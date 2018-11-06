//
// Created by Giuliano Scaglioni on 05/11/2018.
//

#ifndef SS_TP4_FORCE_H
#define SS_TP4_FORCE_H

class Force
{
public:
  virtual ~Force(){};

  virtual double get_force_x() = 0;

  virtual double get_force_y() = 0;

  virtual void evaluate() = 0;
};

#endif // SS_TP4_FORCE_H
