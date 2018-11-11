//
// Created by Giuliano Scaglioni on 08/11/2018.
//

#include "OvitoObserver.h"

void
OvitoObserver::inject_data(const std::list<Body>* bodies, double current_time)
{
  OvitoObserver::bodies = bodies;
  OvitoObserver::current_time = current_time;
}

void
OvitoObserver::observe()
{
  if (last_observed_time + dt < current_time) {
    last_observed_time = current_time;

    /** Print bodies quantity and empty comment line */
    fprintf(out_file, "%lu\n%lf\n", bodies->size(), current_time);

    for (Body body : *bodies) {
      fprintf(out_file,
              "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",
              body.get_x(),
              body.get_y(),
              body.get_vx(),
              body.get_vy(),
              body.get_radius(),
              body.get_mass());
    }
  }
}

OvitoObserver::OvitoObserver(double dt, const std::string& filename)
  : dt(dt)
{
  last_observed_time = 0;
  out_file = fopen(filename.c_str(), "w");
}

void
OvitoObserver::finalize_observer()
{
  fclose(out_file);
}
