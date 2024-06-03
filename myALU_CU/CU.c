#include <mySimpleComputer.h>

int
cu ()
{
  int value = 0;
  sc_memoryGet (comand_counter, &value);
  int command;
  int operand;
  int sign;
  if (sc_commandDecode (value, &sign, &command, &operand))
    {
      sc_regSet (FLAG_IGNORING_CLOCK_PULSES, 0);
      return 1;
    }
  if (operand >= RAM_size || operand < 0)
    {
      sc_regSet (FLAG_RANGE_OVERFLOW, 1);
      sc_regSet (FLAG_IGNORING_CLOCK_PULSES, 1);
      return 1;
    }
  if (command >= 0x1e && command <= 0x21)
    ALU (command, operand);
  else
    {
      switch (command)
        {
        case CPUINFO:
          mt_gotoXY (30, 1);
          write (1, "Дмитриев Антон Александрович, ИП - 213", 69);
          break;
        case READ:
          sc_printTerm (operand, 0);
          break;
        case WRITE:
          sc_printTerm (operand, 1);
          break;
        case LOAD:
          sc_memoryGet (operand, &accumulator);
          break;
        case STORE:
          sc_memorySet (operand, accumulator);
          break;
        case JUMP:
          comand_counter = --operand;
          break;
        case JNEG:
          if (accumulator < 0)
            comand_counter = --operand;
          break;
        case JNS:
          if (accumulator > 0)
            comand_counter = --operand;
          break;
        case JZ:
          if (accumulator == 0)
            comand_counter = --operand;
          break;
        case HALT:
          sc_regSet (FLAG_IGNORING_CLOCK_PULSES, 1);
          break;
        case NOT:
          sc_memorySet (operand, ~accumulator);
          break;
        case JNP:
          if ((accumulator % 2) != 0)
            comand_counter = --operand;
          break;
        case AND:
          accumulator = RAM[operand] & accumulator;
          break;
        case OR:
          accumulator = RAM[operand] | accumulator;
          break;
        }
    }
  if (comand_counter + 1 < RAM_size)
    {
      comand_counter++;
      ActiveCell = comand_counter;
    }
  else
    {
      sc_regSet (FLAG_RANGE_OVERFLOW, 1);
      sc_regSet (FLAG_IGNORING_CLOCK_PULSES, 1);
    }
  sc_printAll ();
  return 0;
}
