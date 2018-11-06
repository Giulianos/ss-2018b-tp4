//
// Created by Giuliano Scaglioni on 05/11/2018.
//

#include "GForce.h"

double
GForce::get_force_x()
{
  return this->fx;
}

double
GForce::get_force_y()
{
  return this->fy;
}

void
GForce::evaluate()
{
  this->fx = 0.0;
  this->fy = -1.0 * this->g * this->b.get_mass();
}

GForce::GForce(const Body& b)
  : b(b)
{}

GForce::~GForce() {}
