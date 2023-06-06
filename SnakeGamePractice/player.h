#pragma once
#include "InitialClass.h"
#include <list>
class piece;
class wall;
class player
{
public:
	std::list<int2> player_list;

	void get_input(piece& _piece, wall& _wall);

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
		return *this;
	}


private:
	int2 MovePos = int2({ 0, 1 });
	bool live = true;
};

