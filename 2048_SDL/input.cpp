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
                std::cout << "up";
                return Up;
            case SDLK_DOWN:
                std::cout << "down";
                return Down;
            case SDLK_RIGHT:
                std::cout << "right";
                return Right;
            case SDLK_LEFT:
                std::cout << "left";
                return Left;
            }
            break;
        }
    }
}