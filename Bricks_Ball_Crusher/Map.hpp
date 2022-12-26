#ifndef MAP_HPP
#define MAP_HPP

#include <ncurses.h>
#include "headeer.hpp"


class Map
{
public:
    Map();
    bool Is_Empty(Position);
    void Set_Map(WINDOW *);
    void Clean_Map();
    void Add_Obstacle(Position);
    void Add_Bonus(Position);
    void Clean_Array();
    void Delite_Obstacle(Position);
    void Delite_Bonus(Position);
    bool Check(Position);
private:

    WINDOW * gameWin;
    int mapArray[MAP_HEIGHT][MAP_WITH] = {0};
};



#endif 