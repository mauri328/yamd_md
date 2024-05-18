// main file for milestone 03

#include "verlet.h"
#include <iostream>


// hyperparameters
int nb_dims = 3;
int nb_atoms = 10;



// THIS IS COPY FROM MILESTONE 02! CHANGE!!!!

/**
 * Update the force acting on a single atom. Update forces &fx, &fy, &fz.
 **/
void update_force(Forces_t) {
    // in this case, no update of force since we are modeling constant gravity
    return;
}

int main(int argc, char *argv[]) {
    // hyperparameters
    int nb_steps = 1000;
    double timestep = 1e-15;  // 1 femto second

    // init atoms
    Positions_t positions(nb_dims, nb_atoms);
    Velocities_t velocities(nb_dims, nb_atoms);
    Forces_t forces(nb_dims, nb_atoms);
    Masses_t masses(1, nb_atoms);

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
        verlet_step1(positions, velocities, forces, timestep);
        update_force(forces);
        verlet_step2(velocities, forces, timestep);

        int verbosity = 100;
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

