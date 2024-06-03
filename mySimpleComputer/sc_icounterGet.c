#include "mySimpleComputer.h"

int
sc_icounterGet (int *value)
{
  if (*value > 32767 || *value < -32767)
    { // 7 бит от 0
      return -1;
    }
  *value = comand_counter;
  return 0;
}
