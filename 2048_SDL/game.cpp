#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <SDL.h>

#include "grid.h"
#include "window.h"
#include "box.h"
#include "input.h"
#include "game.h"


/***
* METHOD
*   gameLoop
*       pWindow     -> window
*/
void gameLoop(Window* pWindow)
{
	bool is_finish = false;

    Grid* pgrid = new Grid();

    pgrid->debut();
    pgrid->display(pWindow->pRenderer);

    pWindow->Update();

	do
	{
        pgrid->movement();
        pgrid->addBox();


        SDL_RenderClear(pWindow->pRenderer);
        pgrid->display(pWindow->pRenderer);
        pWindow->Update();

        if (pgrid->canMove() == false)
        {
            if (pgrid->restart() == true)
            {
                delete pgrid;

                Grid* pgrid = new Grid();

                pgrid->debut();

                SDL_RenderClear(pWindow->pRenderer);
                pgrid->display(pWindow->pRenderer);
            }
            else {
                is_finish = true;
                pgrid->endGame();
            }
        }

	} while (is_finish == false);
    delete pgrid;
}



// OPTIMISATION POSSIBLE -> REVOIR BOUCLE DE JEU ET WIN/LOSE

