#include "fabric_command.h"



std::unique_ptr<command> fabric_command_move::make_command()
{
	std::unique_ptr<command> i = std::make_unique<command_move>();
	return i;
}

std::unique_ptr<command> fabric_command_grab::make_command()
{
	return std::unique_ptr<command>(std::make_unique<command_grab>());
}
std::unique_ptr<command> fabric_command_go_to::make_command()
{
	return std::unique_ptr<command_go_to>(std::make_unique<command_go_to>());
}
std::unique_ptr<command> fabric_command_photosynthesis::make_command() 
{
	return std::unique_ptr<command_photosynthesis>(std::make_unique<command_photosynthesis>());
}
std::unique_ptr<command> fabric_command_non::make_command()
{
	return std::unique_ptr<command_non>(std::make_unique<command_non>());
}
