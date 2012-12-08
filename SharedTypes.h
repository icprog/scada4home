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

#include <stdint.h>


namespace ItemMessageTypes
{
  enum T : uint8_t {StatusUpdate=1, Event=2,Alive=3};
}
namespace ItemTypes
{
  enum T : uint8_t {Jalousie=1,Rollo=2,Switch=3,Dummy=99};
}
namespace ItemProperties
{
  enum T  : uint8_t {Status=1,Value=2};
}

typedef struct
{
    ItemMessageTypes::T MsgType;
    ItemTypes::T ItemType;
    uint8_t ItemIndex;    
    ItemProperties::T Property;
    uint16_t Value;    
} ItemUpdateMessage;



class IPLCEventSubscriber
{
  public:
    virtual void PLCMessageReceived(ItemUpdateMessage argMsg) = 0;
};

class ICULEventSubscriber
{
  public:
    virtual void CULMessageReceived(ItemUpdateMessage argMsg) = 0;
};


class IHMIEventSubscriber
{
  public:
    virtual void HMIMessageReceived(ItemUpdateMessage argMsg) = 0;
};

#endif // SHAREDTYPES_H
