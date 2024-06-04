#ifndef __VERLET_H
#define __VERLET_H

#include "types.h"
#include "atoms.h"

// MILESTONE 02

/**
 * Perform step one of the Velocity-Verlet integration algorithm, the predictor step, for a single atom.
 * Predict velocity v(t+Δt/2) and position r(t+Δt).
 * Update positions &x, &y, &z and velocities &vx, &vy, and &vz.
 */
void verlet_step1(double &x, double &y, double &z, double &vx, double &vy, double &vz, double fx, double fy, double fz, double mass, double timestep);

/**
 * Perform step two of the Velocity-Verlet integration algorithm, the corrector step, for a single atom.
 * Correct the previously predicted velocities -> v(t+Δt). Update velocities &vx, &vy, and &vz.
 */
void verlet_step2(double &vx, double &vy, double &vz, double fx, double fy, double fz, double mass, double timestep);


// MILESTONE 03

/**
 * Apply step one of the Velocity-Verlet integration algorithm, the predictor step, to each atom in an array.
 * Predict velocities v(t+Δt/2) and positions r(t+Δt).
 * Update positions array "positions" and velocities array "velocities".
 */
void verlet_step1(Positions_t &positions, Velocities_t &velocities, const Forces_t &forces, const double mass, double timestep);

/**
 * Apply step two of the Velocity-Verlet integration algorithm, the corrector step, to each atom in an array.
 * Correct the previously predicted velocities -> v(t+Δt). Update velocities array "velocities".
 */
void verlet_step2(Velocities_t &velocities, const Forces_t &forces, const double mass, double timestep);

/**
 * Update the forces acting on atoms in an array.
*/
void update_force(Forces_t &forces);

// MILESTONE 04

/**
 * Apply step one of the Velocity-Verlet integration algorithm, the predictor step, to each atom in an array.
 * Predict velocities v(t+Δt/2) and positions r(t+Δt).
 * Modify atoms.positions and atoms.velocities.
 */
void verlet_step1(Atoms &atoms, const double mass, double timestep);

/**
 * Apply step two of the Velocity-Verlet integration algorithm, the corrector step, to each atom in an array.
 * Correct the previously predicted velocities -> v(t+Δt).
 * Modify atoms.velocities.
 */
void verlet_step2(Atoms &atoms, const double mass, double timestep);

/**
 * Update the forces acting on atoms in an array.
 * Implements the Lennaard-Jones potential.
 * Modify atoms.forces;
*/
double lj_direct_summation(Atoms &atoms, double epsilon=1.0, double sigma=1.0);


#endif  // __VERLET_H