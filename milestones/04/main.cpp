// main file for milestone 04

#include "atoms.h"
#include "verlet.h"
#include "xyz.h"

#include <iostream>

int main(int argc, char *argv[]) {
    std::cout << "main function for milestone 04" << std::endl;
    auto [names, positions, velocities]{read_xyz_with_velocities("lj54.xyz")};

    // std::cout << names << std::endl;
    // std::cout << positions << std::endl;
    // std::cout << velocities << std::endl;
}
