#ifndef _CONSOLE_
#define _CONSOLE_

#define BOX_ROW_MEMORY 12
#define BOX_COLUMN_MEMORY 61
#define MINI_BOX_ROW 3
#define MINI_BOX_COLUMN 22

void printCell (int address);
void printFlags ();
void printDecodedCommand (int value);
void printAccumulator ();
void printCounters ();
int sc_consoleInit ();
#endif
