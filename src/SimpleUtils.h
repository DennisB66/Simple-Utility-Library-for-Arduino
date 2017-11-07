// Copyright  : Dennis Buis (2017)
// License    : MIT
// Platform   : Arduino
// Library    : Simple Utility Library
// File       : SimpleUtils.h
// Purpose    : various supporting functions & macros
// Repository : https://github.com/DennisB66/Simple-Utility-Library-for-Arduino

#ifndef _SIMPLE_UTILS_H
#define _SIMPLE_UTILS_H

#include <Arduino.h>
#include "SimplePrint.h"

#define minMax(A,B,C)     min(max(A,B),C)                   // return A between boundaries (B, C)
#define strLen(A)         (strlen(A)  !=0)                  // return true = empty string (A)
#define strCmp(A,B)       (strcmp(A,B)==0)                  // return true = equal string (A, B)
#define strCpy(D,S,L)     strncpy(D,S,L-1);D[L-1]=0         // copy string S into D, incl. terminator at L
#define strClr(D)         D[0]=0                            // clear string (D)

typedef void (* StopwatchFunc)();                           // callback function for Stopwatch

class Stopwatch {
public:
  Stopwatch ( unsigned long, StopwatchFunc f = NULL);       // create stopwatch (msec, function)

  void lapse( unsigned long);                               // set lapse (msec), reset stopwatch
  void reset();                                             // reset stopwatch
  bool check();                                             // return true = lapse passed, callback called, stopwatch reset

private:
  StopwatchFunc _func;                                      // callback function

  unsigned long _lapse;                                     // lapse time (in msec)
  unsigned long _ticks;                                     // passed time since reset (in msec)
};

const char* shiftL( char*, char, char = 0);                 // move string between chars (C1, C2) to start of string
const char* fill( const char*, int, bool = false);          // fill string with spaces until length L (true = centered)

#endif
