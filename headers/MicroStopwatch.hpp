


#if !defined(_MICROSTOPWATCH_H)
#define _MICROSTOPWATCH_H


class MicroStopwatch {
public:
    void start();
    int Now();
private:
    LARGE_INTEGER m_liPerfFreq;
    LARGE_INTEGER m_liPerfStart;
};

#endif  //_MICROSTOPWATCH_H
