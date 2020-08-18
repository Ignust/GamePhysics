#ifndef MICRO_STOPWATCH
#define MICRO_STOPWATCH

#include <windows.h>

class MicroStopwatch
{
public:
    MicroStopwatch();
    void Start();
    int Now();
    int Time();
private:
    LARGE_INTEGER m_liPerfFreq;
    LARGE_INTEGER m_liPerfStart;
};






#endif // MICRO_STOPWATCH
