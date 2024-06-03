#ifndef MYTERM
#define MYTERM
#pragma once

#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

enum colors
{
  BLACK = 0,
  RED = 1,
  GREEN = 2,
  BROWN = 3,
  BLUE = 4,
  PURPLE = 5,
  CYAN = 6,
  LIGHT_GRAY = 7,
};

int mt_clrscr (void);
int mt_gotoXY (int y, int x);
int mt_getscreensize (int *rows, int *cols);
int mt_setfgcolor (enum colors color);
int mt_setbgcolor (enum colors color);
int mt_setdefaultcolor (void);
int mt_setcursorevisible (int value);
int mt_delline (void);
void sc_printTerm (int address, int input);
#endif
