#include "Ball.hpp"
#include "headeer.hpp"
#include <ncurses.h>

Ball::Ball()
{
    ballStartPosition.first = MAP_HEIGHT - 6;
    ballStartPosition.second = MAP_WITH / 2;
   
    ballNumber = 1;
    ballPosition.first = MAP_HEIGHT - 6;
    ballPosition.second = MAP_WITH / 2;
}

void Ball::Print_Ball()
{
    mvwprintw(gameWin, ballPosition.first, ballPosition.second, BALL_CHAR);
    wrefresh(gameWin);
}

void Ball::Clean_Ball()
{
    mvwprintw(gameWin, ballPosition.first,ballPosition.second, " ");
}


void Ball::Move_Ball()
{
    ballPosition.first = ballPosition.first - direction.first;
    ballPosition.second = ballPosition.second + direction.second ;
    if(Is_Touching_Side_Walls())
        {
          direction.second = direction.second * (-1);
            ballPosition.first = ballPosition.first - direction.first;
    ballPosition.second = ballPosition.second + direction.second ;
        }
    if(Is_Touching_Upper_Wall())
    {
        direction.first = direction.first *(-1);
         ballPosition.first = ballPosition.first - direction.first;
          ballPosition.second = ballPosition.second + direction.second ;
    }      
 
}


void Ball::Set_Window(WINDOW * win)
{
    gameWin = win;
}

void Ball::Choose_Ball_Direction(bool * b)
{
    direction.first = 1;
    bool * is_choice_done = b;

    keypad(gameWin, true);
    static int  choice = 0; 
        ballPosition.first = ballStartPosition.first;
        
        int ch =  wgetch(gameWin);
        
        switch(ch)
        {
            case KEY_LEFT:
                choice --;
                if(choice < -4)
                    choice = -4;
                ballPosition.second = ballStartPosition.second + 3 * choice;
               break;
            case KEY_RIGHT:
                choice ++;
                if(choice > 4)
                    choice = 4;
                ballPosition.second = ballStartPosition.second + 3 * choice;
                break;
            default:
                break;
            case Key_Space:
                * is_choice_done = true;
                break;
        }
            if(choice > 0)
                direction.second = 1;
            else if(choice < 0)
                direction.second = -1;
                else direction.second = 0;        
            return ;
    
}

void Ball::Move_Back()
{
    ballPosition.first = ballPosition.first + direction.first;
    ballPosition.second = ballPosition.second - direction.second ; 
    if(Is_Touching_Side_Walls())
    {
        direction.second = direction.second * (-1);
         ballPosition.first = ballPosition.first + direction.first;
    ballPosition.second = ballPosition.second - direction.second ; 
    }

}


Position Ball::Get_Ball_Position()
{
    return ballPosition;
}

bool Ball::Is_Touching_Side_Walls()
{
    if((ballPosition.second == 0) || (ballPosition.second == MAP_WITH - 2))
        return true;
    return false;
}


void Ball::Print()
{
    mvwprintw(gameWin, ballStartPosition.first, ballStartPosition.second, BALL_CHAR);
}

int Ball::Get_Ball_Number()
{
    return ballNumber;
}

bool Ball::Is_Touching_Bottom_Wall()
{
    if(ballPosition.first == MAP_HEIGHT - 6)
        return true;
    return false;
}

bool Ball::Is_Touching_Upper_Wall()
{
    if (ballPosition.first == 4) 
        return true;
    return false;
}

void Ball::Touched_Side_Wall()
{
        direction.second = direction.second * (-1);
    Move_Ball();        
}

void Ball::Touched_Upper_Wall()
{
    direction.first = direction.first *(-1);
    Move_Ball();
}