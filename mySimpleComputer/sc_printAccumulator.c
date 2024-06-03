#include "mySimpleComputer.h"

void
sc_printAccumulator ()
{
  mt_setdefaultcolor ();
  mt_gotoXY (2, 88);
  write (1, "                   ", 20);
  mt_gotoXY (2, 88);
  int value = accumulator;
  int sign = value >> 14;
  value = value & ~(1 << 14);
  char buff[60];
  int len = sprintf (buff, "sc: %d hex: %c%X\n", accumulator,
                     (sign == 1) ? '-' : '+', accumulator);
  write (1, buff, len);
}
