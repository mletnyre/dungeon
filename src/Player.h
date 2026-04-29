#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player{
    public:
    Player(std::string n):name(n){}
    Player(std::string n, int wx, int wy, int rx, int ry):name(n), world_x(wx), world_y(wy), room_x(rx), room_y(ry){}

    private:
    int level;
    int world_x;
    int world_y;
    int room_x;
    int room_y;
    std::string name;
};

#endif