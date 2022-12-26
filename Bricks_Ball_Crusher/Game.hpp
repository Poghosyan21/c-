#ifndef GAME_HPP
#define GAME_HPP


#include "Ball.hpp"
#include "Map.hpp"
#include "Obstacle.hpp"
#include <ncurses.h>
#include <vector>

class Game
{
public:
    Game();
    void Start_Game();


private:
    void Set_Window();
    void Menu();
    void End_Game();
    bool Is_Game_Over();
    void Push_Obstacles();
    void Move_Down();
    void Print();
    void Check_Obstacles(Position);
    void Raund();
    int  Get_Raund_Number();
    void Hit();
    void Check_Is_Game_Over(Position);

    int menuResult = 0;
    std::vector<Obstacle> obstacle;
    int raundNumber;
    WINDOW * gameWin;
    Ball ball;
    bool gameOver;
    Map map;
};

#endif