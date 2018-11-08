//
// Created by Giuliano Scaglioni on 05/11/2018.
//

#ifndef SS_TP4_SPACE_H
#define SS_TP4_SPACE_H

#include "../integrators/Beeman.h"
#include "../integrators/Integrator.h"
#include "../utils/LaunchSetup.h"
#include "Body.h"
#include "../observers/Observer.h"
#include <list>

class Space
{
  std::list<Body> bodies;
  std::list<Observer*> observers;
  LaunchSetup launch_setup;
  Integrator* integrator = new Beeman();
  double current_time;

public:
  Space(LaunchSetup& launch_setup);
  void simulate_step(double dt);
  void add_observer(Observer * observer);
  void end_simulation();
};

#endif // SS_TP4_SPACE_H
