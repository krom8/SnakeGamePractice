#pragma once
#include "InitialClass.h"
#include <array>
class wall
{
public:
	std::array<int2, 10> get_wall()
	{
		return wall_array;
	}
	wall& operator*()
	{
		return *this;
	}
private:
	std::array<int2, 10> wall_array 
		= { int2({10, 20}), int2({4, 15}), int2({3, 2}), int2({5, 5}), int2({14, 11}), 
		int2({17, 33}), int2({11, 26}), int2({2, 38}), int2({15, 2}), int2({7, 7})};

};

