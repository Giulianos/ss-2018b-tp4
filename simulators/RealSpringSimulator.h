//
// Created by Giuliano Scaglioni on 11/11/2018.
//

#ifndef SS_TP4_REALSPRINGSIMULATOR_H
#define SS_TP4_REALSPRINGSIMULATOR_H

#include "Simulator.h"

class RealSpringSimulator : public Simulator
{
public:
  void run(ParamsManager& params) override;
};

#endif // SS_TP4_REALSPRINGSIMULATOR_H
