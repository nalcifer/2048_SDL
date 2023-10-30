#include <iostream>
#include <thread>
#include <chrono>

#include "grid.h"
#include "box.h"
#include "input.h"

#include "game.h"

void gameLoop()
{
	bool is_finish = true;

    Grid* pgrid = new Grid();

    pgrid->debut();
    pgrid->display();

	do
	{
        pgrid->movement();
        pgrid->addBox();
        pgrid->display();

	} while (is_finish);

    delete pgrid;
}

