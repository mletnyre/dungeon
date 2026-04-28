#ifndef MAP_H
#define MAP_H

#include "Room.h"
#include <vector>

//this is the grid of the rooms 

class Game{
    public:
    Game(int x, int y, int rh, int rw): MAP_WIDTH(x), MAP_HEIGHT(y), ROOM_HEIGHT(rh), ROOM_WIDTH(rw),rooms(y, std::vector<Room>(x)){
        Room* FirstRoom = new Room(ROOM_HEIGHT, ROOM_WIDTH, MAP_WIDTH/2, MAP_HEIGHT/2);
        FirstRoom->createRoom();
        FirstRoom->drawRoom();
        CurRoom = FirstRoom;
    }

    void handleInput(char inp){
        int newWorldX, newWorldY;
        int world_x = CurRoom->getWorld_x();
        int world_y = CurRoom->getWorld_y();
        std::cout<<"Current World Coordinates ("<<world_x<<","<<world_y<<")\n";
        Room* newRoom;
        switch (inp){
            case 'j':
                //move left one room
                std::cout<<"Moving left\n";
                newWorldX = world_x - 1;
                newWorldY = world_y;
                //check that the Room exists already
                break;
            case 'k':
                //move down one room
                std::cout<<"Moving down\n";
                newWorldX = world_x;
                newWorldY = world_y + 1;
                break;
            case 'l':
                std::cout<<"Moving right\n";
                newWorldX = world_x + 1;
                newWorldY = world_y;
                //move right one room
                break; 
            case 'i':
                std::cout<<"Moving up\n";
                newWorldX = world_x;
                newWorldY = world_y - 1;
                //move up one room
                break;
            default:
                std::cout<<"Im not sure what to do with this input: \n" << inp;
                break;
            }
            newRoom = new Room(ROOM_HEIGHT, ROOM_WIDTH, newWorldY, newWorldX);
            newRoom->createRoom();
            newRoom->drawRoom();
            CurRoom = newRoom;
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