#include <IRC.h>

void
irc (int signum)
{
  int val;
  sc_regGet (FLAG_IGNORING_CLOCK_PULSES, &val);
  if (val == 0)
    {
      cu ();
      // resetTerm ();
      mt_gotoXY (24, 1);
      // printf ("%s", io_msg);
    }
}

void
reset_signalhagle (int signal)
{
  accumulator = 0;
  comand_counter = 0;
  mt_setdefaultcolor ();
  ActiveCell = 0;
  sc_regInit ();
  sc_regSet (FLAG_IGNORING_CLOCK_PULSES, 1);
  sc_memoryInit ();
  // resetTerm ();
}

void
create_timer (double interval)
{
  struct itimerval nval;
  nval.it_value.tv_sec = nval.it_interval.tv_sec = (long)interval;
  nval.it_value.tv_usec = nval.it_interval.tv_usec
      = (long)((interval - (long)interval) * 1000000);
  setitimer (ITIMER_REAL, &nval, NULL);
}