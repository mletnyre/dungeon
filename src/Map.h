#ifndef MAP_H
#define MAP_H

#include "Room.h"
#include <vector>

//this is the grid of the rooms 

class Map{
    public:
    Map(int x, int y): x_dim(x), y_dim(y), rooms(y, std::vector<Room>(x)){}

    int getXDim(){ return this->x_dim;}

    int getYDim(){ return this->y_dim;}

    void setXDim(int val){ this->x_dim = val;}

    void setYDim(int val){ this->y_dim = val;}

    private:

    int x_dim;
    int y_dim;
    std::vector<std::vector<Room>> rooms;
};

#endif