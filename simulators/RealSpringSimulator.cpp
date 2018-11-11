//
// Created by Giuliano Scaglioni on 11/11/2018.
//

#include "RealSpringSimulator.h"
#include "../observers/OvitoObserver.h"
#include "../utils/LaunchSetup.h"
#include "../types/RealSpring.h"

void RealSpringSimulator::run(ParamsManager &params) {
  fprintf(stderr, "Running RealSpringSimulator\n");

    /** Get parameters from manager */
  double dt = std::atof(params.get("dt").c_str());
  double total_time = std::atof(params.get("total_time").c_str());
  std::string ovito_output_filename = params.get("ovito_output_filename");

  /** Create spring */
  RealSpring spring = RealSpring();

  if(ovito_output_filename != "") {
    /** Create observers */
    Observer* ovito_observer =
        new OvitoObserver(1.0/25.0, ovito_output_filename);
    /** Add observers to space */
    spring.add_observer(ovito_observer);
  }

  /** Initialize counters */
  double time = 0;
  int progress = 0;
  while (time < total_time) {
    if ((int)(time * 100.0 / total_time) > progress) {
      progress = (int)(time * 100.0 / total_time);
      fprintf(stderr, "Progress: %d%%\n", progress);
    }
    spring.simulate_step(dt);
    time += dt;
  }

  spring.end_simulation();
}
