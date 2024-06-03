#include <mySimpleComputer.h>

void
sc_resetTerm ()
{
  mt_clrscr ();
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 10; j++)
      IObuffer[i][j] = ' ';
  sc_printAll ();
}
