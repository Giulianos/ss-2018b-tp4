//
// Created by Giuliano Scaglioni on 11/11/2018.
//

#ifndef SS_TP4_SPACESIMULATOR_H
#define SS_TP4_SPACESIMULATOR_H


#include "Simulator.h"

class SpaceSimulator : public Simulator {
public:
    void run(ParamsManager &params) override;
};


#endif //SS_TP4_SPACESIMULATOR_H
