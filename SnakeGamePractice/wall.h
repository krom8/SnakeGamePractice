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
		= { int2({20, 10}), int2({15, 4}), int2({2, 3}), int2({5, 5}), int2({11, 14}), 
		int2({33, 17}), int2({26, 11}), int2({38, 2}), int2({2, 15}), int2({7, 7})};

};

