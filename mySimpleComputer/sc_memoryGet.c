#include "mySimpleComputer.h"

int
sc_memoryGet (int address, int *value)
{
  if (address >= 128 || address < 0)
    return -1;
  *value = RAM[address];
  return 0;
}
