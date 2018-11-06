//
// Created by Giuliano Scaglioni on 05/11/2018.
//

#ifndef SS_TP4_GFORCE_H
#define SS_TP4_GFORCE_H

#include "../types/Body.h"
#include "Force.h"

class GForce : public Force
{
  static constexpr double g = 9.8;

  Body b;
  double fx;
  double fy;

public:
  GForce(const Body& b);

  virtual ~GForce();

  double get_force_x() override;

  double get_force_y() override;

  void evaluate() override;
};

#endif // SS_TP4_GFORCE_H
