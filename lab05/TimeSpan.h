#ifndef LAB05ML_TIME_H
#define LAB05ML_TIME_H


#include <ctime>

class TimeSpan {
private:
    time_t t;
public:
    TimeSpan(int hours = 0,int minutes = 0, int seconds = 0);
    void set_hours(int hr); // set the total hours
    void set_minutes(int min); // set the minutes (0-59)
    void set_seconds(int sec); // set the seconds (0-59)
    int get_hours() const; // hour between 0-23
    int get_minutes() const; // minute between 0-59
    int get_seconds() const; // seconds between 0-59
    int total_hours() const; // total hours in the timespan
    int total_minutes() const; // total minutes in the timespan
    int total_seconds() const; // total seconds in the timespan
};


#endif //LAB05ML_TIME_H


