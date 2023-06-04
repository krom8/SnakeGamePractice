#pragma once

class int2
{
public:
	int2(int _x, int _y)
		: x(_x), y(_y)
	{
	}

	void operator=(int2 _other)
	{
		x = _other.x;
		y = _other.y;
	}

	void operator+(int2 _other)
	{
		x += _other.x;
		y += _other.y;
	}

	bool operator==(int2 _other)
	{
		if (x == _other.x && y == _other.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	int x;
	int y;
};

