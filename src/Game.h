#ifndef MAP_H
#define MAP_H

#include "Room.h"
#include <vector>

//this is the grid of the rooms 

class Game{
    public:
    Game(int x, int y, int rh, int rw): MAP_WIDTH(x), MAP_HEIGHT(y), ROOM_HEIGHT(rh), ROOM_WIDTH(rw),rooms(y, std::vector<Room>(x)){
        Room* FirstRoom = new Room(ROOM_HEIGHT, ROOM_WIDTH);
        FirstRoom->createRoom();
        FirstRoom->drawRoom();
        FirstRoom->setWorld_x(MAP_WIDTH / 2);
        FirstRoom->setWorld_y(MAP_HEIGHT / 2);
        CurRoom = FirstRoom;
    }

    void handleInput(char inp){
        int world_x = CurRoom->getWorld_x();
        int world_y = CurRoom->getWorld_y();

        switch (inp){
            case 'j':
                //move left one room
                std::cout<<"Moving left";
                //check that the Room exists already
                break;
            case 'k':
                //move down one room
                std::cout<<"Moving down";
                break;
            case 'l':
                std::cout<<"Moving right";
                //move right one room
                break; 
            case 'i':
                std::cout<<"Moving up";
                //move up one room
                break;
            default:
                std::cout<<"Im not sure what to do with this input: " << inp;

        }
    }

    int getXDim(){ return this->MAP_WIDTH;}

    int getYDim(){ return this->MAP_HEIGHT;}

    void setXDim(int val){ this->MAP_WIDTH = val;}

    void setYDim(int val){ this->MAP_HEIGHT = val;}

    bool getRunning(){ return this->isRunning;}

    private:
    bool isRunning = true;
    int ROOM_HEIGHT;
    int ROOM_WIDTH;
    int MAP_WIDTH;
    int MAP_HEIGHT;
    Room* CurRoom;
    std::vector<std::vector<Room>> rooms;
};

#endif