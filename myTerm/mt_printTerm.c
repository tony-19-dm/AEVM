#include <mySimpleComputer.h>
#include <myTerm.h>

void
sc_printTerm (int address, int input)
{
  int y = 19, x = 69;
  mt_gotoXY (y, x);
  int len = 0;
  if (input == 1)
    {
      mt_setdefaultcolor ();
      int value;
      sc_memoryGet (address, &value);
      int sign = value >> 14;
      value = value & ~(1 << 14);

      for (int i = 4; i > 0; i--)
        strcpy (IObuffer[i], IObuffer[i - 1]);
      len = sprintf (IObuffer[0], "%03d> %c%04x", address,
                     (sign == 1) ? '-' : '+', value);

      for (int i = 0; i < 5; i++)
        {
          y++;
          mt_gotoXY (y, x);
          write (1, IObuffer[i], len);
        }
    }
  else if (input == 0)
    {
      mt_setdefaultcolor ();
      for (int i = 4; i > 0; i--)
        strcpy (IObuffer[i], IObuffer[i - 1]);
      sprintf (IObuffer[0], "%03d<       ", address);
      mt_gotoXY (y, x);
      for (int i = 0; i < 5; i++)
        {
          y++;
          mt_gotoXY (y, x);
          write (1, IObuffer[i], 13);
        }
      int y = 19, x = 69;
      x += 5;
      y++;
      mt_gotoXY (y, x);
      rk_readvalue (&RAM[address], 1000);

      int value;
      sc_memoryGet (address, &value);
      int sign = value >> 14;
      value = value & ~(1 << 14);
      len = sprintf (IObuffer[0], "%03d< %c%04x", address,
                     (sign == 1) ? '-' : '+', value);
    }
  else if (input == -1)
    {
      mt_setdefaultcolor ();
      int value;
      sc_memoryGet (address, &value);
      int sign = value >> 14;
      value = value & ~(1 << 14);

      for (int i = 4; i > 0; i--)
        strcpy (IObuffer[i], IObuffer[i - 1]);
      len = sprintf (IObuffer[0], "%03d< %c%04x", address,
                     (sign == 1) ? '-' : '+', value);

      for (int i = 0; i < 5; i++)
        {
          y++;
          mt_gotoXY (y, x);
          write (1, IObuffer[i], len);
        }
    }
  mt_gotoXY (50, 0);
}
