#ifndef MAP_H
#define MAP_H

#include "Room.h"
#include "Player.h"
#include <vector>
#include <optional>

//this is the grid of the rooms 

class Game{
    public:
    Game(int x, int y, int rh, int rw): MAP_WIDTH(x), MAP_HEIGHT(y), ROOM_HEIGHT(rh), ROOM_WIDTH(rw), rooms(y, std::vector<std::optional<Room>>(x)){
        Room* FirstRoom = new Room(ROOM_HEIGHT, ROOM_WIDTH, MAP_WIDTH/2, MAP_HEIGHT/2);
        FirstRoom->createRoom();
        FirstRoom->drawRoom();
        CurRoom = FirstRoom;
    }

    void handleInput(char inp){
        int world_x = CurRoom->getWorld_x();
        int world_y = CurRoom->getWorld_y();
        int newWorldX = world_y; 
        int newWorldY = world_x;
        Room* newRoom;
        if(inp == 'j'){
            //move left one room
            std::cout<<"Moving left\n";
            newWorldX = world_x - 1;
        }
        else if(inp == 'k'){
            //move down one room
            std::cout<<"Moving down\n";
            newWorldY = world_y + 1;
        }
        else if(inp =='l'){
            std::cout<<"Moving right\n";
            newWorldX = world_x + 1;
        }
        //move right one room
        else if(inp == 'i'){
            std::cout<<"Moving up\n";
            newWorldY = world_y - 1;
        }
        else{
            std::cout<<"Im not sure what to do with this input: \n" << inp;
        }
        if(!rooms[newWorldY][newWorldX].has_value()){    
            newRoom = new Room(ROOM_HEIGHT, ROOM_WIDTH, newWorldX, newWorldY);
            newRoom->createRoom();
            newRoom->drawRoom();
            CurRoom = newRoom;
        }
        else{
            Room room = rooms[newWorldY][newWorldX].value();
            room.drawRoom();
            CurRoom = &room;
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
    std::vector<std::vector<std::optional<Room>>> rooms;
    Player* player;
};

#endif