#include "mySimpleComputer.h"

void
sc_printCommand ()
{
  mt_gotoXY (5, 87);
  write (1, "                     ", 22);
  mt_setdefaultcolor ();
  int value = 0;
  sc_memoryGet (ActiveCell, &value);
  int command, sign, operand;
  sc_commandDecode (value, &sign, &command, &operand);

  if (sc_commandValidate (command))
    {
      mt_gotoXY (5, 91);
      write (1, "! ", 2);
    }
  char buf[20];
  int len = sprintf (buf, "+%.2X : %.2X\n", command, operand);
  mt_gotoXY (5, 93);
  write (1, buf, len);
}
