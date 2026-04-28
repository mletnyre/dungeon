#ifndef ROOM_H
#define ROOM_H

//only one of these on the screen at a time, go through doors to move between them. 

class Room{
    public:
    Room(int x, int y): x_dim(x), y_dim(y), roomMap(y, std::vector<char>(x)){}

    Room(){}

    int getXDim(){ return this->x_dim;}

    int getYDim(){ return this->y_dim;}

    void setXDim(int val){ this->x_dim = val;}

    void setYDim(int val){ this->y_dim = val;}

    void setRoomMap(int y, int x, char c){roomMap[y][x] = c;}

    char getRoomMap(int y, int x){return roomMap[y][x];}

    private:
    std::vector<std::vector<char>> roomMap;
    int idx;
    int world_x;
    int world_y;
    int x_dim;
    int y_dim;
};

#endif