// Copyright  : Dennis Buis (2017, 2018)
// License    : MIT
// Platform   : Arduino
// Library    : Simple Utility Library
// File       : SimplePrint_Example.cpp
// Purpose    : Example
// Repository : https://github.com/DennisB66/Simple-Utils-Library-for-Arduino

#include <Arduino.h>
#include "SimpleUtils.h"
#include "SimplePrint.h"

void setup()
{
  BEGIN( 115200) LF;                                        // start serial console at 115200 baudrate

  PRINT( F( "# -------------------------")) LF;             // print header on console (LF = new line)
  PRINT( F( "# -  SimplePrint Example  -")) LF;
  PRINT( F( "# -  V0.3    (DennisB66)  -")) LF;
  PRINT( F( "# -------------------------")) LF;
  PRINT( F( "#")) LF;
  PRINT( F( "# waiting for key press(es)")) LF;
}

void loop()
{
  if ( Serial.available() > 0) {                            // check incoming data from console
    char c = Serial.read();                                 // fetch incoming data from console

    LABEL( "> key pressed = '", c);                         // print input as character on console
    LABEL( "' / "             , dec( c, 3));                // print input as dec value on console
    LABEL( " / 0x"            , hex( c, 2)) LF;             // print input as hex value on console
  }
}
