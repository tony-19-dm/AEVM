#include "../include/mySimpleComputer.h"
#include "simplebasic.h"

int
sa_memorySet (int address, int value)
{
  if ((address < 0 || address > 128) || (value < 0 || value > 65535))
    {
      sc_regSet (FLAG_RANGE_OVERFLOW, 1);
      printf ("OUT_OF_MEMORY_BOUNDS, address: %x\n", address);
      return -1;
    }
  RAM[address] = value;
  return 0;
}