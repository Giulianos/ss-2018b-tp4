//
// Created by Giuliano Scaglioni on 11/11/2018.
//

#include "SpringSimulator.h"
#include "../integrators/Beeman.h"
#include "../integrators/GearPredictorCorrector.h"
#include "../integrators/Integrator.h"
#include "../integrators/Verlet.h"
#include "../observers/Observer.h"
#include "../observers/OvitoObserver.h"
#include "../types/Spring.h"

void
SpringSimulator::run(ParamsManager& params)
{
  fprintf(stderr, "Running SpringSimulator\n");

  /** Get parameters from manager */
  double dt = std::atof(params.get("dt").c_str());
  double total_time = std::atof(params.get("total_time").c_str());
  std::string ovito_output_filename = params.get("ovito_output_filename");
  std::string integrator_name = params.get("integrator");

  /** Create integrator */
  Integrator* integrator;
  if (integrator_name == "beeman" || integrator_name == "") {
    integrator = new Beeman();
  } else if (integrator_name == "gear_predictor_corrector") {
    integrator = new GearPredictorCorrector();
  } else if (integrator_name == "verlet") {
    integrator = new Verlet();
  } else {
    fprintf(stderr, "Unknown integrator!");
    exit(1);
  }

  /** Create spring */
  Spring spring = Spring(integrator);

  if (ovito_output_filename != "") {
    /** Create observers */
    Observer* ovito_observer =
      new OvitoObserver(1.0 / 25.0, ovito_output_filename);
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
