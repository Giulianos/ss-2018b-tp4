//
// Created by Giuliano Scaglioni on 11/11/2018.
//

#include "DampingForce.h"

double DampingForce::get_force_x() {
  return x;
}

double DampingForce::get_force_y() {
  return y;
}

void DampingForce::evaluate() {
  x = -gamma * body.get_vx();
  y = 0;
}

DampingForce::DampingForce(double gamma, Body &body) : gamma(gamma), body(body) {}

void DampingForce::evaluate(double x, double y, double vx, double vy) {
  DampingForce::x = -gamma * vx;
  DampingForce::y = 0;
}
