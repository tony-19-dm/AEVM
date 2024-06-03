#include <myReadkey.h>
int
rk_mytermrestore (void)
{
  if (tcsetattr (STDIN_FILENO, TCSAFLUSH, &atr) != 0)
    return -1;
  return 0;
}
