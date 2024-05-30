#ifndef __ATOMS_H
#define __ATOMS_H

#include "types.h"

// using Positions_t = Eigen::Array3Xd;
// using Velocities_t = Eigen::Array3Xd;
// using Forces_t = Eigen::Array3Xd;

class Atoms {
public:
    Positions_t positions;
    Velocities_t velocities;
    Forces_t forces;

    Atoms(const Positions_t &p) :
            positions{p}, velocities{3, p.cols()}, forces{3, p.cols()} {
        velocities.setZero();
        forces.setZero();
    }

    Atoms(const Positions_t &p, const Velocities_t &v) :
            positions{p}, velocities{v}, forces{3, p.cols()} {
        assert(p.cols() == v.cols());
        forces.setZero();
    }

    size_t nb_atoms() const {
        return positions.cols();
    }
};

#endif  // __ATOMS_H