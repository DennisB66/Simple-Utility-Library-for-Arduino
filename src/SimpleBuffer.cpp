// Copyright  : Dennis Buis (2018)
// License    : MIT
// Platform   : Arduino
// Library    : Simple Buffer Library
// File       : SimpleBuffer.cpp
// Purpose    : Simple library for (ring) buffer management
// Repository : https://github.com/DennisB66/Simple-Utility-Library-for-Arduino

#include <Arduino.h>
#include "SimpleBuffer.h"
#include "SimplePrint.h"

// constructor (buffer size in bytes)
SimpleBuffer::SimpleBuffer( size_t size)
{
  _data = new uint8_t[ _size = size];                       // create data buffer object
  clr();                                                    // reset counters (= empty buffer)
}

// destructor
SimpleBuffer::~SimpleBuffer()
{
  delete[] _data;                                           // free data buffer object
}

// return ovailable data items (1 item = 1 byte)
size_t SimpleBuffer::available()
{
  return _full ? _size : (( _size + _head - _tail) % _size);
}

// return free item space (1 item = 1 byte)
size_t SimpleBuffer::free()
{
  return _size - available();                               // free space = total space - occupied space
}

// checks if buffer is full
bool SimpleBuffer::full()
{
  return _full;                                             // true = buffer full
}

// print buffer counters (for debugging)
void SimpleBuffer::print()
{
  LABEL( "Size =", _size) LF;
  LABEL( "Head =", _head) LF;
  LABEL( "Tail =", _tail) LF;
  LABEL( "Full =", _full) LF;
  LABEL( "Available =", available()) LF; LF;
}

// reset buffer counters
void SimpleBuffer::clr()
{
  _head = 0;                                                // first available free slot
  _tail = 0;                                                // first available data item
  _full = false;                                            // true = buffer full (_head == _tail)
}

// get first available data item from buffer
uint8_t SimpleBuffer::get()
{
  if ( available()) {                                       // if available data items
     uint8_t b = _data[_tail++];                            // get first available item / increase counter
     _tail %= _size;                                        // apply ring buffer counter (wrap to 0)
     _full  = false;                                        // indicate buffer is not full (anymore)

     return b;                                              // return item
  } else {
     return 0;                                              // return default value (=0)
  }
}

// put next data item in buffer
bool SimpleBuffer::put( uint8_t b)
{
  if ( free()) {                                            // if free space
     _data[_head++] = b;                                    // add item / increase counter
     _head %= _size;                                        // apply ring buffer counter (wrap to 0)
     _full  = ( _head == _tail);

    return true;                                            // success = item added
  } else {
    return false;                                           // failure = item not added (no space)
  }
}
