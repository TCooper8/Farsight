#pragma once

#include "FarSystem/TimeSpan.h"

namespace Farsight
{
	typedef __int8 int8;
	typedef __int16 int16;
	typedef __int32 int32;
	typedef __int64 int64;

	typedef unsigned __int8 uint8;
	typedef unsigned __int16 uint16;
	typedef unsigned __int32 uint32;
	typedef unsigned __int64 uint64;

	typedef unsigned int uint;
	typedef unsigned char uchar;
	typedef unsigned short ushort;
	typedef unsigned long ulong;


	namespace FarSystem
	{
		static void Report(const char* info);
		static void ReportError(int e, const char* info);
		static void RaiseException(const char* info) { }
	};
};