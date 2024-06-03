#include <string.h>
char
getOctChar (char *triad)
{
  if (strcmp (triad, "000") == 0)
    {
      return '0';
    }
  else if (strcmp (triad, "001") == 0)
    {
      return '1';
    }
  else if (strcmp (triad, "010") == 0)
    {
      return '2';
    }
  else if (strcmp (triad, "011") == 0)
    {
      return '3';
    }
  else if (strcmp (triad, "100") == 0)
    {
      return '4';
    }
  else if (strcmp (triad, "101") == 0)
    {
      return '5';
    }
  else if (strcmp (triad, "110") == 0)
    {
      return '6';
    }
  else if (strcmp (triad, "111") == 0)
    {
      return '7';
    }
  return ' ';
}
