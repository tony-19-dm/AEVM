#include <console.h>
#include <myBigChars.h>
#include <myReadkey.h>
#include <mySimpleComputer.h>
#include <myTerm.h>
// #include <rk_structs.h>

int
sc_printCache ()
{
  char buf[20];
  int len;
  for (int i = 0; i < CACHE_SIZE; ++i)
    {
      mt_gotoXY (20 + i, 3);

      if (cache[i].address == -1)
        {
          write (1, "-", 2);
        }
      else
        {
          len = sprintf (buf, "%03d:", cache[i].address);
          write (1, buf, len);
          for (int j = 0; j < CACHE_LINE_SIZE; ++j)
            {
              if ((cache[i].data[j] >> 14) & 1)
                {
                  if ((cache[i].data[j] >> 14) & 1)
                    {
                      len = sprintf (buf, " -%04X",
                                     (cache[i].data[j]) & 0x3FFF);
                      write (1, buf, len);
                    }
                  else
                    {
                      len = sprintf (buf, "  %04X", cache[i].data[j] & 0x3FFF);
                      write (1, buf, len);
                    }
                }

              else
                {
                  len = sprintf (buf, " +%04X", cache[i].data[j] & 0x3FFF);
                  write (1, buf, len);
                }
              // printf (" +%04X", cache[i].data[j] & 0x1FFF);
            }
        }
    }
  return 0;
}