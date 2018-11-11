//
// Created by Giuliano Scaglioni on 11/11/2018.
//

#ifndef SS_TP4_HOOKEFORCE_H
#define SS_TP4_HOOKEFORCE_H

#include "../types/Body.h"
#include "Force.h"

class HookeForce : public Force
{
  /** Force properties */
  double k;
  Body& body;

  /** Force components */
  double x;
  double y;

public:
  HookeForce(double k, Body& body);

  double get_force_x() override;

  double get_force_y() override;

  void evaluate() override;

  void evaluate(double x, double y, double vx, double vy) override;
};

#endif // SS_TP4_HOOKEFORCE_H
