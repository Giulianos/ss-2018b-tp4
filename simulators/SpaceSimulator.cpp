//
// Created by Giuliano Scaglioni on 11/11/2018.
//

#include "SpaceSimulator.h"
#include "../integrators/Beeman.h"
#include "../integrators/GearPredictorCorrector.h"
#include "../integrators/Integrator.h"
#include "../integrators/Verlet.h"
#include "../observers/MinimumDistanceObserver.h"
#include "../observers/Observer.h"
#include "../observers/OvitoObserver.h"
#include "../types/Space.h"
#include "../utils/LaunchSetup.h"
#include <cstdlib>
#include <string>

void
SpaceSimulator::run(ParamsManager& params)
{
  fprintf(stderr, "Running SpaceSimulator\n");

  /** Get parameters from manager */
  double voyager_altitude = std::atof(params.get("L").c_str());
  double initial_speed = std::atof(params.get("v0").c_str());
  double dt = std::atof(params.get("dt").c_str());
  double total_time = std::atof(params.get("total_time").c_str());
  std::string min_jupiter_dist_file = params.get("min_dist_filename");
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

  /** Create launch setup */
  LaunchSetup launch_setup(initial_speed, voyager_altitude);

  /** Create space */
  Space space(launch_setup, integrator);

  /** Create ovito observer */
  if (ovito_output_filename != "") {
    Observer* ovito_observer =
      new OvitoObserver(60 * 60 * 24, ovito_output_filename);
    space.add_observer(ovito_observer);
  }

  /** Create min_distance observer */
  if (min_jupiter_dist_file != "") {
    Observer* min_distance_observer =
      new MinimumDistanceObserver(min_jupiter_dist_file);
    space.add_observer(min_distance_observer);
  }

  /** Initialize counters */
  double time = 0;
  int progress = 0;
  while (time < total_time) {
    if ((int)(time * 100.0 / total_time) > progress) {
      progress = (int)(time * 100.0 / total_time);
      fprintf(stderr, "Progress: %d%%\n", progress);
    }
    space.simulate_step(dt);
    time += dt;
  }

  space.end_simulation();
}