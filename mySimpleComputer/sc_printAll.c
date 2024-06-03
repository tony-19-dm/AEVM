#include <mySimpleComputer.h>

int
sc_printAll ()
{
  sc_printCache ();
  sc_printMemory ();
  sc_printAccumulator ();
  sc_printCommand ();
  mt_setdefaultcolor ();
  sc_printCounters ();
  sc_printFlags ();
  int value;
  sc_memoryGet (ActiveCell, &value);
  sc_printDecodedCommand (value);
  sc_printBigCell ();
  mt_setdefaultcolor ();
  mt_gotoXY (50, 0);
  return 0;
}
