#include "verlet.h"
#include <iostream>

/**
 * Update the force acting on a single atom. Update forces &fx, &fy, &fz.
 **/
void update_force(double &fx, double &fy, double &fz, double mass) {
    // in this case, no update of force since we are modeling constant gravity
    return;
}

int main(int argc, char *argv[]) {
    // hyperparameters
    int nb_steps = 10000;
    double timestep = 1e-15;  // 1 femto second
    int verbosity = 1000; // output only every <verbosity> steps

    // atom properties
    double x = 0;
    double y = 0;
    double z = 0;
    double vx = 0;
    double vy = 0;
    double vz = 0;
    double mass = 1; // kg
    double g = -9.80665; // m/s^2
    double fx = 0;
    double fy = 0;
    double fz = mass * g;

    std::cout << fz << std::endl;

    for (int i = 0; i < nb_steps; ++i) {
        verlet_step1(x, y, z, vx, vy, vz, fx, fy, fz, mass, timestep);
        update_force(fx, fy, fz, mass);
        verlet_step2(vx, vy, vz, fx, fy, fz, mass, timestep);

        if (i % verbosity == verbosity-1 || i+1 == nb_steps) {
            std::cout << "Step: " << i << std::endl;
            std::cout << "------------" << std::endl;
            std::cout << "values after update:" << std::endl;
            std::cout << "position: " << x << ", " << y << ", " << z << std::endl;
            std::cout << "velocity: " << vx << ", " << vy << ", " << vz << std::endl;
            std::cout << "force: " << fx << ", " << fy << ", " << fz << std::endl;
            std::cout << "------------" << std::endl;
        }
    }
}

