#include <helpers.h>
#include <mySimpleComputer.h>

int
sc_commandDecode (int value, int *sign, int *command, int *operand)
{
  if ((value & (~0x7FFF)) > 0)
    {
      return -1;
    }
  if (sign == 0 || command == 0 || operand == 0)
    {
      return -1;
    }
  *sign = (value >> 14) & 1; // Сдвигаем на 15 бит вправо и получаем 15ый бит
  *command = (value >> 7)
             & 0x7F; // Сдвигаем на 8 бит вправо и маскируем следующие 7 бит
  *operand = value & 0x7F; // Маскируем первые 7 бит
  return 0;
}
