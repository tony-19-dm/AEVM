#include "myBigChars.h"
#include "myTerm.h"

int
bc_setbigcharpos (int *big, int x, int y, int value)
{
  if (x < 0 || y < 0 || x > 7 || y > 7 || value > 1 || value < 0)
    return -1;

  int index = 0;
  if (x > 3)
    index = 1;

  if (value == 1)
    {
      big[index] |= 1 << (x * 8 + y);
    }
  else if (value == 0)
    {
      big[index] &= ~(1 << (x * 8 + y));
    }
  return 0;
}
