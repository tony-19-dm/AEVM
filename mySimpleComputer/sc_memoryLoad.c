#include "mySimpleComputer.h"

int
sc_memoryLoad (char *filename)
{
  FILE *memory_file = fopen (filename, "rb");

  if (memory_file == NULL)
    {
      return (-1);
    }
  fread (RAM, sizeof (int), 128, memory_file);
  fclose (memory_file);
  return 0;
}
