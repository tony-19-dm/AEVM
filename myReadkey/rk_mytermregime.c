#include <myReadkey.h>
int
rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint)
{
  struct termios newatr;
  rk_mytermsave ();
  newatr = atr;
  if (regime == 0)
    {
      newatr.c_lflag |= ICANON;
    }
  else if (regime == 1)
    {
      newatr.c_lflag &= (~ICANON);
      if (echo == 0)
        {
          newatr.c_lflag |= ECHO;
        }
      else if (echo == 1)
        {
          newatr.c_lflag &= (~ECHO);
        }
      if (sigint == 0)
        {
          newatr.c_lflag |= ISIG;
        }
      else if (sigint == 1)
        {
          newatr.c_lflag &= (~ISIG);
        }
      newatr.c_cc[VTIME] = vtime;
      newatr.c_cc[VMIN] = vmin;
    }
  tcsetattr (STDIN_FILENO, TCSAFLUSH, &newatr);
  return 0;
}
