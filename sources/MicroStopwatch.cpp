#include "MicroStopwatch.hpp"

//------------------------------------------------------------------------------------------
MicroStopwatch::MicroStopwatch()
//------------------------------------------------------------------------------------------
{
    QueryPerformanceFrequency(&m_liPerfFreq);
    Start();
}

//------------------------------------------------------------------------------------------
void MicroStopwatch::Start()
//------------------------------------------------------------------------------------------
{
    QueryPerformanceCounter(&m_liPerfStart);
}

//------------------------------------------------------------------------------------------
int MicroStopwatch::Now()
//------------------------------------------------------------------------------------------
{
    LARGE_INTEGER liPerfNow;
    QueryPerformanceCounter(&liPerfNow);
    return (((liPerfNow.QuadPart - m_liPerfStart.QuadPart) * 1000) / m_liPerfFreq.QuadPart);
}

//------------------------------------------------------------------------------------------
int MicroStopwatch::Time()
//------------------------------------------------------------------------------------------
{
    LARGE_INTEGER liPerfNow;
    QueryPerformanceCounter(&liPerfNow);
    return ((liPerfNow.QuadPart * 1000) / m_liPerfFreq.QuadPart);
}
