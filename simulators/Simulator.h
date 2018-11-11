//
// Created by Giuliano Scaglioni on 11/11/2018.
//

#ifndef SS_TP4_SIMULATOR_H
#define SS_TP4_SIMULATOR_H


#include "../utils/ParamsManager.h"

class Simulator {
public:
    virtual void run(ParamsManager& params) = 0;
};


#endif //SS_TP4_SIMULATOR_H
