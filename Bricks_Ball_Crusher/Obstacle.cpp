#include <string>

#include "headeer.hpp"
#include "Obstacle.hpp"

Obstacle::Obstacle(WINDOW * win)
{
    gameWin = win;
}

void Obstacle::Set_Obstacle()
{
    isAlive = true;
    obstaclePosition.first = 5;
    obstaclePosition.second = (rand()%7) * 4 + 1;
}

void Obstacle::Print_Obstacle()
{
    for(int i = 0; i < 3; i++)
    {
        mvwprintw(gameWin, obstaclePosition.first + i, obstaclePosition.second, (obs[i].std::string::c_str()));
        wrefresh(gameWin);
    }
    //Print_Live_Number();
}

void Obstacle::Move_Down()
{
    obstaclePosition.first = obstaclePosition.first + 3;
}


void Obstacle::Hit_Obstacle()
{
    Kill_Obstacle();
       Clean_Obstacle();
}


void Obstacle::Kill_Obstacle()
{
    isAlive = false;
}

bool Obstacle::Is_Alive()
{
    return isAlive;
}

void Obstacle::Clean_Obstacle()
{
    for(int i = 0; i < 3; i++)
    {
        mvwprintw(gameWin, obstaclePosition.first +i, obstaclePosition.second, "    ");
        wrefresh(gameWin);
    }
}


Position Obstacle::Get_Obstacle_Position()
{
    return obstaclePosition;
}


bool Obstacle::Check_Position(Position pos)
{
    for(int i = obstaclePosition.first; i < obstaclePosition.first + 3; i++)
        for(int j = obstaclePosition.second; j < obstaclePosition.second + 4; j++)
            if(i == pos.first && j == pos.second)
            {
                Hit_Obstacle();
                return true;
            }
    return false;
}
