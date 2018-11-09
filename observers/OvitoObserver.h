//
// Created by Giuliano Scaglioni on 08/11/2018.
//

#ifndef SS_TP4_OVITOOBSERVER_H
#define SS_TP4_OVITOOBSERVER_H

#include "Observer.h"
#include <string>

class OvitoObserver : public Observer
{
  /** Space state to observe */
  const std::list<Body>* bodies;
  double current_time;

  /** Observer properties */
  FILE* out_file;
  double dt;
  double last_observed_time;

public:
  OvitoObserver(double dt, const std::string& filename);

  void inject_data(const std::list<Body>* bodies, double current_time) override;

  void observe() override;

  void finalize_observer() override;
};

#endif // SS_TP4_OVITOOBSERVER_H
