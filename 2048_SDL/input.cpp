#include <SDL.h>
#include <iostream>

enum Description {
    Up,
    Down,
    Right,
    Left
};

/***
* METHOD
*
* returning value relative to the player's keyboard input
*/
Description directionnalArrowInput()
{
    SDL_Event event;
    bool keyPressed = false;

    while (!keyPressed)
    {
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
                return Up;
            case SDLK_DOWN:
                return Down;
            case SDLK_RIGHT:
                return Right;
            case SDLK_LEFT:
                return Left;
            }
            break;
        }
    }
}