#pragma once
#include "InitialClass.h"
#include <list>

class piece
{
public:
	std::list<int2> piece_list;

	piece& operator*()
	{
		return;
	}
};

