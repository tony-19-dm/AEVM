#include "mySimpleComputer.h"

int
sc_memorySet (int address, int value)
{
  if (address >= 128 || address < 0)
    return -1;

  RAM[address] = value;

  int index;
  int newAddress = address;
  newAddress = newAddress / 10 * 10;
  sc_updateCacheAfterSave (address, newAddress, &index);
  return 0;
}
