#include <iostream>
#include <vector>
#include <cstdlib>

//cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug

#include "Game.h"
#include "Room.h" 

#define ROOM_HEIGHT 23
#define ROOM_WIDTH  80
#define MAP_HEIGHT 100
#define MAP_WIDTH  100


int main(int argc, char* argv[]){

    std::cout<<"Starting Game.\n";
    Game *game = new Game(MAP_WIDTH, MAP_HEIGHT, ROOM_HEIGHT, ROOM_WIDTH);   
    //i j k l moves you around maps
    
    //main game loop
    char inp;
    while(game->getRunning()){
        std::cin>>inp;
        game->handleInput(inp);
    }

    return 0;
}