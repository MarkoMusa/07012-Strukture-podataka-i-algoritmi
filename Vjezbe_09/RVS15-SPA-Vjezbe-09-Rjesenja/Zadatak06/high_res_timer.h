#include <windows.h>

struct hr_timer {
	LARGE_INTEGER start_time;
	LARGE_INTEGER stop_time;
};

void start_hr_timer(hr_timer &timer);
void stop_hr_timer(hr_timer &timer);
double get_elapsed_time_microsec(const hr_timer &timer);
