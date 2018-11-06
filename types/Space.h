//
// Created by Giuliano Scaglioni on 05/11/2018.
//

#ifndef SS_TP4_SPACE_H
#define SS_TP4_SPACE_H

#include "../integrators/Beeman.h"
#include "../integrators/Integrator.h"
#include "../utils/LaunchSetup.h"
#include "Body.h"
#include <list>

class Space
{
  std::list<Body> bodies;
  LaunchSetup launch_setup;
  Integrator* integrator = new Beeman();

public:
  Space(LaunchSetup& launch_setup);
  void simulate_step(double dt);
  void print_ovito(FILE* file) const;
};

#endif // SS_TP4_SPACE_H
