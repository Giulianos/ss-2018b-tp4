//
// Created by Giuliano Scaglioni on 06/11/2018.
//

#ifndef SS_TP4_LAUNCHSETUP_H
#define SS_TP4_LAUNCHSETUP_H

#include "../types/Body.h"

class LaunchSetup
{
  double v0;
  double altitude;

  double x;
  double y;
  double vx;
  double vy;

public:
  LaunchSetup(double v0, double altitude);

  void calculate_location(const Body& earth);
  double get_x() const;
  double get_y() const;
  double get_vx() const;
  double get_vy() const;

  virtual ~LaunchSetup();
};

#endif // SS_TP4_LAUNCHSETUP_H
