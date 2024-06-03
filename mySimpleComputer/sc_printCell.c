#include <helpers.h>
#include <mySimpleComputer.h>
#include <myTerm.h>
#include <stdio.h>
void
sc_printCell (int address, enum colors fg, enum colors bg)
{
  int value;
  sc_memoryGet (address, &value);
  int sign = value >> 14;
  value = value & ~(1 << 14);
  mt_setfgcolor (fg);
  mt_setbgcolor (bg);
  char buf[10];
  int len = sprintf (buf, "%c%04X", (sign == 1) ? '-' : '+', value);
  write (1, buf, len);
  mt_setdefaultcolor ();
  write (1, " ", 1);
}
