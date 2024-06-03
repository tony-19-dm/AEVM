#include <helpers.h>
#include <mySimpleComputer.h>

int
sc_commandEncode (int sign, int command, int operand, int *value)
{

  if (value == 0 || (operand & (~0x7F)) > 0 || (command & (~0x7F)) > 0
      || (sign & (~0x1)) > 0)
    {
      return -1;
    }
  if (sc_commandValidate (command) == 1)
    {
      return -1;
    }
  *value = 0;
  *value = *value | (sign << 14);
  *value = *value | (command << 7);
  *value = *value | (operand);
  return 0;
}
