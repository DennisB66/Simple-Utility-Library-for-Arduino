// Copyright  : Dennis Buis (2017, 2018)
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
#include "SimpleDebug.h"

#if   defined(__AVR__)
//#define LED_BUILTIN     13                                  // built-in LED on Arduino UNO
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
//#define LED_BUILTIN      2                                  // built-in LED on ESP8266
#endif
                                                            // required for Leonardo ETH
#define ETHERNET_RESET(PIN) pinMode(PIN, OUTPUT);\
                            digitalWrite(PIN, HIGH); delay(200);\
                            digitalWrite(PIN, LOW ); delay(200);\
                            digitalWrite(PIN, HIGH); delay(200)

#define minMax(A,B,C)       min(max(A,B),C)                   // return A between boundaries (B, C)
#define strLen(A)           (strlen(A)  !=0)                  // return true = empty string (A)
#define strCmp(A,B)         (strcmp(A,B)==0)                  // return true = equal string (A, B)
#define strClr(D)           D[0]=0                            // clear string (D)

void addChr( char*, const char , size_t);                   // add character to end of string
void strCpy( char*, const char*, size_t);
void strCat( char*, const char*, size_t);

const char* fill( const char*, int, bool = false);          // fill string with spaces until length L (true = centered)

const char* dec( unsigned long);                            // convert to dec string without leading zeros
const char* dec( unsigned long, uint8_t);                   // convert to dec string with leading zeros
const char* hex( unsigned long, uint8_t);                   // convert to hex string with leading zeros

#endif
