#include <iostream>

#include "grid.h"
#include "box.h"
#include "game.h"
#include "window.h"
#include "gameobject.h"

using namespace std;

/***
* MAIN
* 
* initialization Window and Running game loop
* destruction game loop when game is finish
*/
int main(int argc, char** argv)
{
    Window* pWindow = new Window();
    
    srand(time(NULL)); 
    gameLoop(pWindow);

    pWindow->~Window();
    return 0;
}






/*
  ---- ---- ---- ----
 |8192|    |    |    |
  ---- ---- ---- ----
 |    |    |    | 2  |
  ---- ---- ---- ----
 |    | 16 |    |    |
  ---- ---- ---- ----
 |    |256 |    |2048|
  ---- ---- ---- ----
*/