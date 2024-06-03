#include "mySimpleComputer.h"

void
sc_printCounters ()
{
  mt_setdefaultcolor ();
  mt_gotoXY (5, 67);
  char buf[14];
  int len = sprintf (buf, "T: %03d", comand_counter);
  write (1, buf, len);
  len = sprintf (buf, " IC: +%04X", comand_counter);
  write (1, buf, len);
}
