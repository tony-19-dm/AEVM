#include <stdio.h>

int
bc_strlen (const char *str)
{
  if (str == NULL)
    return 0;

  int count = 0;
  const unsigned char *ptr = (const unsigned char *)str;

  while (*ptr)
    {
      if ((*ptr & 0x80) == 0)
        { // 0xxxxxxx, 1 byte
          ptr += 1;
        }
      else if ((*ptr & 0xE0) == 0xC0)
        { // 110xxxxx, 2 bytes
          if (*(ptr + 1) == '\0' || (*(ptr + 1) & 0xC0) != 0x80)
            return 0; // Check for invalid sequence
          ptr += 2;
        }
      else if ((*ptr & 0xF0) == 0xE0)
        { // 1110xxxx, 3 bytes
          if (*(ptr + 1) == '\0' || *(ptr + 2) == '\0'
              || (*(ptr + 1) & 0xC0) != 0x80 || (*(ptr + 2) & 0xC0) != 0x80)
            return 0; // Check for invalid sequence
          ptr += 3;
        }
      else if ((*ptr & 0xF8) == 0xF0)
        { // 11110xxx, 4 bytes
          if (*(ptr + 1) == '\0' || *(ptr + 2) == '\0' || *(ptr + 3) == '\0'
              || (*(ptr + 1) & 0xC0) != 0x80 || (*(ptr + 2) & 0xC0) != 0x80
              || (*(ptr + 3) & 0xC0) != 0x80)
            return 0; // Check for invalid sequence
          ptr += 4;
        }
      else
        { // Invalid UTF-8 start byte
          return 0;
        }
      count++;
    }

  return count;
}
