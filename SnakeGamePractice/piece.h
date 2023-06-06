#pragma once
#include "InitialClass.h"
#include <array>

class piece : public int2
{
public:
	piece()
	{
	}
	piece(int _x, int _y)
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
	std::array<int2, 10> piece_array = { int2({20, 16}), int2({17, 4}), int2({2, 1}), int2({5, 15}), int2({13, 14}),
		int2({31, 15}), int2({22, 10}), int2({33, 2}), int2({2, 17}), int2({7, 8}) };
	int current = 0;

};

