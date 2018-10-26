// Copyright  : Dennis Buis (2017, 2018)
// License    : MIT
// Platform   : Arduino
// Library    : Simple Utility Library
// File       : SimpleDebug.h
// Purpose    : provide simple macros to provide debug information
// Repository : https://github.com/DennisB66/Simple-Utility-Library-for-Arduino

#ifndef _SIMPLE_DEBUG_H
#define _SIMPLE_DEBUG_H

#include <Arduino.h>

// print error (line)
#define ERROR(L)    Serial.print(F("> ERROR: "));Serial.print(L);

// print value (#variable, value)
#define VALUE(E)    Serial.print(F("   "));Serial.print(#E);\
                    Serial.print(F(" = "));Serial.print( E);Serial.print(';')

// trace file, func, line
#define TRACE       Serial.print(F("> TRACE:"));\
                    Serial.print(F("  file = "));Serial.print(__FILE__);\
                    Serial.print(F("  func = "));Serial.print(__FUNCTION__);\
                    Serial.print(F("  line = "));Serial.print(__LINE__) LF

#endif
