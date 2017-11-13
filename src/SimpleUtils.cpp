// Copyright  : Dennis Buis (2017)
// License    : MIT
// Platform   : Arduino
// Library    : Simple Utility Library
// File       : SimpleUtils.h
// Purpose    : various supporting functions & macros
// Repository : https://github.com/DennisB66/Simple-Utility-Library-for-Arduino

#include "SimpleUtils.h"

// create stopwatch (msec, function)
Stopwatch::Stopwatch( unsigned long l, StopwatchFunc f)
{
  _func = f;
  lapse( l);
}

// set lapse (msec), reset stopwatch
void Stopwatch::lapse( unsigned long l)
{
  _lapse = l; reset();
}

// reset stopwatch
void Stopwatch::reset()
{
  _ticks = millis() + _lapse;
}

// return true = lapse time passed, callback called, stopwatch reset
bool Stopwatch::check( bool r)
{
  if ( millis() > _ticks) {
    if ( _func) ( *_func)();

    reset();

    return true;
  }

  if ( r) reset();

  return false;
}

// move string between chars (C1, C2) to start of string
const char* shiftL( char* s, char a, char b)
{
  char* ptr_s = strchr ( s    , a);                         // pointer to first occurence of char a
  char* ptr_e = strrchr( ptr_s, b ? b : a);                 // pointer to last  occurence of char b

  if ( ptr_s == NULL) return s;                             // check on char a found
  if ( ptr_e == NULL) return s;                             // check on char b found

  *ptr_e = 0;                                               // set terminator at char b

  for ( int i = 0; i < ptr_e - ptr_s; i++) {                // move chars between char a and char b
    s[i] = ptr_s[i + 1];                                    // i + 1 => copy after char a, include terminator at char b
  }

  return s;                                                 // return result
}

// fill string with spaces until length L (true = centered)
const char* fill( const char* s, int w, bool c)             // width = desired # chars
{
  static char* line = NULL;                                 // buffer
  int          size = min((int) strlen( s), w);             // check valid size
  int          padd = 0;                                    // no extra spaces at start

  if ( c) {                                                 // if centered
    padd = min(( w - size) / 2, w);                         // calc extra spaces at start
  }

  if ( line) {                                              // reallocate (if needed)
    line = (char*) realloc( line, ( w + 1) * sizeof( char));
  } else {                                                  // allocate widt + 1 chars
    line = (char*)  malloc(       ( w + 1) * sizeof( char));
  }

  if ( w) {                                                 // if width is provided
    memset ( line       , 32, w);                           // fill buffer with spaces
    memset ( line + w   ,  0, 1);                           // terminate buffer
    strncpy( line + padd,  s, size);                        // copy source to buffer (centered if needed)
    return   line;                                          // return buffer
  } else {
    return   s;                                             // return source
  }
}

const char* dec( unsigned long l, byte n)
{
  static char buf[12];                                     // char buffer
         char fmt[] = "%06lu";                              // decode template

  fmt[2] = (char) ( 48 + n);
  sprintf( buf, fmt , l);

  return buf;
}

const char* hex( unsigned long l, byte n)
{
  static char buf[12];                                     // char buffer
         char fmt[] = "%08lX";                              // decode template

  fmt[2] = (char) ( 48 + n);
  sprintf( buf, fmt , l);

  return buf;
}
