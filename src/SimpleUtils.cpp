// Copyright  : Dennis Buis (2017, 2018)
// License    : MIT
// Platform   : Arduino
// Library    : Simple Utility Library
// File       : SimpleUtils.h
// Purpose    : various supporting functions & macros
// Repository : https://github.com/DennisB66/Simple-Utility-Library-for-Arduino

#include "SimpleUtils.h"

// add char to end of string
void addChr( char* s, const char c, size_t l)                     // add character to end of string
{
  size_t i = strlen( s);

  if ( i + 1 < l) {
    s[i    ] = c;
    s[i + 1] = 0;
  }
}

//
void strCpy( char* d, const char* s, size_t l)
{
  l = min( strlen( s), l);

  strncpy( d, s, l); d[l] = 0;
}

//
void strCat( char* d, const char* s, size_t l)
{
  l = min( strlen( s), l - strlen( d));

  strncat( d, s, l);
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

static char _tempBuffer[12];                                // char buffer

const char* dec( unsigned long l)
{
  char fmt[] = "%lu";                                      // decode template

  sprintf( _tempBuffer, fmt , l);

  return _tempBuffer;
}

const char* dec( unsigned long l, uint8_t n)
{
  char fmt[] = "%06lu"; fmt[2] = (char) ( 48 + n);          // decode template

  sprintf( _tempBuffer, fmt , l);

  return _tempBuffer;
}

const char* hex( unsigned long l, uint8_t n)
{
  char fmt[] = "%08lX"; fmt[2] = (char) ( 48 + n);          // decode template

  sprintf( _tempBuffer, fmt , l);

  return _tempBuffer;
}
