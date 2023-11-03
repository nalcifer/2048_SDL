#include "grid.h"
#include "box.h"
#include "input.h"
#include "gameobject.h"
#include "window.h"

#include <iostream>
#include <SDL.h>


using namespace std;

/***
* TEMPLATE
* 
* used to remove an element from a vector
*/
template <typename T>
void remove(std::vector<T>& v, size_t index) {
    v.erase(v.begin() + index);
}

/***
* CONSTRUCTOR
* 
* initialize array and vector with empty boxes
* first used in the game and second to know which box is empty to add a new value in game
*/
Grid::Grid()
{
    i = 0;
    j = 0;
    k = 0;
    x = 0;
    y = 0;

    moved = false;

    for (int m = 0; m < 4; m++)
    {
        for (int n = 0; n < 4; n++)
        {

            Box* box = new Box(0, m, n);
            tab[m][n] = box;
            
            free_tab.push_back(box);

        }
    }
}

/***
* METHOD
*   display      
*       renderer of canva 
* 
* Draw tab on canva with the good picture
*/
void Grid::display(SDL_Renderer* pRenderer)
{
    for (i = 0; i < 5; i++) {
        if (i < 4) {
            for (j = 0; j < 4; j++) {
                int collisions;
                if (tab[i][j]->getValue() != 0)
                    collisions = static_cast<int>(std::log2(tab[i][j]->getValue()));
                else
                    collisions = 0;
                GameObject* pGameObject = new GameObject(j * 175 ,i * 175, 150, 150, pRenderer);
                pGameObject->DrawImg(pRenderer, pGameObject->albums[collisions]);
            }
        }
    }
}

/***
* METHOD
*   randomNum
*       offset -> smallest number desired
*       range -> int of numbers in the desired list of numbers
* 
* return random number with precise specificity
*/
int Grid::randomNum(int offset, int range) {
    int randNum = offset + (rand() % range);
    return randNum;
}


/***
* METHOD
*   addBox
* 
* Adds a value to a random box in the vector of empty boxes
*/
void Grid::addBox()
{
    int randValue = randomNum(1, 2);
    randValue = randValue * 2;
    int randBox = randomNum(0, free_tab.size());
    
    free_tab[randBox]->setValue(randValue);
    free_tab[randBox]->setEmpty(false);

    remove(free_tab, randBox);
}


/***
* METHOD
*   debut
* 
* generate 2 random boxes (2;4) at the begging of the game
*/
void Grid::debut()
{
    for (i = 0; i < 2; i++) {
        addBox();
    }
}

/***
* METHOD
*   getDirection
* 
* used to get input player and add value to variables
*/
void Grid::getDirection()
{
    int direction = directionnalArrowInput();
    x = 0;
    y = 0;
    switch (direction) 
    {
    case 0 :
        x = 1;
        break;
    case 1:
        x = -1;
        break;
    case 2:
        y = 1;
        break;
    case 3:
        y = -1;
        break;
    }
}


/***
* METHOD
*   movement
* 
* call specific method thanks to the input value
*/
void Grid::movement()
{
    int direction[2];

    do {
        getDirection();

        direction[0] = x;
        direction[1] = y;

        if (x == 1) {
            moved = moveUp();
        }
        if (x == -1) {
            moved = moveDown();
        }
        if (y == 1) {
            moved = moveRight();
        }
        if (y == -1) {
            moved = moveLeft();
        }

        if (moved == false) {
            cout << "retry" << endl;
        }

    } while (moved == false);

    clearTab();
}

/***
* METHOD
*   clearTab
* 
* clear and refill vector of empty boxes
*/
void Grid::clearTab()
{
    free_tab.clear();
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (tab[i][j]->getEmpty() == true)
                free_tab.push_back(tab[i][j]);
        }
    }
}

/***
* METHOD
*   moveUp
*/
bool Grid::moveUp() {
    moved = false;

    for (i = 1; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (tab[i][j]->getEmpty() == false) {
                for (k = i; k > 0; k--) {
                    if (tab[i - k][j]->getEmpty() == true) {
                        tab[i - k][j]->setValue(tab[i][j]->getValue());
                        tab[i - k][j]->setEmpty(false);
                        tab[i][j]->setEmpty(true);
                        tab[i][j]->setValue(0);
                        moved = true;
                        break;
                    }
                }
                if ((i - k - 1) >= 0 && tab[i - k][j]->getValue() != 0 && tab[i - k - 1][j]->getValue() == tab[i - k][j]->getValue()) {
                    tab[i - k - 1][j]->setValue(tab[i - k][j]->getValue() * 2);
                    tab[i - k][j]->setEmpty(true);
                    tab[i - k][j]->setValue(0);
                    if (tab[i - k - 1][j]->getValue() == 2048) {
                        win();
                    }
                    moved = true;
                    break;
                }
            }
        }
    }

    return moved;
}

