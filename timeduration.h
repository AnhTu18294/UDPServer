#ifndef TIMEDURATION_H
#define TIMEDURATION_H
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std::chrono;

class TimeDuration
{
public:
    TimeDuration();
    void start();
    void end();
    long getDuration();
    void printDuration();

private:
    high_resolution_clock::time_point m_start, m_end;
    long m_duration;

};

#endif // TIME_H
