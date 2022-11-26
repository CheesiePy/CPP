#ifndef MULTIDGENERICSIM_SIMULATION_H
#define MULTIDGENERICSIM_SIMULATION_H
#include "Population.h"
#include "FileParse.h"
#include <cstdlib>

class Simulation {
public:
    Simulation(): ticks(0){};
    ~Simulation(){};
    void load(const string& filepath);
    void Simulator();

private:
    uint ticks;
};





#endif //MULTIDGENERICSIM_SIMULATION_H
