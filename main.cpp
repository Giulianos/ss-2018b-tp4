#include "simulators/RealSpringSimulator.h"
#include "simulators/Simulator.h"
#include "simulators/SpaceSimulator.h"
#include "simulators/SpringSimulator.h"
#include "utils/ParamsManager.h"
#include <iostream>

int
main(int argc, char* argv[])
{
  /** Check if we have the required command-line parameters */
  if (argc < 2) {
    fprintf(stderr, "No params file provided!\n");
    return 1;
  }

  /** Load simulation parameters from file */
  ParamsManager params(argv[1]);

  /** Create simulator */
  Simulator* simulator;

  std::string system_to_simulate = params.get("system");

  if (system_to_simulate == "space") {
    simulator = new SpaceSimulator();
  } else if (system_to_simulate == "spring") {
    simulator = new SpringSimulator();
  } else if (system_to_simulate == "real_spring") {
    simulator = new RealSpringSimulator();
  } else {
    fprintf(stderr, "System to simulate is unknown or wasn't specified!\n");
    return 1;
  }

  simulator->run(params);

  return 0;
}