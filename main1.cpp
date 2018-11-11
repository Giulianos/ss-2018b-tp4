#include "forces/Force.h"
#include "forces/GForce.h"
#include "observers/MinimumDistanceObserver.h"
#include "observers/OvitoObserver.h"
#include "types/Body.h"
#include "types/Space.h"
#include "utils/LaunchSetup.h"
#include "utils/ParamsManager.h"
#include "types/Spring.h"
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
  double dt = std::atof(params.get("dt").c_str());
  double total_time = std::atof(params.get("total_time").c_str());
  std::string ovito_output_filename = params.get("ovito_output_filename");

  /** Create observers */
  Observer* ovito_observer =
    new OvitoObserver(1.0/25.0, ovito_output_filename);

  /** Create spring */
  Spring spring = Spring();

  /** Add observers to space */
  spring.add_observer(ovito_observer);

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

  return 0;
}