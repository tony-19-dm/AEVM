#include <myTerm.h>
int
mt_setdefaultcolor (void)
{
  write (1, "\E[0m", 5);
  return 0;
}
