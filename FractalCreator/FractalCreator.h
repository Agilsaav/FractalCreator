#pragma once

#include <string>
#include <memory>
#include <cmath>
#include <vector>
#include <assert.h>

#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "RGB.h"

namespace caveofprogramming
{
	class FractalCreator
	{
	private:
		int const m_width;
		int const m_height;

		std::unique_ptr<int[]> m_histogram; //How many pixels have a number of iterations
		std::unique_ptr<int[]> m_fractal; //iterations of each pixel

		Bitmap m_bitmap;
		ZoomList m_zoomList;

		int m_total{ 0 };

		std::vector<RGB> m_colors;
		std::vector<int> m_ranges;
		std::vector<int> m_rangeTotals;

		bool m_bGotFirstRange{ false };

	private:
		void calculateIterations();
		void calculateTotalIterations();
		void calculateRangeTotals();
		void drawFractal();
		void writeBitmap(std::string name);
		int getRange(int iterations) const;

	public:
		FractalCreator(int width, int height);
		virtual ~FractalCreator();

		void addZoom(const Zoom& zoom);
		void addRange(double rangeEnd, const RGB& rgb);
		void run(std::string name);
	};
}

