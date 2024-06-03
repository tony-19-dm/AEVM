#include <myTerm.h>
int
mt_delline (void)
{
  write (1, "\033[2K", 5);
  return 0;
}
