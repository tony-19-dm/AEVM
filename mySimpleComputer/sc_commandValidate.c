#include <mySimpleComputer.h>

int
sc_commandValidate (int command)
{
  if (command != NOP && command != CPUINFO && command != READ
      && command != WRITE && command != LOAD && command != STORE
      && command != ADD && command != SUB && command != DIVIDE
      && command != MUL && command != JUMP && command != JNEG && command != JZ
      && command != HALT && command != NOT && command != AND && command != OR
      && command != XOR && command != JNS && command != JC && command != JNC
      && command != JP && command != JNP && command != CHL && command != SHR
      && command != RCL && command != RCR && command != NEG && command != ADDC
      && command != SUBC && command != LOGLC && command != LOGRC
      && command != RCCL && command != RCCR && command != MOVA
      && command != MOVR && command != MOVCA && command != MOVCR
      && command != ADDC && command != SUBC)
    {
      return 1;
    }
  return 0;
}
