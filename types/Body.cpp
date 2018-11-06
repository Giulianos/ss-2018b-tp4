//
// Created by Giuliano Scaglioni on 05/11/2018.
//

#include "Body.h"
#include <cmath>
#include <cstdio>

int Body::next_id = 0;

double
Body::get_radius() const
{
  return radius;
}

double
Body::get_mass() const
{
  return mass;
}

Body::Body(double x, double y, double vx, double vy, double radius, double mass)
  : current_x(x)
  , previous_x(x)
  , current_y(y)
  , previous_y(y)
  , current_vx(vx)
  , current_vy(vy)
  , previous_vx(vx)
  , previous_vy(vy)
  , current_ax(0)
  , current_ay(0)
  , previous_ax(0)
  , previous_ay(0)
  , radius(radius)
  , mass(mass)
  , id(Body::next_id++)
{}

double
Body::get_x() const
{
  return current_x;
}

double
Body::get_y() const
{
  return current_y;
}

double
Body::get_vx() const
{
  return current_vx;
}

double
Body::get_vy() const
{
  return current_vy;
}

double
Body::get_ax() const
{
  return current_ax;
}

double
Body::get_ay() const
{
  return current_ay;
}

double
Body::get_previous_ax() const
{
  return previous_ax;
}

double
Body::get_previous_ay() const
{
  return previous_ay;
}

int
Body::get_id() const
{
  return id;
}

void
Body::set_x(double x)
{
  Body::future_x = x;
}

void
Body::set_y(double y)
{
  Body::future_y = y;
}

void
Body::set_vx(double vx)
{
  Body::future_vx = vx;
}

void
Body::set_vy(double vy)
{
  Body::future_vy = vy;
}

void
Body::set_ax(double ax)
{
  Body::future_ax = ax;
}

void
Body::set_ay(double ay)
{
  Body::future_ay = ay;
}

void
Body::update()
{
  /** Update position */
  previous_x = current_x;
  previous_y = current_y;
  current_x = future_x;
  current_y = future_y;
  future_x = NAN;
  future_y = NAN;

  /** Update velocity */
  previous_vx = current_vx;
  previous_vy = current_vy;
  current_vx = future_vx;
  current_vy = future_vy;
  future_vx = NAN;
  future_vy = NAN;

  /** Update acceleration */
  previous_ax = current_ax;
  previous_ay = current_ay;
  current_ax = future_ax;
  current_ay = future_ay;
  future_ax = NAN;
  future_ay = NAN;
}
