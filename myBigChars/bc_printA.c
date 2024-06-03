#include "myBigChars.h"
#include "myTerm.h"

int
bc_printA (char *str)
{
  // printf (EN_MACS);
  char buff[10];
  int len = sprintf (buff, EN_MACS);
  write (1, buff, len);

  len = sprintf (buff, "%s", str);
  write (1, buff, len);

  len = sprintf (buff, EX_MACS);
  write (1, buff, len);
  return 0;
}
