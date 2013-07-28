#include <iostream>
#include "../FarSystem.h"

namespace Farsight
{
	void FarSystem::Report(const char* info)
	{
		std::cout << info << std::endl;
	}

	void FarSystem::ReportError(int e, const char* info)
	{
		std::cerr << "Error : " << e << ". " << info << std::endl;
	}
};