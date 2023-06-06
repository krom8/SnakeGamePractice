#pragma once
#include "InitialClass.h"
#include <array>

class piece : public int2
{
public:
	piece()
	{
	}
	piece(int _y, int _x)
	{
		x = _x;
		y = _y;
	}

	piece& operator*()
	{
		return *this;
	}
	
	int get_current()
	{
		return current;
	}

	int another_current()
	{
		current += 1;
		return current;
	}

	std::array<int2, 10> get_array()
	{
		return piece_array;
	}


private:
	std::array<int2, 10> piece_array = { int2({16, 20}), int2({4, 17}), int2({1, 2}), int2({15, 5}), int2({14, 13}),
		int2({15, 31}), int2({10, 22}), int2({2, 33}), int2({17, 2}), int2({8, 7}) };
	int current = 0;

};

