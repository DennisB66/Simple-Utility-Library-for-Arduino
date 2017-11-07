// Copyright  : Dennis Buis (2017)
// License    : MIT
// Platform   : Arduino
// Library    : Simple Utility Library
// File       : Simple-Stopwatch.cpp
// Purpose    : Example
// Repository : https://github.com/DennisB66/Simple-Utils-Library-for-Arduino

#include <Arduino.h>
#include "SimpleUtils.h"

void handleStopwatch1();
void handleStopwatch2();

void setup()
{
  BEGIN( 9600);

  PRINT( F( "# -------------")) LF;                // show header on server console
  PRINT( F( "# - Stopwatch -")) LF;
  PRINT( F( "# -------------")) LF;

  PRINT( F( "# ready")) LF;
}

void loop()
{
  static Stopwatch sw1(  300, handleStopwatch1);
  static Stopwatch sw2( 1000, handleStopwatch2);

  sw1.check();
  sw2.check();

  yield();
}

void handleStopwatch1()
{
  PRINT( F( "> stopwatch 1 lapse time passed")) LF;
}

void handleStopwatch2()
{
  PRINT( F( "> stopwatch 2 lapse time passed (also)")) LF;
}
