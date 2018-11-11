//
// Created by Giuliano Scaglioni on 11/11/2018.
//

#ifndef SS_TP4_REALSPRING_H
#define SS_TP4_REALSPRING_H

#include "../forces/Force.h"
#include "../integrators/Integrator.h"
#include "../observers/Observer.h"
#include "Body.h"

class RealSpring
{
  std::list<Observer*> observers;
  Body mass = Body(1, 0, -0.714, 0, 0.3, 70);
  double current_time;
  double dampening_coefficient;
  double angular_frequency;

  void update_mass_position();

public:
  RealSpring();
  void simulate_step(double dt);
  void add_observer(Observer* observer);
  void end_simulation();
};

#endif // SS_TP4_REALSPRING_H
