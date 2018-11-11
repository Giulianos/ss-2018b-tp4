//
// Created by Giuliano Scaglioni on 11/11/2018.
//

#include "RealSpring.h"
#include <cmath>

RealSpring::RealSpring()
{
  double gamma = 100;
  double k = 1e4;
  current_time = 0;
  dampening_coefficient = -gamma / (mass.get_mass() * 2);
  angular_frequency =
    sqrt(k / mass.get_mass() - pow(gamma, 2) / (4 * pow(mass.get_mass(), 2)));
}

void
RealSpring::simulate_step(double dt)
{
  update_mass_position();
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
RealSpring::add_observer(Observer* observer)
{
  observers.push_front(observer);
}

void
RealSpring::end_simulation()
{
  for (Observer* obs : observers) {
    obs->finalize_observer();
  }
}

void
RealSpring::update_mass_position()
{
  double future_x = exp(dampening_coefficient * current_time) *
                    cos(angular_frequency * current_time);
  mass.set_x(future_x);
}
