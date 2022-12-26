#include <ncurses.h>
#include <unistd.h>
#include "Map.hpp"

Map::Map()
{
    return ;
}

void Map::Set_Map(WINDOW * win)
{
    gameWin = win;
    box(gameWin, 0, 0);
    refresh();
    wrefresh(gameWin);
    for(int i = 1; i < MAP_WITH - 1; i++)
    {
        mvwprintw(gameWin, 4, i, "#");
        mvwprintw(gameWin, MAP_HEIGHT - 5, i, "#");
    }
    wrefresh(gameWin);
    wattron(gameWin,A_BOLD);
    mvwprintw(gameWin, 2, 5,"-BRICKS BALL CRUSHER-");
    mvwprintw(gameWin, 14 , 5,  "-BRICKS BALL CRUSHER-");
    wrefresh(gameWin);
    wattroff(gameWin,A_BOLD);
    sleep(2);
    Clean_Map();
}


void Map::Clean_Map()
{
     for(int y = 5; y < MAP_HEIGHT - 5; y++)
        for(int x = 1; x < MAP_WITH - 1; x++)
            mvwprintw(gameWin, y, x, " ");
    wrefresh(gameWin);
    Clean_Array();
}



bool Map::Is_Empty(Position pos)
{
    if(mapArray[pos.first][pos.second] == 0)
        return true;
    return false;
}



void Map::Add_Obstacle(Position pos)
{
    for(int i = pos.first; i < pos.first + 3; i ++)
        for(int j = pos.second; j < pos.second + 4; j++)
            mapArray[i][j] = 1;
}



void Map::Add_Bonus(Position pos)
{
    mapArray[pos.first][pos.second] = 2;
}



void Map::Clean_Array()
{
    for(int i = 0; i < MAP_HEIGHT; i++)
        for(int j = 0; j< MAP_WITH; j++)
            mapArray[i][j]  = 0;
}

void Map::Delite_Bonus(Position pos)
{
    mapArray[pos.first][pos.second] = 0;
}

void Map::Delite_Obstacle(Position pos)
{
 for(int i = pos.first; i < pos.first + 3; i ++)
        for(int j = pos.second; j < pos.second + 4; j++)
            mapArray[i][j] = 0;
}

bool Map::Check(Position pos)
{
    if((mapArray[pos.first][pos.second + 1] == 1)  ||  (mapArray[pos.first][pos.second - 1] == 1))
        return true;
    return false;
}