#include "solver.hpp"

#include <iostream>
namespace solver{
    //RealVariable class
    RealVariable operator +(const RealVariable &, const RealVariable &){return RealVariable();}
    RealVariable operator +(const RealVariable &, const int){return RealVariable();}
    RealVariable operator +(const int, const RealVariable &){return RealVariable();}
    RealVariable operator -(const RealVariable &, const RealVariable &){return RealVariable();}
    RealVariable operator -(const RealVariable &, const int){return RealVariable();}
    RealVariable operator *(const int, const RealVariable &) {return RealVariable();}
    RealVariable operator /( const RealVariable & ,const int){return RealVariable();}
    RealVariable operator ^(RealVariable const &, const int){return RealVariable();}
    RealVariable operator ==(const RealVariable &, const RealVariable &){return RealVariable();}
    RealVariable operator ==(const RealVariable &, const int){return RealVariable();}

    double solve(RealVariable) {return 0.0;}

    //ComplexVariable class
    ComplexVariable operator +(const ComplexVariable &, const ComplexVariable &){return ComplexVariable();}
    ComplexVariable operator +(const ComplexVariable &, const int){return ComplexVariable();}
    ComplexVariable operator +(const int, const ComplexVariable &){return ComplexVariable();}
    ComplexVariable operator +(const ComplexVariable &, complex<double>){return ComplexVariable();}
    ComplexVariable operator -(const ComplexVariable &, const ComplexVariable &){return ComplexVariable();}
    ComplexVariable operator -(const ComplexVariable &, const int){return ComplexVariable();}
    ComplexVariable operator*(const int, ComplexVariable const &) {return ComplexVariable();}
    ComplexVariable operator /(ComplexVariable const &, const int){return ComplexVariable();}
    ComplexVariable operator^(ComplexVariable const &, const int) {return ComplexVariable();}
    ComplexVariable operator ==(const ComplexVariable &, const int){return ComplexVariable();}
    ComplexVariable operator ==(const ComplexVariable &, const ComplexVariable &){return ComplexVariable();}

    complex<double> solve(ComplexVariable) {return complex<double>();}
}
