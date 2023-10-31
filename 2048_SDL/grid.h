#include <vector>

class Box;

class Grid
{
private:
	int i;
	int j;
	int k;
	bool moved;

public:
	int x, y;

	Box* tab[4][4];
	std::vector<Box*> free_tab;

	Grid();
	//Grid(int _tab[4][4]);

	void display();
	int randomNum(int offset, int range);
	void addBox();
	void debut();
	void clearTab();

	void getDirection();
	void movement();
	bool moveUp();
	bool moveDown();
	bool moveLeft();
	bool moveRight();

	bool canMove();
	bool restart();
	void endGame();
	void win();

	bool compareTab(int end_tab[4][4]);
};