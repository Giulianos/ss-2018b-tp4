#include "forces/Force.h"
#include "forces/GForce.h"
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

  /** Create launch setup */
  LaunchSetup launch_setup(initial_speed, voyager_altitude);

  /** Create space */
  Space space(launch_setup);

  /** Initialize counters */
  double time = 0;
  double time_to_print = 0;
  int progress = 0;
  while (time < total_time) {
    if ((int)(time * 100.0 / total_time) > progress) {
      progress = (int)(time * 100.0 / total_time);
      fprintf(stderr, "Progress: %d%%\n", progress);
    }
    if (time_to_print < 0) {
      space.print_ovito(stdout);
      time_to_print = 60.0 * 60 * 24;
    }
    space.simulate_step(dt);
    time += dt;
    time_to_print -= dt;
  }

  return 0;
}