#pragma once

namespace Farsight
{
	class TimeSpan
	{
	protected:
		long long nanoseconds;

	public:
		#pragma region Properties
		
		static const long long NanosecondsPerDay = 86400000000000;
		static const long long NanosecondsPerHour = 3600000000000;
		static const long long NanosecondsPerMillisecond = 10000000;
		static const long long NanosecondsPerMinute = 60000000000;
		static const long long NanosecondsPerSecond = 1000000000;

		static const TimeSpan MaxValue;
		static const TimeSpan MinValue;
		static const TimeSpan Zero;

		#pragma endregion
		#pragma region Constructors

		TimeSpan(const long long nanoseconds);
		TimeSpan(const int seconds, const int milliseconds);

		#pragma endregion
		#pragma region Operators

		TimeSpan operator+(const TimeSpan &t);
		TimeSpan operator-();
		TimeSpan operator-(const TimeSpan &t);
		bool operator==(const TimeSpan &t);
		bool operator!=(const TimeSpan &t);
		bool operator<(const TimeSpan &t);
		bool operator<=(const TimeSpan &t);
		bool operator>(const TimeSpan &t);
		bool operator>=(const TimeSpan &t);

		#pragma endregion
		#pragma region Public Methods

		int GetDays() const;
		int GetHours() const;
		int GetMilliseconds() const;
		int GetMinutes() const;
		int GetSeconds() const;
		long long GetNanoseconds() const;
		double GetTotalDays() const;
		double GetTotalHours() const;
		double GetTotalMilliseconds() const;
		double GetTotalMinutes() const;
		double GetTotalSeconds() const;

		#pragma endregion
	};
};