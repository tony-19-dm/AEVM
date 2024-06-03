#include "mySimpleComputer.h"

int
sc_regSet (int reg, int value)
{
  if (reg == FLAG_OVERFLOW || reg == FLAG_DEVISION_BY_ZERO
      || reg == FLAG_RANGE_OVERFLOW || reg == FLAG_INCORRECT_COMMAND
      || reg == FLAG_IGNORING_CLOCK_PULSES)
    {
      if (value == 0)
        {
          flag = flag & (~(1 << (reg - 1)));
        }
      else if (value == 1)
        {
          flag = flag | (1 << (reg - 1));
        }
      else
        {
          return 0;
        }
    }
  return -1;
}
