#include "../include/mySimpleComputer.h"
#include "simpleassembler.h"

int
sa_memorySet (int address, int value)
{
  if ((address < 0 || address > 128) || (value < 0 || value > 65535))
    {
      sc_regSet (FLAG_RANGE_OVERFLOW, 1);
      return -1;
    }
  RAM[address] = value;
  return 0;
}
