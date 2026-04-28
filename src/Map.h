#ifndef MAP_H
#define MAP_H

#include "Room.h"
#include <vector>

//this is the grid of the rooms 

class Map{
    public:
    Map(int x, int y, int rh, int rw): MAP_WIDTH(x), MAP_HEIGHT(y), ROOM_HEIGHT(rh), ROOM_WIDTH(rw),rooms(y, std::vector<Room>(x)){
        Room* FirstRoom = new Room(ROOM_HEIGHT, ROOM_WIDTH);
        FirstRoom->createRoom();
        FirstRoom->drawRoom();
    }

    int getXDim(){ return this->MAP_WIDTH;}

    int getYDim(){ return this->MAP_HEIGHT;}

    void setXDim(int val){ this->MAP_WIDTH = val;}

    void setYDim(int val){ this->MAP_HEIGHT = val;}

    private:
    int ROOM_HEIGHT;
    int ROOM_WIDTH;
    int MAP_WIDTH;
    int MAP_HEIGHT;
    std::vector<std::vector<Room>> rooms;
};

#endif