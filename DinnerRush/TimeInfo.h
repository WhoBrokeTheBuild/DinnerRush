#pragma once

#ifndef TIME_INFO_H
#define TIME_INFO_H

class TimeInfo
{
public:

	TimeInfo(void) 
	{ }

	/// The total seconds that have elapsed since the program started
	double TotalSeconds;
	/// The total milliseconds that have elapsed since the program started
	double TotalMilliseconds;
	/// The seconds that have elapsed since the last update
	double ElapsedSeconds;
	/// The milliseconds that have elapsed since the last update
	double ElapsedMilliseconds;
	/// The measurement of time relative to the desired framerate.

	/**
	* The value will be at 1.0 when the program is running normally, > 1.0
	* when the program is running slowly, and < 1.0 when the program is
	* running fast
	*/
	double Delta;

}; // class TimeInfo

#endif // TIME_INFO_H