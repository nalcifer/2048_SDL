#include <vector>

class Box;

class Grid
{
private:
	int i;
	int j;
	int k;

public:
	int x, y;

	Box* tab[4][4];
	std::vector<Box*> free_tab;

	Grid();

	void display();
	int randomNum(int offset, int range);
	void addBox();
	void debut();
	void getDirection();
	void movement();
	void clearTab();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

};