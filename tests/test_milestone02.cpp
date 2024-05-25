#include "verlet.h"
#include <gtest/gtest.h>

// hyperparameters
double timestep = 1e-15;  // 1 femto second


TEST(Milestone02Test, StepOneConstantGravity) {
    // atom properties
    double x = 0;
    double y = 0;
    double z = 10;
    double vx = 0;
    double vy = 0;
    double vz = 0;
    double mass = 2.99e-26; // kg
    double g = -9.80665; // m/s^2
    double fx = 0;
    double fy = 0;
    double fz = mass * g;

    double x_original = x;
    double y_original = y;
    double vx_original = vx;
    double vy_original = vy;
    double mass_original = mass;

    // after step one, only z and vz should have changed -> vz uncorrected
    verlet_step1(x, y, z, vx, vy, vz, fx, fy, fz, mass, timestep);
    EXPECT_EQ(x, x_original);
    EXPECT_EQ(y, y_original);
    EXPECT_NEAR(z, 9.999999999999999999999999999995096675, 1e-6);
    EXPECT_EQ(vx, vx_original);
    EXPECT_EQ(vy, vy_original);
    EXPECT_NEAR(vz, -4.903325e-15, 1e-6);

    EXPECT_EQ(mass, mass_original);
}

TEST(Milestone02Test, StepTwoConstantGravity) {
    // atom properties
    double x = 0;
    double y = 0;
    double z = 10;
    double vx = 0;
    double vy = 0;
    double vz = 0;
    double mass = 2.99e-26; // kg
    double g = -9.80665; // m/s^2
    double fx = 0;
    double fy = 0;
    double fz = mass * g;

    double vx_original = vx;
    double vy_original = vy;
    double fx_original = fx;
    double fy_original = fy;
    double fz_original = fz;

    verlet_step1(x, y, z, vx, vy, vz, fx, fy, fz, mass, timestep);
    // no update of force since we are modeling constant gravity
    EXPECT_EQ(fx, fx_original);
    EXPECT_EQ(fy, fy_original);
    EXPECT_EQ(fz, fz_original);
    // after step two, vz should be corrected
    verlet_step2(vx, vy, vz, fx, fy, fz, mass, timestep);
    EXPECT_EQ(vx, vx_original);
    EXPECT_EQ(vy, vy_original);

    EXPECT_NEAR(vz, -9.80665e-15, 1e-6);
}


TEST(Milestone02Test, TestAfterMultipleIterations) {
    int nb_steps = 1e5;
    // atom properties
    double x = 0;
    double y = 0;
    double z = 10;
    double vx = 0;
    double vy = 0;
    double vz = 0;
    double mass = 2.99e-26; // kg
    double g = -9.80665; // m/s^2
    double fx = 0;
    double fy = 0;
    double fz = mass * g;

    for (int i = 0; i < nb_steps; ++i) {
        verlet_step1(x, y, z, vx, vy, vz, fx, fy, fz, mass, timestep);
        // no update of force since we are modeling constant gravity
        verlet_step2(vx, vy, vz, fx, fy, fz, mass, timestep);
    }

    EXPECT_NEAR(z, 9.99999999999999999995096675, 1e-6);
    EXPECT_NEAR(vz, -9.80665e-10, 1e-6);
}
