#include "mySimpleComputer.h"

int
sc_icounterSet (int value)
{
  if (value > 32767 || value < -32767)
    {
      return -1;
    }
  comand_counter = value;
  return 0;
}
