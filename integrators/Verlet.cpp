//
// Created by Giuliano Scaglioni on 11/11/2018.
//

#include "Verlet.h"

void
Verlet::integrate(Body& b, Force* f, double dt)
{
  /** Evaluate force before getting its components */
  f->evaluate();

  double x = b.get_x();
  double y = b.get_y();

  double vx = b.get_vx();
  double vy = b.get_vy();

  double ax = b.get_ax();
  double ay = b.get_ay();

  double future_ax = f->get_force_x() / b.get_mass();
  double future_ay = f->get_force_y() / b.get_mass();

  /** Calculate future position */
  double future_x = x + vx * dt + ax * dt * dt;
  double future_y = y + vy * dt + ay * dt * dt;

  /** Calculate future velocity */
  double future_vx = vx + dt * (future_ax + ax) / 2;
  double future_vy = vy + dt * (future_ay + ay) / 2;

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
