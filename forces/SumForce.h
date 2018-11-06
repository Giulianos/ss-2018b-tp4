//
// Created by Giuliano Scaglioni on 05/11/2018.
//

#ifndef SS_TP4_SUMFORCE_H
#define SS_TP4_SUMFORCE_H

#include "../types/Body.h"
#include "Force.h"
#include <list>

class SumForce : public Force
{
  std::list<Force*> forces;
  double fx;
  double fy;

public:
  SumForce(const std::list<Force*>& forces);

  virtual ~SumForce();

  double get_force_x() override;

  double get_force_y() override;

  void evaluate() override;
};

#endif // SS_TP4_SUMFORCE_H
