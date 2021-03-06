//
// Created by Giuliano Scaglioni on 05/11/2018.
//

#ifndef SS_TP4_GFORCE_H
#define SS_TP4_GFORCE_H

#include "../types/Body.h"
#include "Force.h"

class GForce : public Force
{
  static constexpr double G = 6.67408E-11;

  Body b1;
  Body b2;
  double fx;
  double fy;

public:
  GForce(const Body& b1, const Body& b2);

  virtual ~GForce();

  double get_force_x() override;

  double get_force_y() override;

  void evaluate() override;
};

#endif // SS_TP4_GFORCE_H
