#include "myBigChars.h"
#include "myTerm.h"
int
bc_bigcharwrite (int fd, int *big, int count)
{
  write (fd, big, sizeof (int) * count * 2);
  return 0;
}
