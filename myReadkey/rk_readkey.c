#include <console.h>
#include <mySimpleComputer.h>
#include <stdio.h>

int
rk_readkey (enum keys *key)
{
  rk_mytermregime (1, 0, 1, 1, 0);
  char buff[8] = { 0 };
  read (STDIN_FILENO, buff, 8);
  if (strcmp (buff, "\E[A") == 0)
    {
      *key = key_up;
    }
  else if (strcmp (buff, "\E[B") == 0)
    {
      *key = key_down;
    }
  else if (strcmp (buff, "\E[C") == 0)
    {
      *key = key_right;
    }
  else if (strcmp (buff, "\E[D") == 0)
    {
      *key = key_left;
    }
  else if (strcmp (buff, "\n") == 0)
    {
      *key = key_enter;
    }
  else if (strcmp (buff, "\E[15~") == 0)
    {
      *key = key_f5;
    }
  else if (strcmp (buff, "\E[17~") == 0)
    {
      *key = key_f6;
    }
  else if (buff[0] == 'l')
    {
      *key = key_l;
    }
  else if (buff[0] == 's')
    {
      *key = key_s;
    }
  else if (buff[0] == 'r')
    {
      *key = key_r;
    }
  else if (buff[0] == 't')
    {
      *key = key_tt;
    }
  else if (buff[0] == 'i')
    {
      *key = key_i;
    }
  else if (buff[0] >= '0' && buff[0] <= '9')
    {
      *key = buff[0] - 48;
    }
  else if (buff[0] >= 'a' && buff[0] <= 'f')
    {
      *key = buff[0] - 87;
    }
  else if (buff[0] == '\033')
    {
      *key = key_esc;
    }
  else if (buff[0] == '+')
    {
      *key = key_plus;
    }
  else if (buff[0] == '-')
    {
      *key = key_minus;
    }
  else
    {
      *key = key_other;
    }
  rk_mytermrestore ();
  return 0;
}
