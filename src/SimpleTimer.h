// Copyright  : Dennis Buis (2018)
// License    : MIT
// Platform   : Arduino
// Library    : Simple Utility Library
// File       : SimpleUtils.h
// Purpose    : various supporting functions & macros
// Repository : https://github.com/DennisB66/Simple-Utility-Library-for-Arduino

#ifndef _SIMPLE_TIMER_H
#define _SIMPLE_TIMER_H

#include <Arduino.h>

#define SetTimer(T,L,F) static SimpleTimer T(L,F); if ( T.check())

typedef void (* SimpleTimerFunc)();                         // callback function for SimpleTimer

class SimpleTimer {
public:
  SimpleTimer( unsigned long = 1000, SimpleTimerFunc f = NULL); // constructor (msec, function)

  void lapse( unsigned long);                               // set lapse (msec), reset timer
  void reset();                                             // reset timer
  bool check( bool = false);                                // return true = lapse passed, callback called, timer reset

private:
  SimpleTimerFunc _func;                                    // callback function
  unsigned long   _lapse;                                   // lapse time (in msec)
  unsigned long   _ticks;                                   // passed time since reset (in msec)
};

#endif
