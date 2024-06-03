#include <myTerm.h>
int
mt_setbgcolor (enum colors color)
{
  char data[80];
  int len = sprintf (data, "\E[4%dm", color);
  write (1, data, len);
  return 0;
}
