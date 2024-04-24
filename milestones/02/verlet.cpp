#include "verlet.h"

void verlet_step1(double &x, double &y, double &z, double &vx, double &vy, double &vz,
                  double fx, double fy, double fz, double timestep) {
    // implement Verlet step1 here
    // atoms.velocities += 0.5 * atoms.forces * timestep / mass; 
    // atoms.positions += atoms.velocities * timestep; 
}

void verlet_step2(double &vx, double &vy, double &vz, double fx, double fy, double fz,
                  double timestep) {
    // implement Verlet step2 here
    // atoms.velocities += 0.5 * atoms.forces * timestep / mass;
}