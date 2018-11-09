//
// Created by Giuliano Scaglioni on 08/11/2018.
//

#ifndef SS_TP4_OBSERVER_H
#define SS_TP4_OBSERVER_H

#include "../types/Body.h"
#include <list>

class Observer
{
public:
  virtual void inject_data(const std::list<Body>* bodies,
                           double current_time) = 0;
  virtual void observe() = 0;
  virtual void finalize_observer() = 0;

  virtual ~Observer() {}
};

#endif // SS_TP4_OBSERVER_H
