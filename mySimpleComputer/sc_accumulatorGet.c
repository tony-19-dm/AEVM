#include <mySimpleComputer.h>

int
sc_accumulatorGet (int *value)
{ // 15 бит
  if (accumulator > 32767 || accumulator < -32767)
    {
      return -1;
    }
  *value = accumulator;
  return 0;
}
