//
// Created by Giuliano Scaglioni on 11/11/2018.
//

#include "HookeForce.h"

double
HookeForce::get_force_x()
{
  return x;
}

double
HookeForce::get_force_y()
{
  return y;
}

void
HookeForce::evaluate()
{
  x = -k * body.get_x();
  y = 0;
}

HookeForce::HookeForce(double k, Body& body)
  : k(k)
  , body(body)
{}

void
HookeForce::evaluate(double x, double y, double vx, double vy)
{
  HookeForce::x = -k * x;
  HookeForce::y = 0;
}
