// Copyright  : Dennis Buis (2017, 2018)
// License    : MIT
// Platform   : Arduino
// Library    : Simple Utility Library
// File       : SimpleHttp.h
// Purpose    : Provide simple functions to support HTTP messages
// Repository : https://github.com/DennisB66/Simple-Utility-Library-for-Arduino

#ifndef _SIMPLE_HTTP_H
#define _SIMPLE_HTTP_H

#include <Arduino.h>

enum HTTPMethod { HTTP_ANY, HTTP_GET, HTTP_HEAD, HTTP_POST, HTTP_PUT, HTTP_DELETE, HTTP_CONNECT, HTTP_OPTIONS, HTTP_PATCH };

#define HTTP_CONTINUE     100
#define HTTP_OK           200
#define HTTP_CREATED      201
#define HTTP_ACCPETED     202
#define HTTP_BAD_REQUEST  400

// get HTTP method from HTTP method string
HTTPMethod HTTP_Method( const char* method);

// get HTTP method string from HTTP method
const char* HTTP_Method( HTTPMethod method);

// get HTTP code response message
const __FlashStringHelper* HTTP_CodeMessage( int code);

// url character conversion
char* HTTP_urlDecode( char* line);

#endif
