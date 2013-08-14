#include <iostream>
#include <chrono>
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
	
	const std::chrono::high_resolution_clock::time_point InitialTime = std::chrono::high_resolution_clock::now();

	TimeSpan FarSystem::GetSystemTime()
	{
		auto tf = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(tf - InitialTime).count();

		return TimeSpan(duration);
	}
};