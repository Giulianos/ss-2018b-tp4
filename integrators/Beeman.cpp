//
// Created by Giuliano Scaglioni on 05/11/2018.
//

#include "Beeman.h"

void
Beeman::integrate(Body& b, Force* f, double dt)
{
  /** Evaluate force before getting its components */
  f->evaluate();

  double x = b.get_x();
  double y = b.get_y();

  double vx = b.get_vx();
  double vy = b.get_vy();

  double ax = b.get_ax();
  double ay = b.get_ay();

  double previous_ax = b.get_previous_ax();
  double previous_ay = b.get_previous_ay();

  double future_ax = f->get_force_x() / b.get_mass();
  double future_ay = f->get_force_y() / b.get_mass();

  /** Calculate future position */
  double future_x = x + vx * dt + (2.0 / 3.0) * ax * dt * dt -
                    (1.0 / 6.0) * previous_ax * dt * dt;
  double future_y = y + vy * dt + (2.0 / 3.0) * ay * dt * dt -
                    (1.0 / 6.0) * previous_ay * dt * dt;

  /** Calculate future velocity */
  double future_vx = vx + (1.0 / 3.0) * future_ax * dt + (5.0 / 6.0) * ax * dt -
                     (1.0 / 6.0) * previous_ax * dt;
  double future_vy = vy + (1.0 / 3.0) * future_ay * dt + (5.0 / 6.0) * ay * dt -
                     (1.0 / 6.0) * previous_ay * dt;

  /** Set new position */
  b.set_x(future_x);
  b.set_y(future_y);

  /** Set new velocity */
  b.set_vx(future_vx);
  b.set_vy(future_vy);

  /** Set new acceleration */
  b.set_ax(future_ax);
  b.set_ay(future_ay);
}
