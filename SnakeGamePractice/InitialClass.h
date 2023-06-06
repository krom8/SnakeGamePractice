#pragma once

const int XLine = 40;
const int YLine = 20;
class int2
{
public:
	int x;
	int y;
	int2()
	{
		x = 0;
		y = 0;
	}
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

	void operator-(int2 _other)
	{
		x -= _other.x;
		y -= _other.y;
	}

	int2& operator*()
	{
		return *this;
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
protected:

};