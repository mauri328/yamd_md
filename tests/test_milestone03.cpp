#include "verlet.h"
// #include "types.h"
#include <gtest/gtest.h>
// #include <Eigen/Dense>


// hyperparameters
int nb_dims = 3;
int nb_atoms = 10;
int nb_steps = 1000;
double timestep = 1e-15;  // 1 femto second
double g = -9.80665; // m/s^2

// init atoms
Positions_t positions(nb_dims, nb_atoms);
Velocities_t velocities(nb_dims, nb_atoms);
Forces_t forces(nb_dims, nb_atoms);
double mass;

void resetProperties() {
    // initialize values
    for (int i = 0; i < nb_atoms; i++) {
        positions(0, i) = i; // x
        positions(1, i) = 0; // y
        positions(2, i) = 10; // z

        for (int j = 0; j < nb_dims; j++) {
            velocities(j, i) = 0;
        }

        mass = 2.99e-26; // kg

        forces(0, i) = 0; // x
        forces(1, i) = 0; // y
        forces(2, i) = mass * g; // y
    }
}

TEST(Milestone03, StepOneUnchangedProperties) {
    // initialize values
    resetProperties();

    // get copies
    auto pos_copy_x = positions.row(0);
    auto pos_copy_y = positions.row(1);
    auto vel_copy_x = velocities.row(0);
    auto vel_copy_y = velocities.row(1);
    auto forces_copy = forces;
    double mass_copy = mass;

    for (int i = 0; i < nb_steps; ++i) {
        verlet_step1(positions, velocities, forces, mass, timestep);
        update_force(forces);
        verlet_step2(velocities, forces, mass, timestep);
    }

    // x and y components of position and velocity, forces and mass, should remain unchanged
    EXPECT_EQ(positions.row(0).isApprox(pos_copy_x), true);
    EXPECT_EQ(positions.row(1).isApprox(pos_copy_y), true);
    EXPECT_EQ(velocities.row(0).isApprox(vel_copy_x), true);
    EXPECT_EQ(velocities.row(1).isApprox(vel_copy_y), true);
    EXPECT_EQ(forces.isApprox(forces_copy), true);
    EXPECT_EQ(forces.isApprox(forces_copy+1), false);
    EXPECT_EQ(mass, mass_copy);
}

TEST(Milestone03, StepOneConstantGravity) {
    // initialize values
    resetProperties();

    verlet_step1(positions, velocities, forces, mass, timestep);

    // after step one, only z and vz should have changed -> vz uncorrected
    // EXPECT_NEAR(z, 9.999999999999999999999999999995096675, 1e-6);
    // EXPECT_NEAR(vz, -4.903325e-15, 1e-6);
}

TEST(Milestone02Test, StepTwoConstantGravity) {
    // initialize values
    resetProperties();

    verlet_step1(positions, velocities, forces, mass, timestep);
    update_force(forces);
    verlet_step2(velocities, forces, mass, timestep);

    // after step two, vz should be corrected
    // EXPECT_NEAR(vz, -9.80665e-15, 1e-6);
}