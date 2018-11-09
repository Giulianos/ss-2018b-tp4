//
// Created by Giuliano Scaglioni on 08/11/2018.
//

#ifndef SS_TP4_MINIMUMDISTANCEOBSERVER_H
#define SS_TP4_MINIMUMDISTANCEOBSERVER_H

#include "Observer.h"
#include <string>

class MinimumJupiterDistanceObserver : public Observer
{
  const std::list<Body>* bodies;
  FILE* out_file;
  double min_distance_jupiter;
  bool is_on_top;

public:
  MinimumJupiterDistanceObserver(const std::string& filename);

  void inject_data(const std::list<Body>* bodies, double current_time) override;

  void observe() override;

  void finalize_observer() override;
};

#endif // SS_TP4_MINIMUMDISTANCEOBSERVER_H
