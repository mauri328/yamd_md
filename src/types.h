#ifndef __TYPES_H
#define __TYPES_H

// #include <Eigen/Dense>
// #include <eigen-3.4.0/Eigen/Dense>
#include "../subprojects/eigen-3.4.0/Eigen/Dense"

using Positions_t = Eigen::Array3Xd;
using Velocities_t = Eigen::Array3Xd;
using Forces_t = Eigen::Array3Xd;

#endif  // __TYPES_H