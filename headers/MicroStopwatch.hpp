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

MicroStopwatch::MicroStopwatch()
{
    QueryPerformanceFrequency(&m_liPerfFreq);
    Start();
}

void MicroStopwatch::Start()
{
    QueryPerformanceCounter(&m_liPerfStart);
}

int MicroStopwatch::Now()
{

        LARGE_INTEGER liPerfNow;
        QueryPerformanceCounter(&liPerfNow);
    return (((liPerfNow.QuadPart - m_liPerfStart.QuadPart) * 1000) / m_liPerfFreq.QuadPart);
}

int MicroStopwatch::Time()
{
    LARGE_INTEGER liPerfNow;
    QueryPerformanceCounter(&liPerfNow);
    return ((liPerfNow.QuadPart * 1000) / m_liPerfFreq.QuadPart);
}






#endif // MICRO_STOPWATCH
