/**
 * @Short stability determaination program
 * @File  stability_condition.cpp
 *
 * This function defines the stable time step for itration based on user input
 *
 */

#include <iostream>
#include <math.h>
#include "stability_condition.h"

using namespace std;

double stable_time (double kappa, gsl_matrix * vx, gsl_matrix * vy, double dx, double dy) {

    double t;
    if (dx >= dy) {
        t =  dx*dx/(3*kappa);                         // Limitation for explicit timestep
        //Limitation for horizontal advection timestep
        if ( t > abs(dx/gsl_matrix_max(vx)) ) {
           t = (abs(dx/gsl_matrix_max(vx)));
           
        }
    }
    else if (dy > dx) {
        t =  dy*dy/(3*kappa);
        // Limitation for vertical advection timestep
        if ( t > abs(dy/gsl_matrix_max(vy)) ) {
            t = (abs(dy/gsl_matrix_max(vy)));
        }
    }
    return t;
}
