#include "forces/Force.h"
#include "forces/GForce.h"
#include "types/Body.h"
#include "types/Space.h"
#include "utils/LaunchSetup.h"
#include <iostream>

int
main(int argc, char* argv[])
{
  if (argc < 3) {
    fprintf(stderr, "Missing parameters!\n");
    exit(1);
  }
  LaunchSetup launch_setup(std::atof(argv[1]), std::atof(argv[2]));
  Space space(launch_setup);
  double time = 0;
  double time_to_print = 0;
  double dt = 60.0;
  while (time < (60 * 60 * 24 * 365.0)) {
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