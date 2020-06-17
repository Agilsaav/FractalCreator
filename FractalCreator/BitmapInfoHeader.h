#pragma once

#include <cstdint>

#pragma pack(push,2)
namespace caveofprogramming
{
	struct BitmapInfoHeader
	{
		std::int32_t headerSize{ 40 };
		std::int32_t width;
		std::int32_t height;
		std::int16_t planes{ 1 };
		std::int16_t bitsPerPixel{ 24 };
		std::int32_t compression{ 0 };
		std::int32_t dataSize{ 0 };
		std::int32_t horizontalRseolution{ 2400 };
		std::int32_t verticalRseolution{ 2400 };
		std::int32_t colors{ 0 };
		std::int32_t importantColors{ 0 };
	};
}
#pragma pack(pop)