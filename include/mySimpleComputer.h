#ifndef MYSIMPLECOMPUTER
#define MYSIMPLECOMPUTER
#pragma once

#include <CU.h>
#include <IRC.h>
#include <helpers.h>
#include <myBigChars.h>
#include <myReadkey.h>
#include <myTerm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RAM_size 128

#define CACHE_SIZE 5
#define CACHE_LINE_SIZE 10

typedef struct
{
  int address;
  int data[CACHE_LINE_SIZE];
  int lastAccessTime;
} CacheLine;

#define FLAG_OVERFLOW 1
#define FLAG_DEVISION_BY_ZERO 2
#define FLAG_RANGE_OVERFLOW 3
#define FLAG_INCORRECT_COMMAND 4
#define FLAG_IGNORING_CLOCK_PULSES 5

#define NOP 0x0
#define CPUINFO 0x1
#define READ 0xA
#define WRITE 0xB
#define LOAD 0x14
#define STORE 0x15
#define ADD 0x1E
#define SUB 0x1F
#define DIVIDE 0x20
#define MUL 0x21
#define JUMP 0x28
#define JNEG 0x29
#define JZ 0x2A
#define HALT 0x2B
#define NOT 0x33
#define AND 0x34
#define OR 0x35
#define XOR 0x36
#define JNS 0x37
#define JC 0x38
#define JNC 0x39
#define JP 0x3A
#define JNP 0x3B
#define CHL 0x3C
#define SHR 0x3D
#define RCL 0x3E
#define RCR 0x3F
#define NEG 0x40
#define ADDC 0x41
#define SUBC 0x42
#define LOGLC 0x43
#define LOGRC 0x44
#define RCCL 0x45
#define RCCR 0x46
#define MOVA 0x47
#define MOVR 0x48
#define MOVCA 0x49
#define MOVCR 0x4A
// #define ADDC 0x4B
// #define SUBC 0x4C

extern int RAM[RAM_size];
extern int flag;
extern int accumulator;
extern int comand_counter;
extern int ActiveCell;
extern char IObuffer[5][13];
extern CacheLine *cache;
extern int updateStatic;

int sc_memoryInit (void);
int sc_memorySet (int address, int value);
int sc_memoryGet (int address, int *value);
int sc_memorySave (char *filename);
int sc_memoryLoad (char *filename);
int sc_regInit (void);
int sc_regSet (int reg, int value);
int sc_regGet (int reg, int *value);
int sc_accumulatorInit (void);
int sc_accumulatorSet (int value);
int sc_accumulatorGet (int *value);
int sc_icounterInit (void);
int sc_icounterSet (int value);
int sc_icounterGet (int *value);
int sc_commandValidate (int command);
int sc_commandEncode (int sign, int command, int operand, int *value);
int sc_commandDecode (int value, int *sign, int *command, int *operand);
void sc_printDecodedCommand (int value);
int sc_commandValidate (int command);
void sc_printAccumulator ();
void sc_printCell (int address, enum colors fg, enum colors bg);
void sc_printCounters ();
void sc_printFlags ();
void sc_printMemory ();
void sc_printCommand ();
void sc_printBigCell ();

void sc_initCache ();
int sc_printCache ();
void sc_updateCacheAfterSave (int address, int cacheLine, int *value);
int sc_findLeastRecentlyUsedCacheEntry ();
int sc_inCache (int address);

int sc_printAll ();
void sc_resetTerm ();
#endif
