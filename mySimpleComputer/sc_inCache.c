#include <mySimpleComputer.h>

int
sc_inCache (int address)
{
  int cache_address = address / 10 * 10;
  for (int i = 0; i < 5; i++)
    if (cache_address == cache[i].address)
      return 1;
  return 0;
}