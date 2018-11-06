//
// Created by Giuliano Scaglioni on 05/11/2018.
//

#include "GForce.h"
#include "math.h"

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
  double dx = b2.get_x() - b1.get_x();
  double dy = b2.get_y() - b1.get_y();
  double r = sqrt(dx * dx + dy * dy);

  double rx = dx / r;
  double ry = dy / r;

  double f = b1.get_mass() * b2.get_mass() * G / (r * r);

  this->fx = f * rx;
  this->fy = f * ry;
}

GForce::GForce(const Body& b1, const Body& b2)
  : b1(b1)
  , b2(b2)
{}

GForce::~GForce() {}
