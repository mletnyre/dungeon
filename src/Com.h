#ifndef COM_H
#define COM_H

#include "Character.h"

class Com : public Character{
    public:
    Com(int x, int y, int rh, int rw):
        Character(x,y,rh,rw,0,0,10,'>'){}

    const Character* operator->() const {
        return this;
    }

    void print() const {
        std::cout<< "Com: " << name << " Location (x,y):"<<"("<<room_x<<","<<room_y<<")\n";
    }
};

#endif