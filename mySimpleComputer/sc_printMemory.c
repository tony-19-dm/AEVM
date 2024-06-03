#include <mySimpleComputer.h>
#include <myTerm.h>
#include <unistd.h>

void
sc_printMemory ()
{
  int x = 2;
  mt_gotoXY (x, 2);
  for (int i = 0; i < RAM_size; i++)
    {
      if (i == ActiveCell)
        {
          sc_printCell (i, BLACK, RED);
        }
      else
        {
          sc_printCell (i, LIGHT_GRAY, BLACK);
        }
      if ((i + 1) % 10 == 0 && i != 0)
        {
          x++;
          mt_gotoXY (x, 2);
        }
    }
}
