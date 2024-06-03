#include <myTerm.h>

int
mt_setcursorevisible (int value)
{
  if (value == 1)
    {
      // делает курсор видимым
      write (1, "\E[?25h\E[?8c", 12);
    }
  else if (value == 0)
    {
      write (1, "\E[?25l\E[?1c", 12);
    }
  return 0;
}
