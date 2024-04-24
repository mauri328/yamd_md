#include "verlet.h"

void verlet_step1(double &x, double &y, double &z, double &vx, double &vy, double &vz,
                  double fx, double fy, double fz, double mass, double timestep) {
    // update velocities
    vx += 0.5 * fx * timestep / mass;
    vy += 0.5 * fy * timestep / mass;
    vz += 0.5 * fz * timestep / mass;
    // update positions
    x += 0.5 * fx * timestep / mass;
    y += 0.5 * fy * timestep / mass;
    z += 0.5 * fz * timestep / mass;
}

void verlet_step2(double &vx, double &vy, double &vz, double fx, double fy, double fz,
                  double mass, double timestep) {
    // correct velocity predictions
    vx += 0.5 * fx * timestep / mass;
    vy += 0.5 * fy * timestep / mass;
    vz += 0.5 * fz * timestep / mass;
}