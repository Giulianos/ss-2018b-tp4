//
// Created by Giuliano Scaglioni on 11/11/2018.
//

#include "Spring.h"
#include "../forces/DampingForce.h"
#include "../forces/HookeForce.h"
#include "../forces/SumForce.h"
#include "../integrators/Beeman.h"
#include "../integrators/Verlet.h"
#include "../integrators/GearPredictorCorrector.h"

Spring::Spring()
{
  hooke_force = new HookeForce(1e4, mass);
  damping_force = new DampingForce(100, mass);
  integrator = new GearPredictorCorrector();
  current_time = 0;
}

void
Spring::simulate_step(double dt)
{
  std::list<Force*> forces;
  forces.push_front(hooke_force);
  forces.push_front(damping_force);
  Force* sum_force = new SumForce(forces);
  integrator->integrate(mass, sum_force, dt);
  mass.update();
  current_time += dt;
  std::list<Body> bodies;
  bodies.push_front(mass);
  for (Observer* obs : observers) {
    obs->inject_data(&bodies, current_time);
    obs->observe();
  }
}

void
Spring::add_observer(Observer* observer)
{
  observers.push_front(observer);
}

void
Spring::end_simulation()
{
  for (Observer* obs : observers) {
    obs->finalize_observer();
  }
}
