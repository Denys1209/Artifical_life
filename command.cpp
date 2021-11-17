#include "command.h"

void command_move::do_something(bacterium & this_bact, char(&map)[HEIGHT][WIDTH], std::vector<std::unique_ptr<eat>> &all_food)
{
	switch (this->direction)
	{
	case 0:
		this_bact.set_x(this_bact.get_x()-1);
		this_bact.set_y(this_bact.get_y()-1);
		break;
	case 1:
		this_bact.set_y(this_bact.get_y() - 1);
		break;
	case 2:
		this_bact.set_x(this_bact.get_x() + 1);
		this_bact.set_y(this_bact.get_y() - 1);
		break;
	case 3:
		this_bact.set_x(this_bact.get_x() + 1);
		this_bact.set_y(this_bact.get_y() - 1);
		break;
	case 4:
		this_bact.set_x(this_bact.get_x() - 1);
		break;
	case 5:
		this_bact.set_x(this_bact.get_x() + 1);

		break;
	case 6:
		this_bact.set_x(this_bact.get_x() - 1);
		this_bact.set_y(this_bact.get_y() + 1);
		break;
	case 7:
		this_bact.set_x(this_bact.get_x() + 1);
		this_bact.set_y(this_bact.get_y() + 1);
		break;
	default:
		break;
	}
}

void command_grab::do_something(bacterium & this_bact, char(&map)[HEIGHT][WIDTH], std::vector<std::unique_ptr<eat>> &all_food)
{
	for (std::unique_ptr<eat> &f : all_food) {

		switch (this->direction)
		{
		case 0:

			if ((*f).crossing(this_bact.get_y() - 1, this_bact.get_x() - 1))
			{
				this_bact.set_live_pointer(this_bact.get_live_pointer() + (*f).get_writing_value());
				(*f).relocation();
			}

			break;
		case 1:
			if ((*f).crossing(this_bact.get_y() - 1, this_bact.get_x()))
			{
				this_bact.set_live_pointer(this_bact.get_live_pointer() + (*f).get_writing_value());
				(*f).relocation();

			}

			break;
		case 2:
			if ((*f).crossing(this_bact.get_y() - 1, this_bact.get_x() + 1))
			{
				this_bact.set_live_pointer(this_bact.get_live_pointer() + (*f).get_writing_value());
				(*f).relocation();
			}
			break;
		case 3:
			if ((*f).crossing(this_bact.get_y() - 1, this_bact.get_x() + 1))
			{
				this_bact.set_live_pointer(this_bact.get_live_pointer() + (*f).get_writing_value());
				(*f).relocation();

			}
			break;
		case 4:
			if ((*f).crossing(this_bact.get_y(), this_bact.get_x() - 1))
			{
				this_bact.set_live_pointer(this_bact.get_live_pointer() + (*f).get_writing_value());
				(*f).relocation();

			}
			break;
		case 5:
			if ((*f).crossing(this_bact.get_y() - 1, this_bact.get_x() + 1))
			{
				this_bact.set_live_pointer(this_bact.get_live_pointer() + (*f).get_writing_value());
				(*f).relocation();


			}


			break;
		case 6:

			if ((*f).crossing(this_bact.get_y() + 1, this_bact.get_x() - 1))
			{
				this_bact.set_live_pointer(this_bact.get_live_pointer() + (*f).get_writing_value());
				(*f).relocation();

			}

			break;
		case 7:

			if ((*f).crossing(this_bact.get_y() + 1, this_bact.get_x() + 1))
			{
				this_bact.set_live_pointer(this_bact.get_live_pointer() + (*f).get_writing_value());
				(*f).relocation();

			}

			break;
		default:
			break;
		}
	}
}

void command_go_to::do_something(bacterium & this_bact, char(&map)[HEIGHT][WIDTH], std::vector<std::unique_ptr<eat>>& all_food)
{
	int com = this_bact.get_command_register() + this->direction;
	this_bact.set_command_register(com%HOW_MANY_COMMAND);
}

void command_photosynthesis::do_something(bacterium & this_bact, char(&map)[HEIGHT][WIDTH], std::vector<std::unique_ptr<eat>>& all_food)
{
	this_bact.set_live_pointer(this_bact.get_live_pointer()+ HOW_MANY_LIVE_POINTERS_GIVE_PHOTOSYNTHESIS);
}

void command_non::do_something(bacterium & this_bact, char(&map)[HEIGHT][WIDTH], std::vector<std::unique_ptr<eat>>& all_food)
{
	
}
