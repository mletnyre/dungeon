#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Character.h"

class Player : public Character{
    public:
    Player(int x, int y, int rh, int rw):
        Character(x, y, rh, rw, 0, 0, 10, '@')
        {
        }
    private:
};

#endif