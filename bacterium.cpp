#include "bacterium.h"

void bacterium::update()
{
	if (live_pointer <= 0) {
		this->live = false;
	}
	if (this->live) {
		this->command_register += 1;
		this->live_pointer -= 1;
	}
	
}
