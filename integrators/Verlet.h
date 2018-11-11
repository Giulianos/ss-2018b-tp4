//
// Created by Giuliano Scaglioni on 11/11/2018.
//

#ifndef SS_TP4_VERLET_H
#define SS_TP4_VERLET_H

#include "Integrator.h"

class Verlet : public Integrator
{
public:
  void integrate(Body& b, Force* f, double dt) override;
};

#endif // SS_TP4_VERLET_H
