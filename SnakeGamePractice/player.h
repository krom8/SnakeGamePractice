#pragma once
#include "InitialClass.h"
#include <list>
class piece;
class player
{
public:
	std::list<int2> player_list;

	void get_input(piece& _piece);

	void Die()
	{
		live = false;
	}
	bool Checklive()
	{
		return live;
	}
	player& operator*()
	{
		return;
	}

private:
	bool live = true;
};

