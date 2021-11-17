#pragma once
#include <iostream>
#include "command.h"
class fabric_command
{
public:
	virtual std::unique_ptr<command> make_command() = 0;
	virtual ~fabric_command() {};
};

class fabric_command_move : public fabric_command
{
public:
	std::unique_ptr<command> make_command() override;
	~fabric_command_move() {};
};
class fabric_command_grab : public fabric_command
{
public:
	std::unique_ptr<command> make_command() override;
	~fabric_command_grab() {};
};
class fabric_command_go_to : public fabric_command
{
public:
	std::unique_ptr<command> make_command() override;
	~fabric_command_go_to() {};
};
class fabric_command_photosynthesis : public fabric_command
{
public:
	std::unique_ptr<command> make_command() override;
	~fabric_command_photosynthesis() {};
};
class fabric_command_non : public fabric_command
{
public:
	std::unique_ptr<command> make_command() override;
	~fabric_command_non() {};
};



