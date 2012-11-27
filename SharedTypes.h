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


#ifndef SHAREDTYPES_H
#define SHAREDTYPES_H

#include "SharedEnums.h"

typedef struct
{
    SCADAMessageTypes::T MsgType;
    SCADASourceTypes::T Source;
    uint8_t SourceIndex;
    Functions::T Func;
    uint8_t Target;
    uint8_t Value;    
} ScadaMessage; 

typedef struct
{
    PLCMessageTypes::T MsgType;
    PLCSourceTypes::T SourceType;
    uint8_t SourceIndex;    
    PLCUnitProperties::T Property;
    uint16_t Value;    
} PLCMessage;

typedef struct
{
    CULMessageTypes::T MsgType;
    CULSourceTypes::T SourceType;
    uint8_t SourceIndex;    
    CULUnitProperties::T Property;
    uint16_t Value;    
} CULMessage;


typedef struct
{
    HMIMessageTypes::T MsgType;
    HMISourceTypes::T SourceType;
    uint8_t SourceIndex;    
    HMIUnitProperties::T Property;
    uint16_t Value;    
} HMIMessage;


class IPLCEventSubscriber
{
  public:
    virtual void PLCMessageReceived(PLCMessage argMsg) = 0;
};

class ICULEventSubscriber
{
  public:
    virtual void CULMessageReceived(CULMessage argMsg) = 0;
};


class IHMIEventSubscriber
{
  public:
    virtual void HMIMessageReceived(HMIMessage argMsg) = 0;
};

#endif // SHAREDTYPES_H
