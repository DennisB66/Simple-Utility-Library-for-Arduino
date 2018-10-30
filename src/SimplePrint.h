// Copyright  : Dennis Buis (2017, 2018)
// License    : MIT
// Platform   : Arduino
// Library    : Simple Utility Library
// File       : SimplePrint.h
// Purpose    : provide simple macros to replace regular print statements
// Repository : https://github.com/DennisB66/Simple-Utility-Library-for-Arduino

#ifndef _SIMPLE_PRINT_H
#define _SIMPLE_PRINT_H

#include <Arduino.h>

#define SP         ;Serial.print(' ')                       // space
#define SC         ;Serial.print(':')                       // space
#define LF         ;Serial.println()                        // line feed
#define LFLF       ;Serial.println();Serial.println()       // double line feed
#define BEGIN(R)    Serial.begin(R)                         // start serial out (rate)
#define PRINT(L)    Serial.print(L)                         // print (line)
#define QUOTE(L)    Serial.print('\'');Serial.print(L);Serial.print('\'')
                                                            // print quoted (line)
#define LABEL(L,V)  Serial.print(L);Serial.print(V);        // print (label, value)

#define LCD1( L, X, Y, A)       L.setCursor(X,Y);L.print(A) // lcd print at x,y (line)
#define LCD2( L, X, Y, A, B)    L.setCursor(X,Y);L.print(A);L.print(B)
                                                            // lcd print at x,y (line, line)
#define LCD3( L, X, Y, A, B, C) L.setCursor(X,Y);L.print(A);L.print(B);L.print(C)
                                                            // lcd print at x,y (line, line, line)
#endif
