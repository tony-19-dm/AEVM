#include "mySimpleComputer.h"

int
sc_regGet (int returnedRegister, int *value)
{
  if (returnedRegister > 5 || returnedRegister <= 0)
    {
      return -1;
    }
  (*value) = (flag >> (returnedRegister - 1)) & 1;
  return 0;
}
