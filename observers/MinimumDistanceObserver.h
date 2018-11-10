//
// Created by Giuliano Scaglioni on 08/11/2018.
//

#ifndef SS_TP4_MINIMUMDISTANCEOBSERVER_H
#define SS_TP4_MINIMUMDISTANCEOBSERVER_H

#include "Observer.h"
#include <string>

class MinimumDistanceObserver : public Observer
{
  double current_time;
  const std::list<Body>* bodies;
  FILE* out_file;
  double time_jupiter;
  double min_distance_jupiter;
  double time_saturn;
  double min_distance_saturn;
  bool is_on_top;

public:
  MinimumDistanceObserver(const std::string& filename);

  void inject_data(const std::list<Body>* bodies, double current_time) override;

  void observe() override;

  void finalize_observer() override;
};

#endif // SS_TP4_MINIMUMDISTANCEOBSERVER_H
