#pragma once


namespace caveofprogramming
{
	struct RGB
	{
		double r, g, b;

		RGB(double r, double g, double b);
		~RGB();
	};

	RGB operator-(const RGB& first, const RGB& second);
}

