#ifndef ROOM_H
#define ROOM_H

//only one of these on the screen at a time, go through doors to move between them. 

class Room{
    public:
    Room(int y, int x): x_dim(x), y_dim(y), roomMap(y, std::vector<char>(x)){}

    Room(){}

    int getXDim(){ return this->x_dim;}

    int getYDim(){ return this->y_dim;}

    void setXDim(int val){ this->x_dim = val;}

    void setYDim(int val){ this->y_dim = val;}

    void setRoomMap(int y, int x, char c){roomMap[y][x] = c;}

    char getRoomMap(int y, int x){return roomMap[y][x];}

    void createRoom(){
        int i, j;
        int x_dim = this->getXDim();
        int y_dim = this->getYDim();
        for(i = 0; i < x_dim-1; i++){
            for(j = 0; j < y_dim-1; j++){
                if(i == 0 || j == 0 || i == x_dim - 2 || j == y_dim - 2){ //the edges
                    this->setRoomMap(j,i,'#');
                }
                else{
                    this->setRoomMap(j, i, '_'); //hard coded for now
                }
            }
        }
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
    std::vector<std::vector<char>> roomMap;
    int idx;
    int world_x;
    int world_y;
    int x_dim;
    int y_dim;
};

#endif