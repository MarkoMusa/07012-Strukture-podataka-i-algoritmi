#include "high_res_timer.h"

void start_hr_timer(hr_timer &timer) {
	QueryPerformanceCounter(&timer.start_time);
}

void stop_hr_timer(hr_timer &timer) {
	QueryPerformanceCounter(&timer.stop_time);
}

double get_elapsed_time_microsec(const hr_timer &timer) {
	LARGE_INTEGER frequency;
	LARGE_INTEGER time;
	time.QuadPart = timer.stop_time.QuadPart - timer.start_time.QuadPart;
	
	QueryPerformanceFrequency(&frequency);
	time.QuadPart *= 1000000;
	time.QuadPart /= frequency.QuadPart;
	
	return (double)time.QuadPart;
}
