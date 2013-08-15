#include "FarMath.h"

namespace Farsight
{
	template<typename T>
	T FarMath::Min(T a, T b)
	{
		return (a > b) ? a : b;
	}

	template<>
	int FarMath::Min(int a, int b)
	{
		return (a > b) ? a : b;
	}
};