//
// Created by Giuliano Scaglioni on 05/11/2018.
//

#include "Space.h"
#include "../forces/GForce.h"
#include "../forces/SumForce.h"
#include "../utils/LaunchSetup.h"
#include <list>

Space::Space(LaunchSetup& launch_setup)
  : launch_setup(launch_setup)
{
  Body jupiter = Body(1.051808117769951E+11,
                      7.552752037839167E+11,
                      -1.310827390034170E+04,
                      2.413222412600538E+03,
                      69911E+03,
                      1898.13E+24);
  Body saturn = Body(-1.075922360420873E+12,
                     8.540977704606439E+11,
                     -6.538404943163649E+03,
                     -7.592712627964003E+03,
                     58232E+03,
                     5.6834E+26);
  Body earth = Body(1.443667096759952E+11,
                    -4.358205294442200E+10,
                    8.134925514034244E+03,
                    2.840370427523522E+04,
                    6371.01E+03,
                    5.97219E+24);
  Body sun = Body(0.0, 0.0, 0.0, 0.0, 6.95700E+08, 1.9885E+30);

  bodies.push_front(earth);
  bodies.push_front(jupiter);
  bodies.push_front(saturn);
  bodies.push_front(sun);

  /** Prepair launch setup for voyager */
  launch_setup.calculate_location(earth);

  /** Add voyager to list of bodies */
  bodies.push_front(Body(launch_setup.get_x(),
                         launch_setup.get_y(),
                         launch_setup.get_vx(),
                         launch_setup.get_vy(),
                         0.0,
                         721.9));
}

void
Space::simulate_step(double dt)
{
  std::list<Body>::iterator it;
  std::list<Body>::const_iterator neighbour;
  std::list<Force*> forces;

  /** Integrate bodies forces */
  for (it = bodies.begin(); it != bodies.end(); it++) {
    forces.clear();
    for (neighbour = bodies.cbegin(); neighbour != bodies.cend(); neighbour++) {
      if (neighbour->get_id() != it->get_id()) {
        forces.push_front(new GForce(*it, *neighbour));
      }
    }
    Force* applied_force = new SumForce(forces);
    integrator->integrate(*it, applied_force, dt);
    for (Force* ptr : forces)
      delete ptr;
    delete applied_force;
  }

  /** Update bodies positions */
  for (it = bodies.begin(); it != bodies.end(); it++) {
    it->update();
  }
}

void
Space::print_ovito(FILE* file) const
{
  FILE* output = file;

  /** Print bodies quantity and empty comment line */
  fprintf(output, "%lu\n\n", bodies.size());

  /** Print bodies states */
  std::list<Body>::const_iterator it;

  for (it = bodies.cbegin(); it != bodies.end(); it++) {
    fprintf(output,
            "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",
            it->get_x(),
            it->get_y(),
            it->get_vx(),
            it->get_vy(),
            it->get_radius(),
            it->get_mass());
  }
}