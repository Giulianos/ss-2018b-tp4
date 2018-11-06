#include "forces/Force.h"
#include "forces/GForce.h"
#include "types/Body.h"
#include "types/Space.h"
#include <iostream>

int
main()
{
  Space space;
  double time = 0;
  while (time < 5.0) {
    space.simulate_step(0.001);
    space.print_ovito();
    time += 0.001;
  }

  return 0;
}