#include <iostream>
#include "grid.h"
#include "box.h"
#include "game.h"
#include "window.h"
#include "gameobject.h"

using namespace std;

int main(int argc, char** argv)
{
    Window* window = new Window();
    GameObject* gameObject = new GameObject(10, 10, 100, 100);
    srand(time(NULL)); 
    //gameLoop();
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

/*
  ----- ----- ----- -----
 |     |16834|     |     |
  ----- ----- ----- -----
 |     |     |     |  2  |
  ----- ----- ----- -----
 |     |  16 |     |     |
  ----- ----- ----- -----
 |     | 256 |     | 2048|
  ----- ----- ----- -----
*/