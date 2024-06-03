#pragma once
#ifndef MYREADKEY
#define MYREADKEY
#include <mySimpleComputer.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

enum keys
{
  key_0 = 0,
  key_1,
  key_2,
  key_3,
  key_4,
  key_5,
  key_6,
  key_7,
  key_8,
  key_9,
  key_A,
  key_B,
  key_C,
  key_D,
  key_E,
  key_F,
  key_up,
  key_down,
  key_right,
  key_left,
  key_f5,
  key_f6,
  key_l,
  key_s,
  key_r,
  key_tt,
  key_i,
  key_esc,
  key_enter,
  key_other,
  key_plus,
  key_minus,
  key_num,
};

extern struct termios atr;

void keySave ();
void keyLoad ();
void keyF5 ();
void keyF6 ();
void keyRight ();
void keyLeft ();
void keyUp ();
void keyDown ();
void keyEnter ();
void keyI ();
int rk_readkey (enum keys *);
int rk_mytermsave (void);
int rk_mytermrestore (void);
int rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint);
int rk_readvalue (int *value, int timeout);
#endif