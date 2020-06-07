# Simple Utility Library for Arduino and ESP8266
Library for an Arduino or ESP8266 supporting various utility macros and functions

## Functionality

The classes in the library include:
```
SimpleTimer         // constructor + set lapse time + attach callback (optional)
lapse()             // set lapse time (msec) + timer reset
reset()             // timer reset
check()             // true = lapse time passed + callback called + timer reset

SimpleBuffer        // constructor + set size (bytes)
available()         // return available items (bytes) in buffer
free()              // return free space (bytes) in buffer
full()              // true = buffer full / no free space
print()             // print buffer content to console (for debugging)
clr()               // clear buffer
get()               // get next item from buffer (fifo based), release item from buffer
put()               // put next item into buffer (lilo based)
```

The basic functions in the library include:
```
minMax(A,B,C)       // (macro) return A between boundaries (B, C)
strLen(A)           // (macro) true = empty string (A)
strCmp(A,B)         // (macro) true = equal string (A, B)
strClr(D)           // (macro) string (D)

addChr()            // add character to end of a string
strCat()            // append string to end of a string
strCpy()            // copy string to a string
fill()              // fill string with spaces until a given length (with optional centering)
dec()               // convert to dec string without leading zeros
dec()               // convert to dec string with leading zeros
hex()               // convert to hex string with leading zeros
```

## Library Dependencies

- none specfic

Version history:
```
0.3                 // initial pulished version
0.4                 // some cleanup
```