/***
* METHOD
*   moveDown
*/
bool Grid::moveDown() {
    moved = false;

    for (i = 2; i >= 0; i--) {
        for (j = 0; j < 4; j++) {
            if (tab[i][j]->getEmpty() == false) {
                for (k = (3 - i); k > 0; k--) {
                    if (tab[i + k][j]->getEmpty() == true) {
                        tab[i + k][j]->setValue(tab[i][j]->getValue());
                        tab[i + k][j]->setEmpty(false);
                        tab[i][j]->setEmpty(true);
                        tab[i][j]->setValue(0);
                        moved = true;
                        break;
                    }
                }
                if ((i + k + 1) <= 3 && tab[i + k][j]->getValue() != 0 && tab[i + k + 1][j]->getValue() == tab[i + k][j]->getValue()) {
                    tab[i + k + 1][j]->setValue(tab[i + k][j]->getValue() * 2);
                    tab[i + k][j]->setEmpty(true);
                    tab[i + k][j]->setValue(0);
                    if (tab[i + k + 1][j]->getValue() == 2048) {
                        win();
                    }
                    moved = true;
                    break;
                }
            }
        }
    }
    
    return moved;
}

/***
* METHOD
*   moveLeft
*/
bool Grid::moveLeft() {
    moved = false;

    for (i = 0; i < 4; i++) {
        for (j = 1; j < 4; j++) {
            if (tab[i][j]->getEmpty() == false) {
                for (k = j; k > 0; k--) {
                    if (tab[i][j - k]->getEmpty() == true) {
                        tab[i][j - k]->setValue(tab[i][j]->getValue());
                        tab[i][j - k]->setEmpty(false);
                        tab[i][j]->setEmpty(true);
                        tab[i][j]->setValue(0);
                        moved = true;
                        break;
                    }
                }
                if ((j - k - 1) >= 0 && tab[i][j - k]->getValue() != 0 && tab[i][j - k - 1]->getValue() == tab[i][j - k]->getValue()) {
                    tab[i][j - k - 1]->setValue(tab[i][j - k]->getValue() * 2);
                    tab[i][j - k]->setEmpty(true);
                    tab[i][j - k]->setValue(0);
                    if (tab[i][j - k - 1]->getValue() == 2048) {
                        win();
                    }
                    moved = true;
                    break;
                }
            }
        }
    }

    return moved;
}

/***
* METHOD
*   moveRight
*/
bool Grid::moveRight() {
    moved = false;

    for (i = 0; i < 4; i++) {
        for (j = 2; j >= 0; j--) {
            if (tab[i][j]->getEmpty() == false) {
                for (k = (3 - j); k > 0; k--) {
                    if (tab[i][j + k]->getEmpty() == true) {
                        tab[i][j + k]->setValue(tab[i][j]->getValue());
                        tab[i][j + k]->setEmpty(false);
                        tab[i][j]->setEmpty(true);
                        tab[i][j]->setValue(0);
                        moved = true;
                        break;
                    }
                }
                if ((j + k + 1) <= 3 && tab[i][j + k]->getValue() != 0 && tab[i][j + k + 1]->getValue() == tab[i][j + k]->getValue()) {
                    tab[i][j + k + 1]->setValue(tab[i][j + k]->getValue() * 2);
                    tab[i][j + k]->setEmpty(true);
                    tab[i][j + k]->setValue(0);
                    if (tab[i][j + k + 1]->getValue() == 2048){
                        win();
                    }
                    moved = true;
                    break;
                }
            }
        }
    }

    return moved;
}

/***
* METHOD 
*   canMove
* 
* Check if tab is full and any move is possible
*/
bool Grid::canMove() {
    if (free_tab.size() == 0) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 4; j++) {
                
                if (tab[i][j]->getValue() == tab[i + 1][j]->getValue()) {
                    cout << "true" << endl;
                    return true;
                }
            }
        }
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 3; j++) {
                if (tab[i][j]->getValue() == tab[i][j+1]->getValue()) {
                    return true;
                }
            }
        }
        cout << "false" << endl;
        return false;
    }
}


/***
* METHOD
*   restart
*/
bool Grid::restart() {
    cout << endl << endl << "RESTART ?" << endl << "YES (up)" << endl << "NO (down)";
    do {
        getDirection();
    } while (x == 0);

    if (x == 1)
        return true;
    if (x == -1)
        return false;
}

/***
* METHOD
*   endGame
*/
void Grid::endGame() {
    cout << "Good job !!!";
}

/***
* METHOD
*   win
*/
void Grid::win() {
    cout << "YOU WIN !!!!" << endl << endl;
    restart();
}



/***
* METHOD
*   compareTab
* 
* compare tab of integration tests
*/
/*bool Grid::compareTab(int end_tab[4][4]) {

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (tab[i][j]->getValue() != end_tab[i][i])
            {
                return false;
            }
        }
    }
    return true;
}*/