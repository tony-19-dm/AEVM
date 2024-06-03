#include "mySimpleComputer.h"

void
sc_printDecodedCommand (int value)
{
  mt_gotoXY (17, 3);
  mt_setdefaultcolor ();
  write (1, "                                                           ", 60);
  mt_gotoXY (17, 3);

  char buf[70];
  int sign = value >> 14;
  value = value & ~(1 << 14);
  int len;
  if (sign)
    {
      len = sprintf (buf, "dec: -%d oct: -%o hex: -%04X bin: ", value, value,
                     value);
      write (1, buf, len);
    }
  else
    {
      len = sprintf (buf, "dec: %d oct: %o hex: %04X bin: ", value, value,
                     value);
      write (1, buf, len);
    }
  if (sign)
    write (1, "1", 1);
  else
    write (1, "0", 1);

  for (int i = 13; i >= 0; i--)
    {
      len = sprintf (buf, "%d", (value & (1 << i)) ? 1 : 0);
      write (1, buf, len);
    }
  if (value == 0)
    {
      write (1, "          ", 10);
    }
}
