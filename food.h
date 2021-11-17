#pragma once
#include <random>
#include "setting.h"
#include "bacterium.h"
class eat 
{
public:

	void relocation();
	bool crossing(int y_crossing, int x_crossing);
	virtual void effect(bacterium &bact);
	int get_x() { return this->x; }
	int get_y() { return this->y; };
	int get_writing_value() { return this->writing_value; }
	char get_skin() { return this->skin; };
	eat(int writing_value, char skin);
	eat(int x, int y, int writing_value, char skin);
	~eat() {};
private:
	int x;
	int y;
	int writing_value;
	char skin;
};
class food :public eat
{
public:
	food(int writing_value, char skin) : eat(writing_value, skin) {};
	food(int x, int y, int writing_value, char skin) : eat(x, y, writing_value, skin) {};
	void effect(bacterium &bact);

	~food() {};


};
class poison : public eat 
{

public:
	poison(int writing_value, char skin) :eat(writing_value, skin){};
	void effect(bacterium &bact);
};

