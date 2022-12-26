#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "headeer.hpp"
#include <ncurses.h>
#include <vector>

class Obstacle
{
public:
    Obstacle(WINDOW *);
    void Set_Obstacle();
    Position Get_Obstacle_Position();
    void Print_Obstacle();
    void Clean_Obstacle();
    void Move_Down();
    void Hit_Obstacle();
    bool Is_Alive();
    void Kill_Obstacle();
    bool Check_Position(Position);

private:
    WINDOW * gameWin;
    Position obstaclePosition;
    bool isAlive;
    //char o
    std::vector<String> obs{
        "@@@@",
        "@  @",
        "@@@@"
    };

};


#endif