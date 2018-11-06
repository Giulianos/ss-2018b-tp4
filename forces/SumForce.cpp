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
  std::list<Force*>::iterator it;

  for (it = forces.begin(); it != forces.end(); it++) {
    Force* f = *it;
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
