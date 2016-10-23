#ifndef TIMER_H
#define TIMER_H

#include <windows.h>

class Timer {
	LARGE_INTEGER prev;
	LARGE_INTEGER cur;
	LARGE_INTEGER frequency;
public:
	Timer();
	~Timer() {}
	void Previous();
	void Current();
	double GetTimeInSec();
	double GetTimeInMillisec();
};

#endif