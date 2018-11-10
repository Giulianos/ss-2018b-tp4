#include "forces/Force.h"
#include "forces/GForce.h"
#include "observers/MinimumDistanceObserver.h"
#include "observers/OvitoObserver.h"
#include "types/Body.h"
#include "types/Space.h"
#include "utils/LaunchSetup.h"
#include "utils/ParamsManager.h"
#include <iostream>

int
main(int argc, char* argv[])
{
  /** Check if we have the required command-line parameters */
  if (argc < 2) {
    fprintf(stderr, "Missing parameters!\n");
    exit(1);
  }

  /** Load simualtion parameters from file */
  ParamsManager params(argv[1]);

  /** Get parameters from manager */
  double voyager_altitude = std::atof(params.get("L").c_str());
  double initial_speed = std::atof(params.get("v0").c_str());
  double dt = std::atof(params.get("dt").c_str());
  double total_time = std::atof(params.get("total_time").c_str());
  std::string min_jupiter_dist_file = params.get("min_jupiter_dist_file");
  std::string ovito_output_filename = params.get("ovito_output_filename");

  /** Create launch setup */
  LaunchSetup launch_setup(initial_speed, voyager_altitude);

  /** Create observers */
  // Observer* ovito_observer =
  // new OvitoObserver(60 * 60 * 24, ovito_output_filename);
  Observer* min_distance_observer =
    new MinimumDistanceObserver(min_jupiter_dist_file);

  /** Create space */
  Space space(launch_setup);

  /** Add observers to space */
  // space.add_observer(ovito_observer);
  space.add_observer(min_distance_observer);

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

  return 0;
}