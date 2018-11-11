//
// Created by Giuliano Scaglioni on 05/11/2018.
//

#include "SumForce.h"

double
SumForce::get_force_x()
{
  return this->fx;
}

double
SumForce::get_force_y()
{
  return this->fy;
}

void
SumForce::evaluate()
{
  fx = 0;
  fy = 0;

  for (Force * f : forces) {
    f->evaluate();
    fx += f->get_force_x();
    fy += f->get_force_y();
  }
}

SumForce::SumForce(const std::list<Force*>& forces)
  : forces(forces)
  , fx(0)
  , fy(0)
{}

SumForce::~SumForce() {}

void SumForce::evaluate(double x, double y, double vx, double vy) {
  fx = 0;
  fy = 0;

  for (Force * f : forces) {
    f->evaluate(x, y, vx, vy);
    fx += f->get_force_x();
    fy += f->get_force_y();
  }
}
