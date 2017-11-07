// Copyright  : Dennis Buis (2017)
// License    : MIT
// Platform   : Arduino
// Library    : Simple Utils Library
// File       : SimplePrint.h
// Purpose    : provide simple macros to replace regular print statements
// Repository : https://github.com/DennisB66/Simple-Utility-Library-for-Arduino

#ifndef _SIMPLE_PRINT_H
#define _SIMPLE_PRINT_H

#include <Arduino.h>

#define LF         ;Serial.println()                        // line feed
#define BEGIN(R)    Serial.begin(R)                         // start serial out (rate)
#define PRINT(L)    Serial.print(L)                         // print (line)
#define QUOTE(L)    Serial.print('\'');Serial.print(L);Serial.print('\'')
                                                            // print quoted (line)
#define LABEL(L,V)  Serial.print(L);Serial.print(V);        // print (label, value)
#define ERROR(L)    Serial.print(F("> ERROR: "));Serial.print(L);
                                                            // print error (line)
#define VALUE(E)    Serial.print(F("   "));Serial.print(#E);\
                    Serial.print(F(" = "));Serial.print( E);Serial.print(';')
                                                            // print value (#value, value)
#define TRACE       Serial.print(F("> TRACE:"));\
                    Serial.print(F("  file = "));Serial.print(__FILE__);\
                    Serial.print(F("  func = "));Serial.print(__FUNCTION__);\
                    Serial.print(F("  line = "));Serial.print(__LINE__) LF
                                                            // trace file, func, line

#define LCD1( L, X, Y, A)       L.setCursor(X,Y);L.print(A) // lcd print at x,y (line)
#define LCD2( L, X, Y, A, B)    L.setCursor(X,Y);L.print(A);L.print(B)
                                                            // lcd print at x,y (line, line)
#define LCD3( L, X, Y, A, B, C) L.setCursor(X,Y);L.print(A);L.print(B);L.print(C)
                                                            // lcd print at x,y (line, line, line)
#endif
