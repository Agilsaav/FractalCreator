#pragma once

#include <string>
#include <cstdint>

namespace caveofprogramming
{
	class Bitmap
	{
	private:
		int m_width{0};
		int m_height{0};
		std::unique_ptr<std::uint8_t[]> m_pPixels{ nullptr };

	public:
		Bitmap(int width, int height);
		~Bitmap();

		bool write(std::string fileName);
		void setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue);
	};

}

