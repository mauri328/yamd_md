// main file for milestone 03

#include "verlet.h"
#include <iostream>


int main(int argc, char *argv[]) {
    // hyperparameters
    int nb_dims = 3;
    int nb_atoms = 10;
    int nb_steps = 1000;
    double timestep = 1e-15;  // 1 femto second

    // init atoms
    Positions_t positions(nb_dims, nb_atoms);
    Velocities_t velocities(nb_dims, nb_atoms);
    Forces_t forces(nb_dims, nb_atoms);
    double mass;

    // initialize values
    for (int i = 0; i < nb_atoms; i++) {
        positions(0, i) = i; // x
        positions(1, i) = 0; // y
        positions(2, i) = 10; // z

        for (int j = 0; j < nb_dims; j++) {
            velocities(j, i) = 0;
        }

        forces(0, i) = 0; // x
        forces(1, i) = 0; // y
        forces(2, i) = -9.80665; // z

        mass = 1;
    }

    verlet_step1(positions, velocities, forces, mass, timestep);
    update_force(forces);
    verlet_step2(velocities, forces, mass, timestep);

    std::cout << positions << std::endl;
    std::cout << velocities << std::endl;
    std::cout << velocities.row(0) << std::endl;
    std::cout << forces << std::endl;
}
