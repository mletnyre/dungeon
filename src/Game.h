#ifndef MAP_H
#define MAP_H

#include "Room.h"
#include "Player.h"
#include "Character.h"
#include "Com.h"
#include <vector>
#include <optional>

//this is the grid of the rooms 

class Game{
    public:
    Game(int x, int y, int rh, int rw): MAP_WIDTH(x), MAP_HEIGHT(y), ROOM_HEIGHT(rh), ROOM_WIDTH(rw), rooms(y, std::vector<std::optional<Room>>(x)){
        //generate the room first so that the Player constructor can use its information
        Room* FirstRoom = new Room(ROOM_HEIGHT, ROOM_WIDTH, MAP_WIDTH/2, MAP_HEIGHT/2);
        FirstRoom->createRoom();
        CurRoom = FirstRoom;

        player = new Player(CurRoom->getWorld_x(), CurRoom->getWorld_y(), CurRoom->getXDim() / 2, CurRoom->getYDim() / 2);
        ShowStartScreen(); 
        renderScene();
    }
    
    void run(){
        while(this->isRunning){
            startPlayersTurn();
            renderScene();
            moveComs();
            renderScene();
        }

    }
    private:
    
    void moveComs(){
        std::vector<Com> coms = CurRoom->getComs();
        for(Com c: coms){
            //pick a random dir to move
            checkFight(c);
        }
    }

    void checkFight(Character c){

    }

    void renderScene(){
        //find the current room
        //find player position
        //display "hud" information
        drawHud();
        int i, j;
        std::vector<Com> coms = CurRoom->getComs();
        for(j = 0; j < CurRoom->getYDim(); j++){
            for(i = 0; i < CurRoom->getXDim(); i++){

                //if this is a com or the character then draw that rather than the room char
                for(const Com& c: coms){
                    int x = c->getRoom_x();
                    int y = c->getRoom_y();
                    if(x == i && y == j){
                        std::cout<<c->getSymbol();
                        continue;
                    }
                }
                if(player->getRoom_x() == i && player->getRoom_y() == j){
                    std::cout<<player->getSymbol();
                    continue;
                }
                std::cout<<CurRoom->getRoomMap(j, i);
            }
                std::cout << "\n";
        }
    }

    void drawHud(){
        using std::cout;
        cout<<"Player Name:" << player->getName() << " Player Level: " << player->getLevel();
        cout<<" XP: "<<player->getXP() << " XP for next level: "<< player->getNextLevelXP()<<"\n";
        cout<<"Current World Coordiantes ("<<CurRoom->getWorld_x()<<","<<CurRoom->getWorld_y()<<")\n";
    }

    void ShowStartScreen(){
        std::string name;
        std::cout<<"Welcome to dungeon game by Matthew Etnyre\n";
        std::cout<<"Please Enter a name for your hero\n";
        std::cin >> name;
        player->setName(name);
    }

    void startPlayersTurn(){
        char inp;
        std::cin>>inp;
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
        else if(inp == 'w'){
            player->setRoom_y(player->getRoom_y() - 1);
        }
        else if(inp == 'a'){
            player->setRoom_x(player->getRoom_x() - 1);
        }
        else if(inp == 's'){
            player->setRoom_y(player->getRoom_y() + 1);
        }
        else if(inp == 'd'){
            player->setRoom_x(player->getRoom_x() + 1); 
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
    //do we even need setters and getters if the only public method is going to be run()??
    // int getXDim(){ return this->MAP_WIDTH;}
    
    // int getYDim(){ return this->MAP_HEIGHT;}
    
    // void setXDim(int val){ this->MAP_WIDTH = val;}
    
    // void setYDim(int val){ this->MAP_HEIGHT = val;}
    
    // bool getRunning(){ return this->isRunning;}

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