#include <console.h>
#include <mySimpleComputer.h>
#include <myTerm.h>
#include <stdio.h>

void
sc_printFlags ()
{
  int flag = 0;
  char r_P = '_', r_O = '_', r_M = '_', r_T = '_', r_E = '_';

  sc_regGet (FLAG_OVERFLOW, &flag);
  if (flag == 1)
    {
      r_P = 'P';
    }

  sc_regGet (FLAG_DEVISION_BY_ZERO, &flag);
  if (flag == 1)
    {
      r_O = 'O';
      ;
    }

  sc_regGet (FLAG_RANGE_OVERFLOW, &flag);
  if (flag == 1)
    {
      r_M = 'M';
      ;
    }

  sc_regGet (FLAG_INCORRECT_COMMAND, &flag);
  if (flag == 1)
    {
      r_T = 'T';
      ;
    }
  sc_regGet (FLAG_IGNORING_CLOCK_PULSES, &flag);
  if (flag == 1)
    {
      r_E = 'E';
    }

  // mt_gotoXY (1, 69);
  // mt_setfgcolor (RED);
  // printf (" Flags \n");
  mt_setdefaultcolor ();
  mt_gotoXY (2, 70);
  printf ("%c %c %c %c %c\n", r_P, r_O, r_M, r_T, r_E);
  fflush (stdout);
  fflush (stdout);
  mt_gotoXY (50, 1);
}
