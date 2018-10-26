// Copyright  : Dennis Buis (2018)
// License    : MIT
// Platform   : Arduino
// Library    : Simple Utility Library
// File       : SimpleBuffer.h
// Purpose    : Simple library for (ring) buffer management
// Repository : https://github.com/DennisB66/Simple-Utility-Library-for-Arduino

#ifndef _SIMPLE_BUFFER_H
#define _SIMPLE_BUFFER_H

#include <Arduino.h>

class SimpleBuffer {
public:
  SimpleBuffer( size_t);                                    // constructor (buffer size in bytes)
 ~SimpleBuffer();                                           // destructor

  size_t available();                                       // return ovailable data items (1 item = 1 byte)
  size_t free();                                            // return free item space (1 item = 1 byte)
  bool   full();                                            // checks if buffer is full
  void   print();                                           // print buffer counters (for debugging)

  void    clr();                                            // reset buffer counters
  uint8_t get();                                            // get first available data item from buffer
  bool    put( uint8_t);                                    // put next data item in buffer

  private:
  uint8_t* _data;                                           // buffer data
  size_t   _size;                                           // buffer size
  size_t   _head;                                           // first available free slot
  size_t   _tail;                                           // first available data item
  bool     _full;                                           // true = buffer full (_head == _tail)
};

#endif
