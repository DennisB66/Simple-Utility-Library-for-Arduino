// Copyright  : Dennis Buis (2018)
// License    : MIT
// Platform   : Arduino
// Library    : Simple Utility Library
// File       : SimpleUtils.h
// Purpose    : various supporting functions & macros
// Repository : https://github.com/DennisB66/Simple-Utility-Library-for-Arduino

#include "SimpleTimer.h"

// create stopwatch (msec, function)
SimpleTimer::SimpleTimer( unsigned long l, SimpleTimerFunc f)
{
  _func = f;
  lapse( l);
}

// set lapse (msec), reset stopwatch
void SimpleTimer::lapse( unsigned long l)
{
  _lapse = l; reset();
}

// reset stopwatch
void SimpleTimer::reset()
{
  _ticks = millis() + _lapse;
}

// return true = lapse time passed, callback called, stopwatch reset
bool SimpleTimer::check( bool r)
{
  if ( millis() > _ticks) {
    if ( _func) ( *_func)();

    reset();

    return true;
  }

  if ( r) reset();

  return false;
}
