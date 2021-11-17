#include "food.h"
void eat::relocation()
{
	this->x = rand() % WIDTH;
	this->y = rand() % HEIGHT;
}

bool eat::crossing(int y_crossing, int x_crossing)
{
	if (this->x == x_crossing && this->y == y_crossing) {
		return true;
	}
	else 
	{
		return false;
	}
}

void eat::effect(bacterium & bact)
{
	bact.set_live_pointer(bact.get_live_pointer() + this->writing_value);
}

eat::eat(int writing_value, char skin)
{
	this->relocation();
	this->writing_value = writing_value;
	this->skin = skin;

}

eat::eat(int x, int y, int writing_value, char skin)
{
	this->x = x;
	this->y = y;
	this->writing_value = writing_value;
	this->skin = skin;
}

void poison::effect(bacterium & bact)
{
	bact.set_live_pointer(bact.get_live_pointer() - this->get_writing_value());
}
void food::effect(bacterium & bact)
{
	bact.set_live_pointer(bact.get_live_pointer() + this->get_writing_value());
}
