#pragma once
#include <vector>


class bacterium
{
private:
	int x;
	int y;
	int live_pointer;
	int command_register;
	bool live;

public:
	bacterium(int x, int y, int live_pointer)
	{
		this->x = x;
		this->y = y;
		this->live_pointer = live_pointer;
		this->command_register = 0;
		this->live = true;
	}
	void set_x(int x)		 {this->x = x;}
	void set_y(int y)		 {this->y = y;}
	int  get_x()			 {return this->x;}
	int  get_y()             {return this->y;}
	void set_live(bool live) { this->live = live; }
	void update();
	void set_live_pointer(int live_pointer)			{ this->live_pointer = live_pointer; };
	int get_live_pointer()							{ return this->live_pointer; };
	void set_command_register(int command_register) { this->command_register = command_register; }
	int get_command_register()						{ return this->command_register; }
	bool get_live()									{ return this->live; }



};

