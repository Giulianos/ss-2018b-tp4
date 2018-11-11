//
// Created by Giuliano Scaglioni on 11/11/2018.
//

#include <cmath>
#include "GearPredictorCorrector.h"

static long factorial(long x) {
  long start = 1;
  while(x>0) {
    start *= x--;
  }
  return start;
}

void GearPredictorCorrector::integrate(Body &b, Force *f, double dt) {
  double rx[6];
  double ry[6];

  rx[0] = b.get_x();
  rx[1] = b.get_vx();
  ry[0] = b.get_y();
  ry[1] = b.get_vy();

  for(int i = 2; i < (sizeof(rx)/sizeof(double)); i++) {
    f->evaluate(rx[i-2], ry[i-2], rx[i-1], ry[i-1]);
    rx[i] = f->get_force_x()/b.get_mass();
    ry[i] = f->get_force_y()/b.get_mass();
  }

  double predicted_rx[6];
  double predicted_ry[6];

  for(int i = 0; i < (sizeof(predicted_rx)/sizeof(double)); i++) {
    predicted_rx[i] = 0;
    predicted_ry[i] = 0;

    for(int j = i, k = 0; j < (sizeof(rx)/sizeof(double)); j++, k++) {
      predicted_rx[i] += rx[j]*pow(dt, k)/factorial(k);
      predicted_ry[i] += ry[j]*pow(dt, k)/factorial(k);
    }
  }

  double d_rx2 = (rx[2] - predicted_rx[2])*dt*dt/2;
  double d_ry2 = (rx[2] - predicted_ry[2])*dt*dt/2;

  double alpha[] = {3.0/20,251.0/360,1.0,11.0/18,1.0/6,1.0/60};

  double corrected_rx[6];
  double corrected_ry[6];

  for(int i = 0; i < (sizeof(corrected_rx)/ sizeof(double)); i++) {
    corrected_rx[i] = predicted_rx[i] + d_rx2*alpha[i]*pow(dt, i)/factorial(i);
    corrected_ry[i] = predicted_ry[i] + d_ry2*alpha[i]*pow(dt, i)/factorial(i);
  }

  /** Set positions */
  b.set_x(corrected_rx[0]);
  b.set_y(corrected_ry[0]);

  /** Set velocity */
  b.set_vx(corrected_rx[1]);
  b.set_vy(corrected_ry[1]);

}


/*

        Vector dR2 = rs[2].add(rPredicted[2].multiply(-1.0)).multiply(dt*dt).divide(2.0);

        Double alpha[] = {3.0/20,251.0/360,1.0,11.0/18,1.0/6,1.0/60};

        Vector[] rCorrected = new Vector[6];

        for(int i = 0; i < rCorrected.length; i++){
            rCorrected[i] = new Vector(0.0,0.0).add(
                    rPredicted[i]
            ).add(
                    dR2.multiply(
                            alpha[i]*Math.pow(dt,i)/factorial(i)
                    )
            );
        }

        return new Body(rCorrected[0],rCorrected[1],b.getM(),b.getTag());
*/