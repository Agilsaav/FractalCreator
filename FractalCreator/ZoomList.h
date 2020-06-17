#pragma once

#include <vector>
#include <utility>

#include "Zoom.h";

namespace caveofprogramming
{
	class ZoomList
	{
	private:
		int m_width{ 0 };
		int m_height{ 0 };

		double m_xCenter{ 0.0 };
		double m_yCenter{ 0.0 };
		double m_scale{ 1.0 };
		std::vector<Zoom> zooms;

	public:
		ZoomList(int width, int height);
		~ZoomList();

		void add(const Zoom& zoom);
		 std::pair<double, double> doZoom(int x, int y);
	};

}
