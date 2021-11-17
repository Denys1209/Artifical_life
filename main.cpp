#include <iostream>
#include <vector>
#include <windows.h>
#include <random>
#include <Ctime>
#include "fabric_command.h"
#include "setting.h"
#include "food.h"
#include <algorithm>

char map[HEIGHT][WIDTH];
using u_p_e = std::unique_ptr<eat>;
using u_p_c = std::unique_ptr<command>;

static fabric_command_move factory_move;
static fabric_command_grab factory_grab;
static fabric_command_go_to factory_go_to;
static fabric_command_photosynthesis factory_photosynthesis;
static fabric_command_non factory_non;
std::vector<std::vector<u_p_c>> all_command;
std::vector<bacterium> all_bacteriums;
std::vector<u_p_e> all_food;
std::unique_ptr<command> make_random_command() 
{
	int rand_number = rand() % HOW_MANY_COMMAND_EXIST;
	if (rand_number == NUMBER_COMMAND_MOVE) {
		return factory_move.make_command();
	}
	else if (rand_number == NUMBER_COMMAND_GRAB) {
		return factory_grab.make_command();
	}
	else if (rand_number == NUMBER_COMMAND_GO_TO) {
		return factory_go_to.make_command();
	}
	else if (rand_number == NUMBER_COMMAND_PHOTOSYNTHESIS) {
		return factory_photosynthesis.make_command();
	}
	return factory_non.make_command();
}
void creat_list_command(std::vector<std::vector<u_p_c>> &all_command)
{
	std::srand(time(NULL));
	for (int a = 0; a < ALL_BACTERIUMS_START; ++a) {
		all_command.push_back(std::vector<std::unique_ptr<command>>());
		for (int i = 0; i < HOW_MANY_COMMAND; ++i)
		{
			
			
			all_command[a].push_back(make_random_command());
			
		}
	}
}
void creat_list_food(std::vector<u_p_e> &all_food)
{
	for (int i = 0; i < HOW_MANY_FOODS; ++i) 
	{
		all_food.push_back(std::make_unique<food>(HOW_MANY_FOOD_GET_LIVE_POINTERS, FOOD_SKIN));
	}
	for (int i = 0; i < HOW_MANY_POISON; ++i)
	{
		all_food.push_back(std::make_unique<poison>(HOW_MUCH_POISON_DANAGE, POISON_SKIN));
	}
}
void creat_all_bacterium(std::vector<bacterium> &all_bacteriums)
{
	std::srand(time(NULL));
	for (int i = 0; i < ALL_BACTERIUMS_START; ++i)
	{
		all_bacteriums.push_back(bacterium(rand() % HEIGHT, rand() % WIDTH, HOW_MANU_LIVE_POINTERS_HAVE_BACTERIUM));
	}
}
void create_world(char (&map)[HEIGHT][WIDTH])
{
	for (int i = 0; i < HEIGHT; ++i) 
	{
		for (int a = 0; a < WIDTH; ++a) 
		{
			map[i][a] = ' ';
		}
	}
}
void print_map(char(&map)[HEIGHT][WIDTH])
{
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int a = 0; a < WIDTH; ++a)
		{
			std::cout << map[i][a];
		}
		std::cout << std::endl;
	}
}
void update_map(char(&map)[HEIGHT][WIDTH], std::vector<bacterium> &all_bacteriums, std::vector<u_p_e> &all_food)
{
	for (auto &f : all_food)
	{
		map[(*f).get_y()][(*f).get_x()] = (*f).get_skin();
	}
	for (auto &bact : all_bacteriums) 
	{
		if (bact.get_live()) {
			map[bact.get_y()][bact.get_x()] = BACTERIUM_SKIN;
		}
		
	}
	
}
void create_a_new_generation(std::vector<bacterium> &all_bacteriums, std::vector<std::vector<u_p_c>> &all_command)
{
	std::vector<int> command_count;
	int count_command = 0;
	for (int i = 0; i < ALL_BACTERIUMS_START; ++i) 
	{
		if (all_bacteriums[i].get_live()) 
		{
			command_count.push_back(i);
		}
	}
	for (int a = 0; a < command_count.size(); ++a) {
		for (int i = int(all_command.size() / command_count.size()) * a; i < int(all_command.size()/ command_count.size())*(a+1); ++i)
		{
			if (!(i >= all_command.size())) {
				if (std::find(command_count.begin(), command_count.end(), i) == command_count.end()) {
					for (int f = 0; f < HOW_MANY_COMMAND; ++f) {
						*(all_command[i][f]) = *(all_command[command_count[a]][f]);
					}
				}
			}
		}
	}
	for (int a = 0; a < int(ALL_BACTERIUMS_START / 2); ++a)
	{
		all_command[rand() % ALL_BACTERIUMS_START][rand() % HOW_MANY_COMMAND] = make_random_command();
	}
	for (int i = 0; i < all_bacteriums.size(); ++i) 
	{
		all_bacteriums[i].set_live_pointer(HOW_MANU_LIVE_POINTERS_HAVE_BACTERIUM);
		all_bacteriums[i].set_live(true);
	}
}
void update(std::vector<bacterium> &all_bacteriums, std::vector<std::vector<u_p_c>> &all_command, std::vector<u_p_e> &all_food)
{
	int command_registe_for_bacter = 0;
	int count_deat_bacters = 0;
	for (auto &bacterium : all_bacteriums) 
	{
		if (count_deat_bacters >= HOW_MANY_BACTERS_NEED_TO_DIED_A_NEW_GENERATION) {
			create_a_new_generation(all_bacteriums, all_command);
			break;
		}
		if (!bacterium.get_live())
		{
			++command_registe_for_bacter;
			++count_deat_bacters;
			
			continue;
		}
		
		(*all_command[command_registe_for_bacter][bacterium.get_command_register()]).do_something(bacterium, map, all_food);
		bacterium.update();
		if (HOW_MANY_COMMAND <= bacterium.get_command_register()) 
		{
			bacterium.set_command_register(0);
		}
		if (bacterium.get_x()>= WIDTH)
		{
			bacterium.set_x(0);
		}
		else if(bacterium.get_x() <0 )
		{
			bacterium.set_x(WIDTH-1);
		}
		if (bacterium.get_y() >= HEIGHT)
		{
			bacterium.set_y(0);
		}
		else if (bacterium.get_y() < 0)
		{
			bacterium.set_y(HEIGHT - 1);
		}
		for (auto &f : all_food)
		{
			if ((*f).crossing(bacterium.get_y(), bacterium.get_x()))
			{
				(*f).effect(bacterium);
				(*f).relocation();
			}
		}
		++command_registe_for_bacter;

	}
}



int main() 
{

	int count_generations = 0;
	create_world(map);
	creat_list_command(all_command);
	creat_all_bacterium(all_bacteriums);
	creat_list_food(all_food);
	while (true) {
		count_generations++;
		update(all_bacteriums, all_command, all_food);
		update_map(map, all_bacteriums, all_food);
		print_map(map);
		create_world(map);
		std::cout << count_generations << std::endl;
		Sleep(1);
		system("cls");
	}
	return 0;
}


