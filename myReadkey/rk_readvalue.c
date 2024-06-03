#include <myReadkey.h>
#include <mySimpleComputer.h>
#include <stdio.h>
#include <time.h>

int
rk_readvalue (int *value, int timeout)
{
  *value = 0;
  int plus = 0;
  enum keys key;
  while (1)
    {
      rk_readkey (&key);
      if (key == key_plus)
        {
          *value = *value | (0 << 14);
          write (1, "+", 1);
          break;
        }
      if (key == key_minus)
        {
          *value = *value | (1 << 14);
          write (1, "-", 1);
          break;
        }
      if (key >= key_0 && key <= key_3)
        {
          *value = *value | (0 << 14);
          write (1, "+", 1);
          char buf[2];
          *value = *value | (key * 16 * 16 * 16);
          int len = sprintf (buf, "%d", key);
          write (1, buf, len);
          plus = 1;
          break;
        }
    }
  if (!plus)
    while (1)
      {
        rk_readkey (&key);
        if (key >= key_0 && key <= key_3)
          {
            char buf[2];
            *value = *value | (key * 16 * 16 * 16);
            int len = sprintf (buf, "%d", key);
            write (1, buf, len);
            break;
          }
      }
  while (1)
    {
      rk_readkey (&key);
      if (key >= key_0 && key <= key_F)
        {
          char buf[2];
          *value = *value | (key * 16 * 16);
          if (key >= key_A && key <= key_F)

            {
              int len = sprintf (buf, "%c", 97 + key - 10);
              write (1, buf, len);
              break;
            }
          else
            {
              int len = sprintf (buf, "%d", key);
              write (1, buf, len);
              break;
            }
        }
    }
  while (1)
    {
      rk_readkey (&key);
      if (key >= key_0 && key <= key_F)
        {
          char buf[2];
          *value = *value | (key * 16);
          if (key >= key_A && key <= key_F)

            {
              int len = sprintf (buf, "%c", 97 + key - 10);
              write (1, buf, len);
              break;
            }
          else
            {
              int len = sprintf (buf, "%d", key);
              write (1, buf, len);
              break;
            }
        }
    }
  while (1)
    {
      rk_readkey (&key);
      if (key >= key_0 && key <= key_F)
        {
          char buf[2];
          *value = *value | (key);
          if (key >= key_A && key <= key_F)

            {
              int len = sprintf (buf, "%c", 97 + key - 10);
              write (1, buf, len);
              break;
            }
          else
            {
              int len = sprintf (buf, "%d", key);
              write (1, buf, len);
              break;
            }
        }
    }

  // rk_readkey (&key);
  // }
  return 1;
}
