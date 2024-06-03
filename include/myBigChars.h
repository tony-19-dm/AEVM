#ifndef MYBIGCHARS
#define MYBIGCHARS
#pragma once

#include "myTerm.h"
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define BC_ANGLE_LEFT_UP "l"
#define BC_ANGLE_LEFT_DOWN "m"
#define BC_ANGLE_RIGHT_UP "k"
#define BC_ANGLE_RIGHT_DOWN "j"
#define BC_LINE_VERTICAL "x"
#define BC_LINE_HORIZONTAL "q"

#define EN_MACS "\E(0"
#define EX_MACS "\E(B"
#define BLACK_CHAR 'a'

extern int bcint0[2];
extern int bcint1[2];
extern int bcint2[2];
extern int bcint3[2];
extern int bcint4[2];
extern int bcint5[2];
extern int bcint6[2];
extern int bcint7[2];
extern int bcint8[2];
extern int bcint9[2];
extern int bcintA[2];
extern int bcintB[2];
extern int bcintC[2];
extern int bcintD[2];
extern int bcintE[2];
extern int bcintF[2];
extern int bcintp[2];
extern int bcintm[2];

int bc_printA (char *str);
int bc_box (int x1, int y1, int x2, int y2, enum colors box_fg,
            enum colors box_bg, char *header, enum colors header_fg,
            enum colors header_bg);
int bc_setbigcharpos (int *big, int x, int y, int value);
int bc_getbigcharpos (int *big, int x, int y, int *value);
int bc_printbigchar (int arr[2], int x, int y, enum colors fg, enum colors bg);
int bc_bigcharwrite (int fd, int *big, int count);
int bc_bigcharread (int fd, int *big, int need_count, int *count);
int bc_strlen (const char *str);
#endif
