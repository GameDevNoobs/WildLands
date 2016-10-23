#include "Timer.h"

Timer::Timer() {
	QueryPerformanceFrequency(&frequency);
}

void Timer::Previous() {
	QueryPerformanceCounter(&prev);
}

void Timer::Current() {
	QueryPerformanceCounter(&cur);
}

double Timer::GetTimeInSec() {
	return (cur.QuadPart - prev.QuadPart) / (double)frequency.QuadPart;
}

double Timer::GetTimeInMillisec() {
	return (1.0e3*(cur.QuadPart - prev.QuadPart)) / (double)frequency.QuadPart;
}

