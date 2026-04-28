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


int main(int argc, char* argv[]){
    std::cout<<"Starting Game.\n";
    Map *map = new Map(MAP_WIDTH, MAP_HEIGHT, ROOM_HEIGHT, ROOM_WIDTH);

    return 0;
}