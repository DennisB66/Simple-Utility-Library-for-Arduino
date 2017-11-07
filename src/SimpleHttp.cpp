// Copyright  : Dennis Buis (2017)
// License    : MIT
// Platform   : Arduino
// Library    : Simple Utils Library
// File       : SimpleHttp.cpp
// Purpose    : Provide simple functions to support HTTP messages
// Repository : https://github.com/DennisB66/Simple-Utility-Library-for-Arduino

#include "SimpleHTTP.h"

// get HTTP method from HTTP method string
HTTPMethod HTTP_Method( const char* method)
{
  if ( strcmp_P( method, PSTR( "GET"    )) == 0) return HTTP_GET;
  if ( strcmp_P( method, PSTR( "HEAD"   )) == 0) return HTTP_HEAD;
  if ( strcmp_P( method, PSTR( "POST"   )) == 0) return HTTP_POST;
  if ( strcmp_P( method, PSTR( "PUT"    )) == 0) return HTTP_PUT;
  if ( strcmp_P( method, PSTR( "DELETE" )) == 0) return HTTP_DELETE;
  if ( strcmp_P( method, PSTR( "CONNECT")) == 0) return HTTP_CONNECT;
  if ( strcmp_P( method, PSTR( "OPTIONS")) == 0) return HTTP_OPTIONS;
  if ( strcmp_P( method, PSTR( "PATCH"  )) == 0) return HTTP_PATCH;
  return HTTP_ANY;
}

// get HTTP method string from HTTP method
const char* HTTP_Method( HTTPMethod method)
{
  switch ( method) {
    case HTTP_GET     : return "GET";
    case HTTP_HEAD    : return "HEAD";
    case HTTP_POST    : return "POST";
    case HTTP_PUT     : return "PUT";
    case HTTP_DELETE  : return "DELETE";
    case HTTP_CONNECT : return "CONNECT";
    case HTTP_PATCH   : return "PATCH";
    case HTTP_OPTIONS : return "OPTIONS";
    default           : return "GET";
  }
}

// get HTTP code response message
const __FlashStringHelper* HTTP_CodeMessage( int code) {
  switch ( code) {
    case 100: return F( "Continue");
    case 101: return F( "Switching Protocols");
    case 200: return F( "OK");
    case 201: return F( "Created");
    case 202: return F( "Accepted");
    case 203: return F( "Non-Authoritative Information");
    case 204: return F( "No Content");
    case 205: return F( "Reset Content");
    case 206: return F( "Partial Content");
    case 300: return F( "Multiple Choices");
    case 301: return F( "Moved Permanently");
    case 302: return F( "Found");
    case 303: return F( "See Other");
    case 304: return F( "Not Modified");
    case 305: return F( "Use Proxy");
    case 307: return F( "Temporary Redirect");
    case 400: return F( "Bad Request");
    case 401: return F( "Unauthorized");
    case 402: return F( "Payment Required");
    case 403: return F( "Forbidden");
    case 404: return F( "Not Found");
    case 405: return F( "Method Not Allowed");
    case 406: return F( "Not Acceptable");
    case 407: return F( "Proxy Authentication Required");
    case 408: return F( "Request Time-out");
    case 409: return F( "Conflict");
    case 410: return F( "Gone");
    case 411: return F( "Length Required");
    case 412: return F( "Precondition Failed");
    case 413: return F( "Request Entity Too Large");
    case 414: return F( "Request-URI Too Large");
    case 415: return F( "Unsupported Media Type");
    case 416: return F( "Requested range not satisfiable");
    case 417: return F( "Expectation Failed");
    case 500: return F( "Internal Server Error");
    case 501: return F( "Not Implemented");
    case 502: return F( "Bad Gateway");
    case 503: return F( "Service Unavailable");
    case 504: return F( "Gateway Time-out");
    case 505: return F( "HTTP Version not supported");
    default:  return F( "");
  }
}

// url character conversion
char* HTTP_urlDecode( char* line)
{
  char hex[] = "0x00";                            // decode template
  int  l     = strlen( line);                     // total chars to be decoded
  int  i     = 0;                                 // encode char index
  int  d     = 0;                                 // decode char index

  while ( i <= l) {                               // include '/0' terminator
    char enc = line[i++];                         // encoded char
    char dec;                                     // decoded char

    if (( enc == '%') && ( i + 1 < l)) {          // found encoded char
      hex[2] = line[i++];                         // read 1st hex digit
      hex[3] = line[i++];                         // read 2nd hex digit

      dec = (char) strtol( hex, NULL, 16);        // convert hex to char
    } else {
      dec = ( enc == '+') ? ' ' : enc;            // convert '+' to space
    }

    line[d++] = dec;                              // save decoded char
  }

	return line;
}
