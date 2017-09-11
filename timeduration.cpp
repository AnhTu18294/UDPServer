#include "timeduration.h"

TimeDuration::TimeDuration()
{

}

void TimeDuration::start(){
    m_start = high_resolution_clock::now();
}

void TimeDuration::end(){
    m_end =high_resolution_clock::now();
    duration<double, std::milli> time_span = m_end - m_start;
    m_duration = (long)time_span.count();
}

void TimeDuration::printDuration(){
    std::cout << "Time duration = " << m_duration << std::endl;
}

long TimeDuration::getDuration(){
    return m_duration;
}


