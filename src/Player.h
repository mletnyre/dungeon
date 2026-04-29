#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player{
    public:
    Player(){}

    private:
    int level;
    int world_x;
    int world_y;
    int room_x;
    int room_y;
    std::string name;
};

#endif