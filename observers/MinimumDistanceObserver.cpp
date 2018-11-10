//
// Created by Giuliano Scaglioni on 08/11/2018.
//

#include "MinimumDistanceObserver.h"
#include <cmath>
#include <limits>

void
MinimumDistanceObserver::inject_data(const std::list<Body>* bodies,
                                     double current_time)
{
  MinimumDistanceObserver::current_time = current_time;
  MinimumDistanceObserver::bodies = bodies;
}

void
MinimumDistanceObserver::observe()
{
  double voyager_x;
  double voyager_y;

  double jupiter_x;
  double jupiter_y;

  double saturn_x;
  double saturn_y;

  /** Find planets positions */
  for (Body body : *bodies) {
    /** Cases are the order in which planets are created (not the best approach)
     */
    switch (body.get_id()) {
      case 4:
        voyager_x = body.get_x();
        voyager_y = body.get_y();
        break;
      case 1:
        jupiter_x = body.get_x();
        jupiter_y = body.get_y();
        break;
      case 2:
        saturn_x = body.get_x();
        saturn_y = body.get_y();
        break;
    }
  }

  double distance =
    sqrt(pow(voyager_x - jupiter_x, 2) + pow(voyager_y - jupiter_y, 2));

  if (distance < min_distance_jupiter) {
    min_distance_jupiter = distance;
    time_jupiter = current_time;
    is_on_top = jupiter_y < voyager_y;
  }

  distance = sqrt(pow(voyager_x - saturn_x, 2) + pow(voyager_y - saturn_y, 2));

  if (distance < min_distance_saturn) {
    min_distance_saturn = distance;
    time_saturn = current_time;
  }
}

MinimumDistanceObserver::MinimumDistanceObserver(const std::string& filename)
  : min_distance_jupiter(std::numeric_limits<double>::max())
  , min_distance_saturn(std::numeric_limits<double>::max())
{
  out_file = fopen(filename.c_str(), "w");
}

void
MinimumDistanceObserver::finalize_observer()
{
  fprintf(out_file,
          "%lf;%lf\n%lf;%lf",
          min_distance_jupiter,
          time_jupiter,
          min_distance_saturn,
          time_saturn);
  fclose(out_file);
}
