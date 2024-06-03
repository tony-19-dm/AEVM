#include <mySimpleComputer.h>

int RAM[128];
int flag;
int accumulator;
int comand_counter;
char IObuffer[5][13] = { " ", " ", " ", " ", " " };
int ActiveCell = 0;
CacheLine *cache;
int updateStatic;