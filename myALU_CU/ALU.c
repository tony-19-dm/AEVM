#include <mySimpleComputer.h>

int
ALU (int command, int operand)
{
  sc_regSet (1, 1);
  int value = 0;
  int sign_mask = 1 << 14;
  sc_memoryGet (operand, &value);
  int signA = (accumulator >> 14) & 1;
  int signV = (value >> 14) & 1;
  switch (command)
    {
    case ADD:
      if (accumulator + value > 0x3FFF)
        {
          int mask = 1 << 15;
          accumulator ^= mask;
          sc_regSet (FLAG_OVERFLOW, 1);
          break;
        }

      accumulator += value;
      break;
    case SUB:
      if (accumulator - value < -0x3FFF)
        {
          accumulator ^= sign_mask;
          sc_regSet (FLAG_OVERFLOW, 1);
          break;
        }
      accumulator -= value;
      break;
    case DIVIDE:
      if (value == 0)
        {
          sc_regSet (FLAG_DEVISION_BY_ZERO, 1);
          break;
        }
      signA = (accumulator >> 14) & 1;
      signV = (value >> 14) & 1;
      accumulator /= value;

      if ((signA == 1 && signA == signV) || signA != signV)
        accumulator ^= sign_mask;
      break;
    case MUL:
      if (accumulator * value > 0x3FFF)
        {
          sc_regSet (FLAG_OVERFLOW, 1);
          break;
        }
      signA = (accumulator >> 14) & 1;
      signV = (value >> 14) & 1;

      accumulator *= value;
      if ((signA == 1 && signA == signV) || signA != signV)
        accumulator ^= sign_mask;
      break;
    default:
      sc_regSet (FLAG_INCORRECT_COMMAND, 1);
      break;
    }
  return 0;
}