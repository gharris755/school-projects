#include "counting.h"

using namespace std;

//file that will have the timer functions that allows to be called to start and end the timer while it records the sorting time.
time_t getTime()
{
    return time(NULL);
}

double totalTime(time_t start, time_t end)
{
    return difftime(end, start);
}