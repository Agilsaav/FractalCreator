#pragma once

#include <cstdint>

#pragma pack(push,2)
namespace caveofprogramming
{
	struct BitmapFileHeader
	{
		char header[2]{ 'B','M' };
		std::int32_t fileSize;
		std::int32_t reserved{ 0 };
		std::int32_t dataOffset;
	};
}
#pragma pack(pop)