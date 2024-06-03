#include "mySimpleComputer.h"
#include <myBigChars.h>

void
sc_printBigCell ()
{
  char str[12];
  int value;
  sc_memoryGet (ActiveCell, &value);
  int sign = value >> 14;
  value = value & ~(1 << 14);
  mt_setfgcolor (LIGHT_GRAY);
  mt_setbgcolor (BLACK);
  sprintf (str, "%c%04x ", (sign == 1) ? '-' : '+', value);
  int y = 65;
  int x = 7;
  if (!sign)
    bc_printbigchar (bcintp, x, y, BLACK, GREEN);
  else
    bc_printbigchar (bcintm, x, y, BLACK, GREEN);
  y = 56;
  x = 7;
  for (int i = 0; i < 6; i++)
    {
      y += 8;
      switch (str[i])
        {
        case '0':
          bc_printbigchar (bcint0, x, y, BLACK, GREEN);
          break;
        case '1':
          bc_printbigchar (bcint1, x, y, BLACK, GREEN);
          break;
        case '2':
          bc_printbigchar (bcint2, x, y, BLACK, GREEN);
          break;
        case '3':
          bc_printbigchar (bcint3, x, y, BLACK, GREEN);
          break;
        case '4':
          bc_printbigchar (bcint4, x, y, BLACK, GREEN);
          break;
        case '5':
          bc_printbigchar (bcint5, x, y, BLACK, GREEN);
          break;
        case '6':
          bc_printbigchar (bcint6, x, y, BLACK, GREEN);
          break;
        case '7':
          bc_printbigchar (bcint7, x, y, BLACK, GREEN);
          break;
        case '8':
          bc_printbigchar (bcint8, x, y, BLACK, GREEN);
          break;
        case '9':
          bc_printbigchar (bcint9, x, y, BLACK, GREEN);
          break;
        case 'a':
          bc_printbigchar (bcintA, x, y, BLACK, GREEN);
          break;
        case 'b':
          bc_printbigchar (bcintB, x, y, BLACK, GREEN);
          break;
        case 'c':
          bc_printbigchar (bcintC, x, y, BLACK, GREEN);
          break;
        case 'd':
          bc_printbigchar (bcintD, x, y, BLACK, GREEN);
          break;
        case 'e':
          bc_printbigchar (bcintE, x, y, BLACK, GREEN);
          break;
        case 'f':
          bc_printbigchar (bcintF, x, y, BLACK, GREEN);
          break;
        }
    }

  mt_gotoXY (16, 66);
  mt_setfgcolor (BLUE);

  char text[80];
  int len = sprintf (text, "Номер редактируемой ячейки: %d  ", ActiveCell + 1);
  write (1, text, len);
  mt_gotoXY (50, 1);
}
