#ifdef __unix__
#include <unistd.h>
#include <sys/times.h>

using ClockType = decltype(times(nullptr));

struct tms start, end;
ClockType clock_start, clock_end;

#define START_TIME() \
clock_start = times(&start);

#define END_TIME() \
clock_end = times(&end);

#define DELTA_TIME() \
(double(end.tms_utime - start.tms_utime) / sysconf(_SC_CLK_TCK)) 

#elif defined(_WIN32) || defined(WIN32)
#include <windows.h>

using ClockType = LARGE_INTEGER;

ClockType clock_start, clock_end, clock_freq;

#define START_TIME() \
QueryPerformanceCounter(&clock_start);

#define END_TIME() \
QueryPerformanceCounter(&clock_end); \
QueryPerfomanceFrequency(&clock_freq);

#define DELTA_TIME() \
(double(clock_end.QuadPart - clock_start.QuadPart) / clock_freq.QuadPart);

#endif