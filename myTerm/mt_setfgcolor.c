#include <myTerm.h>
int
mt_setfgcolor (enum colors color)
{
  char data[80];
  int len = sprintf (data, "\E[3%dm", color);
  write (1, data, len);
  return 0;
}
