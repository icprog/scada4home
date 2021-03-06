/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  <copyright holder> <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "LogTracer.h"
#include <stdio.h>
#include <time.h>
#include <iostream>

LogTracer::LogTracer()
{  
  _LogMutex = PTHREAD_MUTEX_INITIALIZER;
  _Instance = this;
}

LogTracer::~LogTracer()
{

}

LogTracer* LogTracer::_Instance = NULL;

LogTracer* LogTracer::GetInstance()
{
  return _Instance;
}


void LogTracer::Log(LogTypes::T argType, string argText, ...)
{  
  
  string strOut = ">" + GetCurrentDateTime();
  if(argType == LogTypes::Error)
    strOut += " ERROR ";
  else if(argType == LogTypes::Warning)
    strOut += " WARNING ";
  else if(argType == LogTypes::Audit)
    strOut += " AUDIT ";
  
  strOut += argText + "\n";
  
  va_list arguments;                     // A place to store the list of arguments
   
  va_start ( arguments, argText );           // Initializing arguments to store all values after num
 
  
  pthread_mutex_lock( &_LogMutex );
  vprintf (strOut.c_str(), arguments);
  pthread_mutex_unlock( &_LogMutex );
 
  va_end ( arguments );                  // Cleans up the list
}


void LogTracer::Trace(string argText, ...)
{
  
  if(!_LogVerbose)
    return;
  
  string strOut = ">" + GetCurrentDateTime();
  strOut += " TRACE "+ argText + "\n";
  
  va_list arguments;                     // A place to store the list of arguments
   
  va_start ( arguments, argText );           // Initializing arguments to store all values after num
 
  pthread_mutex_lock( &_LogMutex );
  vprintf (strOut.c_str(), arguments);
  pthread_mutex_unlock( &_LogMutex );
 
  va_end ( arguments );                  // Cleans up the list
}

string LogTracer::GetCurrentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    
    //strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    strftime(buf, sizeof(buf), "%X", &tstruct);

    return buf;
}



void LogTracer::SetLogLevel(bool argHigh)
{
  _LogVerbose = argHigh;
}

