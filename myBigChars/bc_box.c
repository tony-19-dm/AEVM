#include "myBigChars.h"
#include "myTerm.h"
#include <stddef.h>

int
bc_box (int x1, int y1, int x2, int y2, enum colors box_fg, enum colors box_bg,
        char *header, enum colors header_fg, enum colors header_bg)
{
  mt_setfgcolor (box_fg);
  mt_setbgcolor (box_bg);

  if (x1 < 0 || y1 < 0)
    return -1;

  mt_gotoXY (x1, y1);
  bc_printA (BC_ANGLE_LEFT_UP);
  for (int i = y1 + 1; i < y1 + y2 - 1; i++)
    {
      mt_gotoXY (x1, i);
      bc_printA (BC_LINE_HORIZONTAL);
    }

  bc_printA (BC_ANGLE_RIGHT_UP);

  for (int i = x1 + 1; i < x1 + x2 - 1; i++)
    {
      mt_gotoXY (i, y1);
      bc_printA (BC_LINE_VERTICAL);
    }

  mt_gotoXY (x1 + x2 - 1, y1);
  bc_printA (BC_ANGLE_LEFT_DOWN);

  for (int i = x1 + 1; i < x1 + x2 - 1; i++)
    {
      mt_gotoXY (i, y1 + y2 - 1);
      bc_printA (BC_LINE_VERTICAL);
    }

  for (int i = y1 + 1; i < y1 + y2 - 1; i++)
    {
      mt_gotoXY (x1 + x2 - 1, i);
      bc_printA (BC_LINE_HORIZONTAL);
    }

  bc_printA (BC_ANGLE_RIGHT_DOWN);

  if (header != NULL)
    {
      mt_setfgcolor (header_fg);
      mt_setbgcolor (header_bg);
      mt_gotoXY (x1, y1 + (y2 / 2) - (int)bc_strlen (header) / 2);

      char buff[80];
      int len = sprintf (buff, "%s", header);
      write (1, header, len);
    }

  return 0;
}
