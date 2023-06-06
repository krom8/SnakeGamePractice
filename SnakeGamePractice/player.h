#pragma once
#include "InitialClass.h"
#include <list>
class piece;
class wall;
class player
{
public:
	
	player()
	{
		player_list.push_back(int2({ 10,20 }));
	}
	

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

	void move(piece& _piece, wall& _wall);

	void check_wall(wall& _wall);

	void check_piece(piece& _piece);
	void crash();
	std::list<int2> get_player_list()
	{
		return player_list;
	}



private:
	std::list<int2> player_list;
	int2 MovePos = int2({ 0, 1 });
	bool live = true;
};

