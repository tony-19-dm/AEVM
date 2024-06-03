#include <myTerm.h>
int
mt_gotoXY (int y, int x)
{
  char data[80];
  int len = sprintf (data, "\E[%d;%dH", y, x);
  write (1, data, len);
  return 0;
}
