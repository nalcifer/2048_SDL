#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

#include "grid.h"
#include "box.h"
#include "input.h"


#include "game.h"

void gameLoop()
{
	bool is_finish = false;

    Grid* pgrid = new Grid();

    pgrid->debut();
    pgrid->display();

	do
	{
        pgrid->movement();
        pgrid->addBox();
        pgrid->display();

        if (pgrid->canMove() == false)
        {
            if (pgrid->restart() == true)
            {
                delete pgrid;

                Grid* pgrid = new Grid();

                pgrid->debut();
                pgrid->display();
            }
            else {
                is_finish = true;
                pgrid->endGame();
            }
        }

	} while (is_finish == false);

    std::cout << "finish";

    delete pgrid;
}

