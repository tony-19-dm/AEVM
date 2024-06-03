#include "myBigChars.h"
#include "myTerm.h"
int
bc_printbigchar (int arr[2], int x, int y, enum colors b_col,
                 enum colors f_col)
{
  char str[8] = { 0 };
  mt_setfgcolor (f_col);
  mt_setbgcolor (b_col);
  for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < 4; j++)
        {
          int a_buf = arr[i] >> (j * 8);
          int buf = a_buf & 255;
          for (int k = 0; k < 8; k++)
            {
              int buf_bit = (buf & (1 << k));
              if (buf_bit != 0)
                {
                  str[k] = BLACK_CHAR;
                }
              else
                {
                  str[k] = ' ';
                }
            }
          mt_gotoXY (x + (i * 4) + j + 1, y);
          bc_printA (str);
        }
    }
  mt_setdefaultcolor ();
  mt_gotoXY (24, 0);
  return 0;
}
