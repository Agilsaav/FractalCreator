#pragma once


namespace caveofprogramming
{
	struct Zoom
	{
		int x{ 0 }, y{ 0 };
		double scale{ 0.0 };

		Zoom(int x, int y, double scale)
			:x(x), y(y), scale(scale){};
		~Zoom() {};
	};
}


