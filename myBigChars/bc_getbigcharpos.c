#include "myBigChars.h"
#include "myTerm.h"

int
bc_getbigcharpos (int *big, int x, int y, int *value)
{
  if (x < 0 || x > 7 || y < 0 || y > 7)
    return -1;

  int ind = 0;
  if (x > 3)
    ind = 1;

  *value = ((big[ind] >> (x * 8)) >> y) & 1;

  return 0;
}
