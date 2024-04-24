#ifndef __VERLET_H
#define __VERLET_H

/**
 * Perform step one of the Velocity-Verlet integration algorithm, the predictor step, for a single atom.
 * Predict velocity and position.
 * Update positions &x, &y, &z and velocities &vx, &vy, and &vz.
 */
void verlet_step1(double &x, double &y, double &z, double &vx, double &vy, double &vz,
                  double fx, double fy, double fz, double timestep);

/**
 * Perform step two of the Velocity-Verlet integration algorithm, the corrector step, for a singel atom.
 * Correct the previously predicted velocities. Update velocities &vx, &vy, and &vz.
 */
void verlet_step2(double &vx, double &vy, double &vz, double fx, double fy, double fz,
                  double timestep);

#endif  // __VERLET_H