#include "pch.h"
#include <fstream>

#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace caveofprogramming;

namespace caveofprogramming
{

	Bitmap::Bitmap(int width, int height)
		:m_width(width), m_height(height), m_pPixels(new std::uint8_t[3 * width*height]{0})
	{
	}

	Bitmap::~Bitmap()
	{
	}

	bool Bitmap::write(std::string fileName)
	{
		BitmapFileHeader fileHeader;
		BitmapInfoHeader infoHeader;

		fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + 3 * m_width*m_height;
		fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

		infoHeader.width = m_width;
		infoHeader.height = m_height;

		std::ofstream file;
		file.open(fileName, std::ios::out|std::ios::binary);

		if (!file) return false;

		file.write((char*)&fileHeader, sizeof(fileHeader));
		file.write((char*)&infoHeader, sizeof(infoHeader));
		file.write((char*)m_pPixels.get(), 3 * m_width*m_height);

		file.close();
		if (!file) return false;

		return true;
	}

	void Bitmap::setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue)
	{
		std::uint8_t *pPixel = m_pPixels.get();
		pPixel += ((3*y) * m_width) + 3*x;


		//reverse order because of the format
		pPixel[0] = blue;
		pPixel[1] = green;
		pPixel[2] = red;
	}
}
