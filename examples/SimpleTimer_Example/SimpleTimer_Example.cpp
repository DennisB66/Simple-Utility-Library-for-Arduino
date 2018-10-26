// Copyright  : Dennis Buis (2017, 2018)
// License    : MIT
// Platform   : Arduino
// Library    : Simple Utility Library
// File       : SimpleTimer_Example.cpp
// Purpose    : Example
// Repository : https://github.com/DennisB66/Simple-Utils-Library-for-Arduino

#include <Arduino.h>
#include "SimpleTimer.h"
#include "SimplePrint.h"

void handleTimer1();
void handleTimer2();

void setup()
{
  BEGIN( 115200) LF;                                        // start serial console at 115200 baudrate

  PRINT( F( "# -------------------------")) LF;             // print header on console (LF = new line)
  PRINT( F( "# -  SimpleTimer Example  -")) LF;
  PRINT( F( "# -  V0.3    (DennisB66)  -")) LF;
  PRINT( F( "# -------------------------")) LF;
  PRINT( F( "#")) LF;

  PRINT( F( "# ready")) LF;
  PRINT( F( "#")) LF;
}

void loop()
{
  SetTimer( timer1,  300, handleTimer1);                    // create 1st timer with callback on  300 msec lapse
  SetTimer( timer2, 1000, handleTimer2);                    // create 2nd timer with callback on 1000 msec lapse

  // SetTimer( timer1,  300, handleTimer1) equals: static SimpleTimer timer1(  300, handleTimer1); timer1.check();
  // SetTimer( timer2, 1000, handleTimer1) equals: static SimpleTimer timer2( 1000, handleTimer2); timer2.check();

  yield();                                                  // provide time for system functions
}

// callback function for timer 1
void handleTimer1()
{
  PRINT( F( "> timer 1 lapse time passed")) LF;
}

// callback function for timer 2
void handleTimer2()
{
  PRINT( F( "> timer 2 lapse time passed (also)")) LF;
}
