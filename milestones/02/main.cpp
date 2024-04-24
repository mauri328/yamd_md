#include "verlet.h"
#include <iostream>

/**
 * Compute force acting on a single atom. Update forces &fx, &fy, &fz.
 **/
void compute_force(double &fx, double &fy, double &fz, double mass) {
    return;
}

int main(int argc, char *argv[]) {
    // hyperparameters
    int nb_steps = 100;
    double timestep = 1;

    // atom properties
    double x = 0;
    double y = 0;
    double z = 0;
    double vx = 0;
    double vy = 0;
    double vz = 0;
    double fx = 0;
    double fy = 0;
    double fz = 0;
    double mass = 0;


    for (int i = 0; i < nb_steps; ++i) {
        std::cout << "Step: " << i << std::endl;
        verlet_step1(x, y, z, vx, vy, vz, fx, fy, fz, timestep);
        compute_force(fx, fy, fz, mass);
        verlet_step2(vx, vy, vz, fx, fy, fz, timestep);
    }
}

