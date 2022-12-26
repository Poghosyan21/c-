#ifndef BALL_HPP
#define BAll_HPP

#include "headeer.hpp"
#include <ulimit.h>
#include <ncurses.h>

class Ball
{
public:   
    Ball();
    void Choose_Ball_Direction(bool *);
    void Move_Ball();
    void Move_Back();
    void Clean_Ball();
    void Print_Ball();;
    void Print();
    void Set_Window(WINDOW *);
    bool Is_Touching_Side_Walls();
    int Get_Ball_Number();
    bool Is_Touching_Upper_Wall();
    bool Is_Touching_Bottom_Wall();
    void Touched_Side_Wall();
    void Touched_Upper_Wall();
    Position Get_Ball_Position();


private:
    std::pair <int, int> direction;
    Position ballPosition;
    Position ballStartPosition;
    int ballNumber;
    WINDOW * gameWin;
};


#endif