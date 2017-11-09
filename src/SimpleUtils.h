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

#if   defined(__AVR__)
#define LED_BUILTIN     13                                  // built-in LED on Arduino UNO
#define D0               0
#define D1               1
#define D2               2
#define D3               3
#define D4               4
#define D5               5
#define D6               6
#define D7               7
#define D8               8
#define D9               9
#define D10             10
#define D11             11
#define D12             12
#define D13             13
#elif defined(ESP8266)
#define LED_BUILTIN      2                                  // built-in LED on Arduino UNO
#endif
                                                            // required for Leonardo ETH
#define ETHERNET_RESET(PIN) pinMode(PIN, OUTPUT);\
                            digitalWrite(PIN, HIGH); delay(200);\
                            digitalWrite(PIN, LOW ); delay(200);\
                            digitalWrite(PIN, HIGH); delay(200)

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
