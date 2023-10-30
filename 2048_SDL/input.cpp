#include <conio.h>
#include "input.h"


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


enum Description {
    Up,
    Down,
    Right,
    Left
};


Description directionnalArrowInput()
{
    bool badKey = true;
    while (badKey)
    {
        badKey = false;
        int c = 0;
        switch ((c = _getch()))
        {
        case KEY_UP:
            return Up;
            break;
        case KEY_DOWN:
            return Down;
            break;
        case KEY_RIGHT:
            return Right;
            break;
        case KEY_LEFT:
            return Left;
            break;
        default:
            badKey = true;
            break;
        }
    }
}