#include <iostream>

#include "box.h"


/***
* CONSTRUCTOR
*	Box
*		_value		-> value of the box
*		x			-> position on x in tab
*		y			-> position on y in tab
*/
Box::Box(int _value, int x, int y) : value(_value)
{
	coordinate[0] = x;
	coordinate[1] = y;

	is_empty = true;
}

/***
* METHOD
*	getValue
*/
int Box::getValue()
{
	return value;
}

/***
* METHOD
*	setValue
*		_value		-> new value of the box
*/
void Box::setValue(int _value)
{
	value = _value;
}

/***
* METHOD
*	getCoord
*/
int* Box::getCoord()
{
	return coordinate;
}

/***
* METHOD
*   setCoord
*		x			-> new position on x on the tab
*		y			-> new position on y on the tab
*/
void Box::setCoord(int x, int y)
{
	coordinate[0] = x;
	coordinate[1] = y;
}

/***
* METHOD
*	getEmpty
*/
bool Box::getEmpty()
{
	return is_empty;
}

/***
* METHOD
*	setEmpty
*		_is_empty		-> change visibility of the box
*/
void Box::setEmpty(bool _is_empty)
{
	is_empty = _is_empty;
}

/***
* METHOD
*	displayInformation
* 
* Debug line to describe the caracteristics of boxes
*/
void Box::displayInformation()
{
	std::cout << "Case Valeur : " << value << std::endl << " De coordonnée : " << std::endl << "  x : " << coordinate[0] << std::endl << "  y : " << coordinate[1] << std::endl << "vide ? : " << is_empty;
}