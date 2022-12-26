#include <ncurses.h>
#include <unistd.h>
#include <string>

#include "Game.hpp"
#include "headeer.hpp"
#include "Map.hpp"

Game::Game()
{
    gameOver = false;
}

bool Game::Is_Game_Over()
{
    return gameOver;
}

int  Game::Get_Raund_Number()
{
    return raundNumber;
}

void Game::Start_Game()
{
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    Set_Window();
    Menu();
    Raund();
    endwin();
}

void Game::End_Game()
{
    map.Clean_Map();
    wattron(gameWin, A_BOLD);
    mvwprintw(gameWin, MAP_HEIGHT / 2 , MAP_WITH / 2 - 5, "GAME OVER");
    wrefresh(gameWin);
    wattroff(gameWin, A_BOLD);
    gameOver = true;
    getch();
}

void Game::Set_Window()
{
    Position pos;
    getmaxyx(stdscr, pos.first, pos.second);
    gameWin = newwin(MAP_HEIGHT, MAP_WITH, (pos.first/2 - 15), (pos.second/2 -20));
    ball.Set_Window(gameWin);
    map.Set_Map(gameWin);
}




void Game::Raund()
{
    while(!Is_Game_Over())
    {
    map.Clean_Map();
    Move_Down();
    if(!Is_Game_Over())
    {
    Push_Obstacles();
    Print();
    ball.Clean_Ball();
    bool choice = false;
    while(!choice)
    {
        ball.Choose_Ball_Direction(&choice);
        for(int i = 0; i < 3; i++)
            if(map.Is_Empty(ball.Get_Ball_Position()))
            {
                ball.Print_Ball();
                ball.Move_Ball();
            }
        sleep(1.8);
        for(int i = 0; i < 3; i++)
            if(map.Is_Empty(ball.Get_Ball_Position()))
            {
                ball.Move_Back();
                ball.Clean_Ball();
            }
    }
    Hit();
    }
    }
}



void Game::Push_Obstacles()   
{
    Obstacle ob(gameWin);
    for(int  i = 0;  i < 3; i++)
    {
        ob.Set_Obstacle();
        while(!map.Is_Empty(ob.Get_Obstacle_Position()))
        {
            ob.Set_Obstacle();
        }
        obstacle.push_back(ob);
        map.Add_Obstacle(ob.Get_Obstacle_Position());   
    }

}



void Game::Move_Down()
{
    for(int i = 0; i < obstacle.size() ; i ++)
        if(obstacle[i].Is_Alive())
        {
            obstacle[i].Move_Down();
            map.Add_Obstacle(obstacle[i].Get_Obstacle_Position());
            Check_Is_Game_Over(obstacle[i].Get_Obstacle_Position());
        }
}

void Game::Print()
{
    for(int i = 0; i < int (obstacle.size()); i ++)
        obstacle[i].Print_Obstacle();
}



void Game::Hit()
{
    ball.Move_Ball();
    while(!ball.Is_Touching_Bottom_Wall())
        {

            ball.Clean_Ball();
            ball.Move_Ball();
            sleep(1.1);
            if(map.Is_Empty(ball.Get_Ball_Position()))
                ball.Print_Ball();
            else
            {  
                Check_Obstacles(ball.Get_Ball_Position());
            } 
        }
    ball.Print_Ball();
}



void Game::Check_Obstacles(Position pos)
{
    for(int i = 0; i < obstacle.size(); i++ )
        if(obstacle[i].Check_Position(pos))
            if(!obstacle[i].Is_Alive())
                map.Delite_Obstacle(obstacle[i].Get_Obstacle_Position());
}



void Game::Check_Is_Game_Over(Position pos)
{
    if(pos.first == MAP_HEIGHT - 10)
        End_Game();
}




void Game::Menu()
{
    keypad(gameWin, true);
    while(1)
    {
        for(int i = 0; i < 2; i++ )
        {
            if( i == menuResult )
                wattron(gameWin, A_REVERSE);
            wattron(gameWin, A_BOLD);
            mvwprintw(gameWin, i * 2 + 14, 13, (choices[i].std::string::c_str()));
            wattroff(gameWin, A_BOLD);
            wattroff(gameWin, A_REVERSE);
        }
        int ch = wgetch(gameWin);
        switch(ch)
        {
            case (KEY_UP):
                menuResult --;
                if(menuResult < 0)
                    menuResult = 0;
                break;
            case (KEY_DOWN):
                menuResult ++;
                if(menuResult > 1)
                    menuResult = 1;
                break;
            default:
                break;
        }
        if(ch == Key_Enter)
        {
            if(menuResult == 1)
                End_Game();
            return;
        }
    }
}