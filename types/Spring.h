//
// Created by Giuliano Scaglioni on 11/11/2018.
//

#ifndef SS_TP4_SPRING_H
#define SS_TP4_SPRING_H


#include "Body.h"
#include "../forces/Force.h"
#include "../observers/Observer.h"
#include "../integrators/Integrator.h"

class Spring {
    std::list<Observer*> observers;
    Body mass = Body(1,0,-0.714,0,0.3,70);
    Integrator * integrator;
    double current_time;

    /** Forces */
    Force * hooke_force;
    Force * damping_force;
public:
    Spring(Integrator * integrator);
    void simulate_step(double dt);
    void add_observer(Observer * observer);
    void end_simulation();
};


#endif //SS_TP4_SPRING_H
