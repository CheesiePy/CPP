#include <cmath>
#include "TimeSpan.h"

TimeSpan::TimeSpan(int hours, int minutes, int seconds):t(0){
    t += (seconds + minutes*60 + hours*60*60);
}

void TimeSpan::set_hours(int hr) {
     int temp;
     temp = floor((double)t/(60*60));
     t -= temp*60*60;
     t += hr*60*60;
}
void TimeSpan::set_minutes(int min) {
    if(min > 59)
        min = 59;
    if(min < 0)
        min = 0;
    int temp;
    temp = (int)t/(60);
    t -= temp*60;
    t += min*60;
}

void TimeSpan::set_seconds(int sec) {
    if(sec > 59)
        sec = 59;
    if(sec < 0)
        sec = 0;
    int temp = (int)t%10;
    t -= temp;
    t += sec;
}

int TimeSpan::get_hours() const {
    return (int)floor((double)t/(60*60))%24;
}

int TimeSpan::get_minutes() const {
    return (int)floor((double)t/60)%100;
}

int TimeSpan::get_seconds() const {
    int hh, mm;
    hh = get_hours();
    mm = get_minutes();
    return (int)t - hh*60*60 - mm*60;
}

int TimeSpan::total_hours() const {
    return 0;
}

int TimeSpan::total_minutes() const {
    return 0;
}

int TimeSpan::total_seconds() const {
    return 0;
}