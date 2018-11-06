//
// Created by Giuliano Scaglioni on 05/11/2018.
//

#include "Space.h"
#include "../forces/GForce.h"

Space::Space()
{
  bodies.push_front(Body(0, 0, 10, 10, 1, 1));
}

void
Space::simulate_step(double dt)
{
  std::list<Body>::iterator it;

  /** Integrate bodies forces */
  for (it = bodies.begin(); it != bodies.end(); it++) {
    Force* f = new GForce(*it);
    integrator->integrate(*it, f, dt);
    delete f;
  }

  /** Update bodies positions */
  for (it = bodies.begin(); it != bodies.end(); it++) {
    it->update();
  }
}

void
Space::print_ovito() const
{
  FILE* output = stdout;

  /** Print bodies quantity and empty comment line */
  fprintf(output, "%lu\n\n", bodies.size());

  /** Print bodies states */
  std::list<Body>::const_iterator it;

  for (it = bodies.cbegin(); it != bodies.end(); it++) {
    fprintf(
      output, "%lf\t%lf\t%lf\n", it->get_x(), it->get_y(), it->get_radius());
  }
}