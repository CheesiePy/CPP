//
// Created by Mai on 1/16/2022.
//

#include <sstream>
#include "Simulation.h"


void Simulation::load(const string& filepath) {
    FileParse parser;
    uint psize, ssize, dsize;
    parser.load(filepath,psize, ssize, dsize,ticks);
    double** graph = new double*[psize];
    for(uint i = 0; i < psize; i++)
    {
        graph[i] = new double[ssize];
    }

    parser.load(filepath, graph, psize, ssize);
    POPULATION<double> p = POPULATION<double>(psize, ssize, dsize, graph);


    p.setFunc(psize);
    p.RankAndSort();
    for(uint i = 0 ; i < ticks; i++ ){
        p.Evolve();
    }

    parser.Write("output.dat", p);



}

