#include <iostream>
#include "TimeSpan.h"
using namespace std;
int main() {
    TimeSpan ts = TimeSpan(50,50,50);
    ts.set_hours(60);

    int hh = ts.get_hours();
    ts.set_minutes(66);
    int mm = ts.get_minutes();
    int ss = ts.get_seconds();
    cout << ss;
    return 0;
}
