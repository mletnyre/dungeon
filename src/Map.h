#ifndef MAP_H
#define MAP_H

class Map{
    public:
    Map(int x_dim, int y_dim){
        this->x_dim = x_dim;
        this->y_dim = y_dim;
        
    }

    int getXDim(){ return this->x_dim;}

    int getYDim(){ return this->y_dim;}

    void setXDim(int val){ this->x_dim = val;}

    void setYDim(int val){ this->y_dim = val;}

    private:
    int x_dim;
    int y_dim;
};

#endif