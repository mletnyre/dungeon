#include <iostream>
#include <vector>
#include <cstdlib>

#include "Map.h"
#include "Room.h"
#include <iostream> 

#define ROOM_HEIGHT 23
#define ROOM_WIDTH  80
#define MAP_HEIGHT 100
#define MAP_WIDTH  100

void createRoom(Room* room){
    int i, j;
    int x_dim = room->getXDim();
    int y_dim = room->getYDim();
    for(i = 0; i < x_dim-1; i++){
        for(j = 0; j < y_dim-1; j++){
            room->setRoomMap(j, i, '&'); //hard coded for now
        }
    }
}
void drawRoom(Room* room){
    int room_x, room_y, i, j;
    for(j = 0; j < room_y; j++){
        for(i = 0; i < room_x; i++){
            std::cout<<room->getRoomMap(j, i);
            }
            std::cout << "\n";
        }
    }

Map* createMap(){
    std::cout<<"Creating Map...\n";
    Map* out = new Map(MAP_HEIGHT, MAP_WIDTH);
    Room* FirstRoom = new Room(ROOM_HEIGHT, ROOM_WIDTH);

    createRoom(FirstRoom);
    drawRoom(FirstRoom);

    std::cout<<"Done.\n";
    return out;
}


int main(int argc, char* argv[]){
    std::cout<<"Starting Game.\n";
    Map *map = createMap();

    return 0;
}