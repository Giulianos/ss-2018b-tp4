//
// Created by Giuliano Scaglioni on 05/11/2018.
//

#ifndef SS_TP4_BODY_H
#define SS_TP4_BODY_H

class Body
{
  /** ID Sequence */
  static int next_id;

  /** Current state */
  double current_x;
  double current_y;
  double current_vx;
  double current_vy;
  double current_ax;
  double current_ay;

  /** Previous state */
  double previous_x;
  double previous_y;
  double previous_vx;
  double previous_vy;
  double previous_ax;
  double previous_ay;

  /** Future state */
  double future_x;
  double future_y;
  double future_vx;
  double future_vy;
  double future_ax;
  double future_ay;

  /** Body properties */
  double radius;
  double mass;
  int id;

public:
  Body(double x, double y, double vx, double vy, double radius, double mass);

  double get_radius() const;

  double get_mass() const;

  double get_x() const;

  double get_y() const;

  double get_vx() const;

  double get_vy() const;

  double get_ax() const;

  double get_ay() const;

  double get_previous_ax() const;

  double get_previous_ay() const;

  int get_id() const;

  void set_x(double x);

  void set_y(double y);

  void set_vx(double vx);

  void set_vy(double vy);

  void set_ax(double ax);

  void set_ay(double ay);

  void update();
};

#endif // SS_TP4_BODY_H
