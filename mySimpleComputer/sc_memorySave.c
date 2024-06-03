#include "mySimpleComputer.h"

int
sc_memorySave (char *filename)
{
  FILE *memory_file = fopen (filename, "wb");
  if (memory_file == NULL)
    {
      return (-1);
    }
  fwrite (RAM, sizeof (int), RAM_size, memory_file);
  fclose (memory_file);
  return 0;
}
