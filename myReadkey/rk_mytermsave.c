#include <myReadkey.h>
int
rk_mytermsave (void)
{
  if (tcgetattr (STDIN_FILENO, &atr) != 0)
    return -1;
  return 0;
}
