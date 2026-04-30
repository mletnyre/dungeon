#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Character.h"

class Player : public Character{
    public:
    Player(int wx, int wy, int rx, int ry)
        :world_x(wx), world_y(wy), room_x(rx), room_y(ry){
            xp = 0;
            nextLevelXP = 10;
        }

    void drawPlayer(){
        //does nothing for now
    }

    void levelUp(){
        level++;
        nextLevelXP *= 1.05;
    }

    std::string getName(){return name;}
    int getLevel(){return level;}
    int getWorld_x(){return world_x;}
    int getWorld_y(){return world_y;}
    int getRoom_x(){return room_x;}
    int getRoom_y(){return room_y;}
    int getXP(){return xp;}
    int getNextLevelXP(){return nextLevelXP;}

    void setName(std::string n){name = n;}
    void setLevel(int l){level = l;}
    void setWorld_x(int wx){world_x = wx;}
    void setWorld_y(int wy){world_y = wy;}
    void setRoom_x(int rx){room_x = rx;}
    void setRoom_y(int ry){room_y = ry;}

    private:
    std::string name;
    int level;
    int xp;
    int nextLevelXP;
    int world_x;
    int world_y;
    int room_x;
    int room_y;
};

#endif