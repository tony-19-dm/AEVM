#include <myTerm.h>

int
mt_clrscr (void)
{
  write (1, "\E[H\E[J", 7);
  return 0;
}
