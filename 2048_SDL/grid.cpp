#include "grid.h"
#include "box.h"
#include "input.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <iterator>

using namespace std;

using namespace std::this_thread;
using namespace std::chrono;

template <typename T>
void remove(std::vector<T>& v, size_t index) {
    v.erase(v.begin() + index);
}

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

//Grid::Grid(int _tab[4][4])
//{
//    i = 0;
//    j = 0;
//    k = 0;
//    x = 0;
//    y = 0;
//    moved = false;
//
//    for (int m = 0; m < 4; m++)
//    {
//        for (int n = 0; n < 4; n++)
//        {
//            Box* box = new Box(_tab[m][n], m, n);
//            tab[m][n] = box;
//
//            free_tab.push_back(box);
//        }
//    }
//}

void Grid::display()
{
    system("cls");

    for (i = 0; i < 5; i++) {

        for (k = 0; k < 4; k++) {
            cout << " ----";
            if (k == 3)
                cout << endl;
        }

        if (i < 4) {
            for (j = 0; j < 4; j++) {
                cout << "|";


                if (tab[i][j]->getValue() < 1000)
                    cout << " ";

                if (tab[i][j]->getValue() < 10)
                    cout << " ";

                cout << tab[i][j]->getValue();

                if (tab[i][j]->getValue() < 100)
                    cout << " ";

                if (j == 3)
                    cout << "|" << endl;

            }
        }
    }

    /*cout << endl << endl << endl << endl << endl;


    for (i = 0; i < 5; i++) {

        for (k = 0; k < 4; k++) {
            cout << " ----";
            if (k == 3)
                cout << endl;
        }

        if (i < 4) {
            for (j = 0; j < 4; j++) {



                cout << "|  " << tab[i][j]->getEmpty() << " ";
                if (j == 3)
                    cout << "|" << endl;


            }
        }
    }*/

}

int Grid::randomNum(int offset, int range) {
    int randNum = offset + (rand() % range);
    return randNum;
}


void Grid::addBox()
{
    int randValue = randomNum(1, 2);
    randValue = randValue * 2;
    int randBox = randomNum(0, free_tab.size());
    
    free_tab[randBox]->setValue(randValue);
    free_tab[randBox]->setEmpty(false);

    remove(free_tab, randBox);
}

void Grid::debut()
{
    for (i = 0; i < 2; i++) {
        addBox();
    }
}

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
    //cout << direction[0] << endl << direction[1] << endl;

    clearTab();
}

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

void Grid::endGame() {
    cout << "Good job !!!";
}

void Grid::win() {
    cout << "YOU WIN !!!!" << endl << endl;
    restart();
}



//Test
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