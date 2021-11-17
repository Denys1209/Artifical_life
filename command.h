#pragma once
#include <random>
#include "bacterium.h"
#include "setting.h"
#include "food.h"
class command
{
public:
	virtual void do_something(bacterium &this_bact, char(&map)[HEIGHT][WIDTH], std::vector<std::unique_ptr<eat>> &all_food) = 0;
	virtual ~command() = default;
};
class command_move : public command 
{
private:
	int direction;
public:
	command_move() {direction = rand() % 8;}
	void do_something(bacterium &this_bact, char(&map)[HEIGHT][WIDTH], std::vector<std::unique_ptr<eat>> &all_food) override;
};
class command_grab : public command 
{
private:
	int direction;
public:
	command_grab() { direction = rand() % 8; }
	void do_something(bacterium &this_bact, char(&map)[HEIGHT][WIDTH], std::vector<std::unique_ptr<eat>> &all_food) override;
};
class command_go_to : public command
{
private:
	int direction;
public:
	command_go_to() { direction = rand() % HOW_MANY_COMMAND; }
	void do_something(bacterium &this_bact, char(&map)[HEIGHT][WIDTH], std::vector<std::unique_ptr<eat>> &all_food) override;
};
class command_photosynthesis : public command 
{
public:
	command_photosynthesis() = default;
	void do_something(bacterium &this_bact, char(&map)[HEIGHT][WIDTH], std::vector<std::unique_ptr<eat>> &all_food) override;
};
class command_non : public command 
{
public:
	command_non() = default;
	void do_something(bacterium &this_bact, char(&map)[HEIGHT][WIDTH], std::vector<std::unique_ptr<eat>> &all_food) override;
};