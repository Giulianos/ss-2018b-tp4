//
// Created by Giuliano Scaglioni on 05/11/2018.
//

#ifndef SS_TP4_BEEMAN_H
#define SS_TP4_BEEMAN_H

#include "Integrator.h"

class Beeman : public Integrator
{
public:
  void integrate(Body& b, Force* f, double dt) override;
};

#endif // SS_TP4_BEEMAN_H
