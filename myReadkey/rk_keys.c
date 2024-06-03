#include <mySimpleComputer.h>
#include <stdio.h>

void
keyI ()
{
  mt_setdefaultcolor ();
  sc_memoryInit ();
  sc_memoryInit ();
  sc_regInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();

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

  sc_printAll ();
  sc_regSet (FLAG_INCORRECT_COMMAND, 1);
  fflush (stdout);

  create_timer (0); //
  raise (SIGUSR1);  //
  // break;//
}

void
keySave ()
{
  char filename[64];
  mt_gotoXY (26, 2);
  char buff[20];
  int len = sprintf (buff, "Save file as:      ");
  write (1, buff, len);
  scanf ("%63s", filename);
  sc_memorySave (filename);
  sc_printAll ();
}

void
keyLoad ()
{
  char filename[64];
  mt_gotoXY (26, 2);
  char buff[20];
  int len = sprintf (buff, "Load file:         ");
  write (1, buff, len);
  mt_gotoXY (26, 13);
  scanf ("%63s", filename);
  if (sc_memoryLoad (filename))
    {
      mt_gotoXY (26, 2);
      write (1, "Error loading file ", 20);
    }
  sc_printAll ();
}

void
keyEnter ()
{
  int y = 2;
  int x = 2;
  int value;
  mt_gotoXY (y + (ActiveCell + 1) / 10, x + ((ActiveCell + 1) % 10) * 6 - 6);
  mt_setbgcolor (GREEN);
  mt_setfgcolor (BLACK);
  char buf[7] = "     ";
  write (1, buf, 6);
  mt_gotoXY (y + (ActiveCell + 1) / 10, x + ((ActiveCell + 1) % 10) * 6 - 6);

  if (rk_readvalue (&value, 1000))
    {
      sc_memorySet (ActiveCell, value);
      mt_gotoXY (y + (ActiveCell + 1) / 10,
                 x + ((ActiveCell + 1) % 10) * 6 - 6);
      sc_printCell (ActiveCell, BLACK, GREEN);
      sc_printTerm (ActiveCell, -1);
      sc_printBigCell ();
      sc_printDecodedCommand (value);
      sc_printCache ();
      sc_printCommand ();
    }
  mt_gotoXY (50, 0);
}

void
keyF5 ()
{
  mt_gotoXY (2, 88);
  write (1, "hex:                 ", 22);
  mt_gotoXY (2, 92);
  int value = 0;
  rk_readvalue (&value, 1000);
  sc_accumulatorSet (value);
  sc_printAccumulator ();
}

void
keyF6 ()
{
  int value = 0;
  int flag200 = 0;
  enum keys key;
  mt_gotoXY (5, 67);
  write (1, "T:                 ", 17);
  mt_gotoXY (5, 69);
  while (1)
    {
      rk_readkey (&key);
      if (key >= key_0 && key <= key_2)
        {
          char buf[2];
          value += (key * 100);
          int len = sprintf (buf, "%d", key);
          write (1, buf, len);
          if (key == key_2)
            flag200 = 1;
          break;
        }
    }
  if (flag200)
    {
      while (1)
        {
          rk_readkey (&key);
          if (key >= key_0 && key <= key_5)
            {
              char buf[2];
              value += (key * 10);
              int len = sprintf (buf, "%d", key);
              write (1, buf, len);
              break;
            }
        }
      while (1)
        {
          rk_readkey (&key);
          if (key >= key_0 && key <= key_5)
            {
              char buf[2];
              value += key;
              int len = sprintf (buf, "%d", key);
              write (1, buf, len);
              break;
            }
        }
    }
  else
    {
      while (1)
        {
          rk_readkey (&key);
          if (key >= key_0 && key <= key_9)
            {
              char buf[2];
              value += (key * 10);
              int len = sprintf (buf, "%d", key);
              write (1, buf, len);
              break;
            }
        }
      while (1)
        {
          rk_readkey (&key);
          if (key >= key_0 && key <= key_9)
            {
              char buf[2];
              value += key;
              int len = sprintf (buf, "%d", key);
              write (1, buf, len);
              break;
            }
        }
    }
  sc_icounterSet (value);
  sc_printAll ();
  fflush (stdout);
}

void
keyRight ()
{
  if (ActiveCell == 127)
    ActiveCell = 120;
  else if (ActiveCell % 10 == 9)
    ActiveCell -= 9;
  else
    ActiveCell++;
  sc_printAll ();
}

void
keyLeft ()
{
  if (ActiveCell % 10 == 0)
    if (ActiveCell == 120)
      ActiveCell = 127;
    else
      ActiveCell += 9;
  else
    ActiveCell--;
  sc_printAll ();
}

void
keyUp ()
{
  if (ActiveCell >= 0 && ActiveCell <= 9)
    {
      ActiveCell = 120 + ActiveCell;
      if (ActiveCell >= 128)
        ActiveCell = 127;
    }
  else
    ActiveCell -= 10;
  sc_printAll ();
}

void
keyDown ()
{
  if (ActiveCell < 120)
    {
      ActiveCell += 10;
      if (ActiveCell >= 127)
        ActiveCell = 127;
    }
  else
    ActiveCell = ActiveCell % 10;
  sc_printAll ();
}
