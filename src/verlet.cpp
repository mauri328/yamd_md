#include "verlet.h"


// MILESTONE 02

void verlet_step1(double &x, double &y, double &z, double &vx, double &vy, double &vz,
                  double fx, double fy, double fz, double mass, double timestep) {
    // update velocities -> v(t+Δt/2)
    vx += 0.5 * fx * timestep / mass;
    vy += 0.5 * fy * timestep / mass;
    vz += 0.5 * fz * timestep / mass;
    // update positions -> r(t+Δt)
    x += 0.5 * fx * timestep / mass;
    y += 0.5 * fy * timestep / mass;
    z += 0.5 * fz * timestep / mass;
}

void verlet_step2(double &vx, double &vy, double &vz, double fx, double fy, double fz,
                  double mass, double timestep) {
    // correct velocity predictions -> v(t+Δt)
    vx += 0.5 * fx * timestep / mass;
    vy += 0.5 * fy * timestep / mass;
    vz += 0.5 * fz * timestep / mass;
}


// MILESTONE 03

void verlet_step1(Positions_t &positions, Velocities_t &velocities, const Forces_t &forces, const double mass, double timestep) {
    // update velocities -> v(t+Δt/2)
    velocities += 0.5 * forces * timestep / mass;
    // update positions -> r(t+Δt)
    positions += 0.5 * forces * timestep / mass;
}

void verlet_step2(Velocities_t &velocities, const Forces_t &forces, const double mass, double timestep) {
    // correct velocity predictions -> v(t+Δt)
    velocities += 0.5 * forces * timestep / mass;
}

void update_force(Forces_t &forces) {
    return;  // in this case, no update of force since we are still modeling constant forces
}