class Box
{
public:
	int value;
	int coordinate[2];
	bool is_empty;

	Box(int _value, int x, int y);

	int getValue();

	void setValue(int _value);

	int* getCoord();

	void setCoord(int x, int y);

	bool getEmpty();

	void setEmpty(bool _is_empty);

	void displayInformation();

};