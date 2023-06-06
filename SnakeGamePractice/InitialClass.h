#pragma once

const int XLine = 40;
const int YLine = 20;
class int2
{
public:
	int y;
	int x;
	int2()
	{
		x = 0;
		y = 0;
	}
	int2(int _y, int _x)
		: y(_y), x(_x)
	{
	}

	void operator=(int2 _other)
	{
		x = _other.x;
		y = _other.y;
	}

	void operator+=(int2 _other)
	{
		x += _other.x;
		y += _other.y;
	}

	void operator-=(int2 _other)
	{
		x -= _other.x;
		y -= _other.y;
	}

	int2 operator+(int2 _other)
	{
		int2 _return;
		_return.x = _return.x + _other.x;
		_return.y = _return.y + _other.y;
		return _return;
	}

	int2 operator-(int2 _other)
	{
		int2 _return;
		_return.x = _return.x - _other.x;
		_return.y = _return.y - _other.y;
		return _return;
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