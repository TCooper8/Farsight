#include <iostream>
#include <climits>
#include <chrono>
#include <ctime>
#include "TimeSpan.h"

namespace Farsight
{
	const TimeSpan TimeSpan::MaxValue (LLONG_MAX);
	const TimeSpan TimeSpan::MinValue (LLONG_MIN);
	const TimeSpan TimeSpan::Zero (0);

	#pragma region Constructors

	TimeSpan::TimeSpan(const long long nanoseconds)
		: nanoseconds(nanoseconds)
	{ }

	TimeSpan::TimeSpan(const int seconds, const int milliseconds)
		: nanoseconds(seconds * NanosecondsPerSecond + milliseconds * NanosecondsPerMillisecond)
	{ }

	#pragma endregion
	#pragma region Operators

	TimeSpan TimeSpan::operator+(const TimeSpan &t)
	{
		return TimeSpan(nanoseconds + t.GetNanoseconds());
	}

	TimeSpan TimeSpan::operator-()
	{
		return TimeSpan(-nanoseconds);
	}

	TimeSpan TimeSpan::operator-(const TimeSpan &t)
	{
		return TimeSpan(nanoseconds - t.GetNanoseconds());
	}

	bool TimeSpan::operator==(const TimeSpan &t)
	{
		return (nanoseconds == t.GetNanoseconds());
	}

	bool TimeSpan::operator!=(const TimeSpan &t)
	{
		return !(*this == t);
	}

	bool TimeSpan::operator<(const TimeSpan &t)
	{
		return (nanoseconds < t.GetNanoseconds());
	}

	bool TimeSpan::operator<=(const TimeSpan &t)
	{
		return (nanoseconds <= t.GetNanoseconds());
	}

	bool TimeSpan::operator>(const TimeSpan &t)
	{
		return (nanoseconds > t.GetNanoseconds());
	}

	bool TimeSpan::operator>=(const TimeSpan &t)
	{
		return (nanoseconds >= t.GetNanoseconds());
	}

	#pragma endregion
	#pragma region Public Methods

	int TimeSpan::GetDays() const
	{
		return (nanoseconds / NanosecondsPerDay) % 365;
	}

	int TimeSpan::GetHours() const
	{
		return (nanoseconds / NanosecondsPerHour) % 24;
	}

	int TimeSpan::GetMilliseconds() const
	{
		return (nanoseconds / NanosecondsPerMillisecond) % 1000;
	}

	int TimeSpan::GetMinutes() const
	{
		return (nanoseconds / NanosecondsPerMinute) % 60;
	}

	int TimeSpan::GetSeconds() const
	{
		return (nanoseconds / NanosecondsPerSecond) % 60;
	}

	long long TimeSpan::GetNanoseconds() const
	{
		return nanoseconds;
	}

	double TimeSpan::GetTotalDays() const
	{
		return (nanoseconds / NanosecondsPerDay) % 365;
	}

	double TimeSpan::GetTotalHours() const
	{
		return (nanoseconds / NanosecondsPerHour) % 24;
	}

	#pragma endregion

	namespace FarSystem
	{
		const std::chrono::high_resolution_clock::time_point InitialTime = std::chrono::high_resolution_clock::now();

		TimeSpan GetSystemTime()
		{
			auto tf = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(tf - InitialTime).count();

			return TimeSpan(duration);
		}
	};
};