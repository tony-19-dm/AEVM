#include <console.h>
#include <mySimpleComputer.h>

int
sc_consoleInit ()
{
  struct winsize ws;
  ioctl (1, TIOCGWINSZ, &ws);
  // printf ("%d, %d\n\n", ws.ws_row, ws.ws_col);
  if (ws.ws_row > 25 && ws.ws_col >= 109)
    return 1;
  else
    return 0;
}
