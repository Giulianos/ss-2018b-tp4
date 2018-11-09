//
// Created by Giuliano Scaglioni on 08/11/2018.
//

#include "MinimumJupiterDistanceObserver.h"
#include <cmath>
#include <limits>

void
MinimumJupiterDistanceObserver::inject_data(const std::list<Body>* bodies,
                                            double current_time)
{
  MinimumJupiterDistanceObserver::bodies = bodies;
}

void
MinimumJupiterDistanceObserver::observe()
{
  double voyager_x;
  double voyager_y;

  double jupiter_x;
  double jupiter_y;

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
    }
  }

  double distance =
    sqrt(pow(voyager_x - jupiter_x, 2) + pow(voyager_y - jupiter_y, 2));

  if (distance < min_distance_jupiter) {
    min_distance_jupiter = distance;
    is_on_top = jupiter_y < voyager_y;
  }
}

MinimumJupiterDistanceObserver::MinimumJupiterDistanceObserver(
  const std::string& filename)
  : min_distance_jupiter(std::numeric_limits<double>::max())
{
  out_file = fopen(filename.c_str(), "w");
}

void
MinimumJupiterDistanceObserver::finalize_observer()
{
  fprintf(out_file, "%lf", min_distance_jupiter * (is_on_top ? 1.0 : -1.0));
  fclose(out_file);
}
