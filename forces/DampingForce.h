//
// Created by Giuliano Scaglioni on 11/11/2018.
//

#ifndef SS_TP4_DAMPINGFORCE_H
#define SS_TP4_DAMPINGFORCE_H


#include "Force.h"
#include "../types/Body.h"

class DampingForce : public Force {
    /** Force properties */
    double gamma;
    Body& body;

    /** Force components */
    double x;
    double y;
public:
    DampingForce(double gamma, Body &body);

public:
    double get_force_x() override;

    double get_force_y() override;

    void evaluate() override;

    void evaluate(double x, double y, double vx, double vy) override;
};


#endif //SS_TP4_DAMPINGFORCE_H
