#include <string.h>
char
getHexChar (char *tetraid)
{
  if (strcmp (tetraid, "0000") == 0)
    {
      return '0';
    }
  else if (strcmp (tetraid, "0001") == 0)
    {
      return '1';
    }
  else if (strcmp (tetraid, "0010") == 0)
    {
      return '2';
    }
  else if (strcmp (tetraid, "0011") == 0)
    {
      return '3';
    }
  else if (strcmp (tetraid, "0100") == 0)
    {
      return '4';
    }
  else if (strcmp (tetraid, "0101") == 0)
    {
      return '5';
    }
  else if (strcmp (tetraid, "0110") == 0)
    {
      return '6';
    }
  else if (strcmp (tetraid, "0111") == 0)
    {
      return '7';
    }
  else if (strcmp (tetraid, "1000") == 0)
    {
      return '8';
    }
  else if (strcmp (tetraid, "1001") == 0)
    {
      return '9';
    }
  else if (strcmp (tetraid, "1010") == 0)
    {
      return 'A';
    }
  else if (strcmp (tetraid, "1011") == 0)
    {
      return 'B';
    }
  else if (strcmp (tetraid, "1100") == 0)
    {
      return 'C';
    }
  else if (strcmp (tetraid, "1101") == 0)
    {
      return 'D';
    }
  else if (strcmp (tetraid, "1110") == 0)
    {
      return 'E';
    }
  else if (strcmp (tetraid, "1111") == 0)
    {
      return 'F';
    }
  return ' ';
}
