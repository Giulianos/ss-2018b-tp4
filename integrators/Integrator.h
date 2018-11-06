//
// Created by Giuliano Scaglioni on 05/11/2018.
//

#ifndef SS_TP4_INTEGRATOR_H
#define SS_TP4_INTEGRATOR_H

#include "../forces/Force.h"
#include "../types/Body.h"

class Integrator
{
public:
  virtual ~Integrator() = default;

  virtual void integrate(Body& b, Force* f, double dt) = 0;
};

#endif // SS_TP4_INTEGRATOR_H
