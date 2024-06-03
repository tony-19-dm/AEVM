#ifndef IRC
#define IRC
#pragma once

#include <console.h>
#include <mySimpleComputer.h>
#include <signal.h>
#include <stdio.h>
#include <sys/time.h>

void irc (int signal);
void reset_signalhagle (int signal);
void create_timer (double interval);

#endif