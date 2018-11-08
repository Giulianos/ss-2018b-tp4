//
// Created by Giuliano Scaglioni on 06/11/2018.
//

#include "LaunchSetup.h"
#include <cmath>
#include <cstdio>

LaunchSetup::LaunchSetup(double v0, double altitude)
  : v0(v0)
  , altitude(altitude)
{}

LaunchSetup::~LaunchSetup() = default;

void
LaunchSetup::calculate_location(const Body& earth)
{
  double rx = earth.get_x();
  double ry = earth.get_y();

  double r = sqrt(rx * rx + ry * ry);

  double ex = rx / r;
  double ey = ry / r;

  x = rx + (altitude + earth.get_radius()) * ex;
  y = ry + (altitude + earth.get_radius()) * ey;

  vx = -ey * v0 + earth.get_vx();
  vy = ex * v0 + earth.get_vy();
}

double
LaunchSetup::get_x() const
{
  return x;
}

double
LaunchSetup::get_y() const
{
  return y;
}

double
LaunchSetup::get_vx() const
{
  return vx;
}

double
LaunchSetup::get_vy() const
{
  return vy;
}