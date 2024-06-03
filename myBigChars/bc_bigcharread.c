#include "myBigChars.h"
#include "myTerm.h"
int
bc_bigcharread (int fd, int *big, int need_count, int *count)
{
  *count = read (fd, big, sizeof (int) * need_count * 2);
  if (*count / sizeof (int) != need_count * 2)
    return -1;

  return 0;
}
