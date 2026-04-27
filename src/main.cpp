#include <iostream>

#include <Room.h>

int main(){
    Room *r = new Room(5, 5);

    std::cout<<"Room XDim: " << r->getXDim() << "\n";
    std::cout<<"Room YDim: " << r->getYDim() << "\n";

    std::cout<<"Hello World\n";
    return 0; 
}