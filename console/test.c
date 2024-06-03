#include <console.h>
#include <mySimpleComputer.h>

int
main ()
{
  enum keys key;
  if (!sc_consoleInit ())
    {
      char buf[30];
      int len = sprintf (buf, "ERROR: window is too small!\n");
      write (1, buf, len);
      return 0;
    }
  sc_regInit ();
  sc_memoryInit ();
  sc_icounterInit ();
  sc_accumulatorInit ();
  sc_initCache ();
  mt_clrscr ();
  bc_box (1, 86, 3, 24, LIGHT_GRAY, BLACK, " Аккумулятор ", RED, BLACK);
  bc_box (1, 1, 15, 62, LIGHT_GRAY, BLACK, " Память ", RED, BLACK);
  bc_box (4, 86, 3, 24, LIGHT_GRAY, BLACK, " Команда ", RED, BLACK);
  bc_box (4, 63, 3, 23, LIGHT_GRAY, BLACK, " Счетчик ", RED, BLACK);
  bc_box (1, 63, 3, 23, LIGHT_GRAY, BLACK, " Флаги ", RED, BLACK);
  bc_box (19, 68, 7, 13, LIGHT_GRAY, BLACK, " IN-OUT ", GREEN, LIGHT_GRAY);
  bc_box (16, 1, 3, 62, LIGHT_GRAY, BLACK, " Редактируемая ячейка (формат) ",
          RED, BLACK);
  bc_box (7, 63, 12, 47, LIGHT_GRAY, BLACK,
          " Редактируемая ячейка (увеличено) ", RED, BLACK);
  bc_box (19, 81, 7, 29, LIGHT_GRAY, BLACK, " Управление ", GREEN, LIGHT_GRAY);
  bc_box (19, 1, 7, 67, LIGHT_GRAY, BLACK, " Кэш процессора ", RED, BLACK);

  mt_setdefaultcolor ();
  mt_gotoXY (20, 82);
  write (1, "l - load s - save i - reset", 28);
  mt_gotoXY (21, 82);
  write (1, "r - run t - step", 17);
  mt_gotoXY (22, 82);
  write (1, "ESC - exit", 11);
  mt_gotoXY (23, 82);
  write (1, "F5 - accumulator", 17);
  mt_gotoXY (24, 82);
  write (1, "F6 - counter", 13);

  signal (SIGUSR1, reset_signalhagle);
  signal (SIGALRM, irc);

  sc_regSet (FLAG_IGNORING_CLOCK_PULSES, 1);

  sc_printAll ();
  while (1)
    {
      rk_readkey (&key);
      int val;
      if (key == key_i)
        {
          create_timer (0);
          raise (SIGUSR1);
        }
      if (key == key_tt)
        sc_regSet (FLAG_IGNORING_CLOCK_PULSES, 1);
      if (key == key_esc)
        break;
      else if (!sc_regGet (FLAG_IGNORING_CLOCK_PULSES, &val) && val)
        switch (key)
          {
          case key_enter:
            keyEnter ();
            break;
          case key_l:
            keyLoad ();
            break;
          case key_s:
            keySave ();
            break;
          case key_r:
            sc_regSet (FLAG_IGNORING_CLOCK_PULSES, 0);
            comand_counter = 0;
            ActiveCell = 0;
            create_timer (0.1);
            break;
          case key_tt:
            cu ();
            break;
          case key_i:
            keyI ();
            break;
          case key_f5:
            keyF5 ();
            break;
          case key_f6:
            keyF6 ();
            break;
          case key_up:
            keyUp ();
            break;
          case key_down:
            keyDown ();
            break;
          case key_right:
            keyRight ();
            break;
          case key_left:
            keyLeft ();
            break;
          default:
            break;
          }
    }
  rk_mytermregime (1, 0, 1, 0, 0);
  return 0;
}
