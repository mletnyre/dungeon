#ifndef ROOM_H
#define ROOM_H

//only one of these on the screen at a time, go through doors to move between them. 
#include <cstdlib>
#include "Com.h"
#include <cstring>

class Room{
    public:
    Room(int y, int x, int wx, int wy): x_dim(x), y_dim(y), world_x(wx), world_y(wy), roomMap(y, std::vector<char>(x)){}

    std::vector<Com> getComs(){return this->coms;}

    int getXDim(){ return this->x_dim;}

    int getYDim(){ return this->y_dim;}

    void setXDim(int val){ this->x_dim = val;}

    void setYDim(int val){ this->y_dim = val;}

    void setRoomMap(int y, int x, char c){roomMap[y][x] = c;}

    char getRoomMap(int y, int x){return roomMap[y][x];}

    void setWorld_x(int x){world_x = x;}
    int  getWorld_x(){return world_x;}
    
    void setWorld_y(int y){world_y = y;}
    int  getWorld_y(){return world_y;}

    void createRoom(){
        int i, j;
        int x_dim = this->getXDim();
        int y_dim = this->getYDim();
        for(i = 0; i < x_dim; i++){
            for(j = 0; j < y_dim; j++){
                if(i == 0 || j == 0 || i == x_dim-1 || j == y_dim -1 ){ //the edges
                    this->setRoomMap(j,i,'#');
                }
                else{
                    this->setRoomMap(j, i, '_'); //hard coded for now
                }
            }
        }
        placeDoors();
        carveRoom();
        generateComs();
    }

    void generateComs(){
        //adds comCount number of coms to the coms vector. ensures that they are not overlapping
        //for now each room will have 5 coms in it
        int comCount = CalculateComCount();
        int ranY, ranX;
        for(int i = 0; i < comCount; i ++){
            bool valid = false;
            while(!valid){
                ranX = i + 5;
                ranY = i + 7;
                if(validSpot(ranX, ranY)){
                    valid = true;
                }
            }
            Com* c = new Com(getWorld_x(), getWorld_y(), ranX, ranY);
            coms.push_back(*c);
        }
    }

    bool validSpot(int ranX, int ranY){
        const char* RoomChars = "_";
        char square = roomMap[ranY][ranX];
        if(strchr(RoomChars, square)){
            return true; 
        }
        return false;
    }

    int CalculateComCount(){
        return 5;//hardcoded for now
    }

    void drawRoom(){
        int i, j;
        for(j = 0; j < y_dim; j++){
            for(i = 0; i < x_dim; i++){
                std::cout<<this->getRoomMap(j, i);
            }
                std::cout << "\n";
        }
    }

    private:
    
    void setDoors(int n, int s, int e, int w){
        nDoor = n;
        sDoor = s;
        wDoor = w;
        eDoor = e;
    }

    void placeDoors(){
        //pick a random spot for each door on all 4 sides
        
        int nDoor = (rand() % x_dim -1) + 1;
        int sDoor = (rand() % x_dim -1) + 1;

        int wDoor = (rand() % y_dim -1) + 1;
        int eDoor = (rand() % y_dim -1) + 1;

        setRoomMap(0, nDoor, '*');//set n Door
        setRoomMap(y_dim - 1, sDoor, '*');//set s Door
        
        setRoomMap(wDoor, 0,  '*');//set w Door
        setRoomMap(eDoor, x_dim - 1, '*');//set e Door

        setDoors(nDoor, sDoor, eDoor, wDoor);
    }

    void carveRoom(){
        //some kind of minesweeper like algo?

    }

    std::vector<std::vector<char>> roomMap;
    bool initialized = false;
    int idx;
    int world_x;
    int world_y;
    int x_dim;
    int y_dim;
    int nDoor, sDoor, eDoor, wDoor;
    std::vector<Com> coms;
};

#endif