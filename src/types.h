#ifndef __TYPES_H
#define __TYPES_H

// #include <Eigen/Dense>
// changed because otherwise Eigen/Dense is not found
#include "../subprojects/eigen-3.4.0/Eigen/Dense"

using Positions_t = Eigen::Array3Xd;
using Velocities_t = Eigen::Array3Xd;
using Forces_t = Eigen::Array3Xd;

#endif  // __TYPES_H