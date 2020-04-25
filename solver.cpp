#include "solver.hpp"

namespace solver{
    RealVariable operator *(const int r1, const RealVariable & r2) {}
    RealVariable operator -(const RealVariable &, const int){}
    RealVariable operator ==(const RealVariable &, const int){}
    RealVariable operator ^(RealVariable const &, const int){}


    ComplexVariable operator*(ComplexVariable const &) {
    }
    ComplexVariable operator^(ComplexVariable const &, ComplexVariable const &) {
    }
}
