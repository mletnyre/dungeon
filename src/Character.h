#ifndef CHARACTER_H
#define CHARACTER_H

class Character{
    public:
    Character(int wx, int wy, int rx, int ry, int l, double x, double nxp, char c)
        :world_x(wx), world_y(wy), 
         room_x(rx), room_y(ry),
         level(l), xp(x), nextLevelXP(nxp), symbol(c){
        }
    

    void levelUp(){
        level++;
        nextLevelXP *= 1.05;
    }

    std::string getName()const {return name;}
    int getLevel() const {return level;}
    int getWorld_x()const {return world_x;}
    int getWorld_y()const {return world_y;}
    int getRoom_x()const {return room_x;}
    int getRoom_y()const {return room_y;}
    double getXP()const {return xp;}
    double getNextLevelXP()const {return nextLevelXP;}
    char getSymbol()const {return symbol;}

    void setName(std::string n){name = n;}
    void setLevel(int l){level = l;}
    void setWorld_x(int wx){world_x = wx;}
    void setWorld_y(int wy){world_y = wy;}
    void setRoom_x(int rx){room_x = rx;}
    void setRoom_y(int ry){room_y = ry;}
    void setSymbol(char c){symbol = c;}


    private:
    char symbol;
    std::string name;
    int level;
    double xp;
    double nextLevelXP;
    int world_x;
    int world_y;
    int room_x;
    int room_y;
};

#endif