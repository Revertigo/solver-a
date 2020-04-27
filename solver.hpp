#ifndef SOLVER_A_SOLVER_HPP
#define SOLVER_A_SOLVER_HPP

#include <complex>
using namespace std;

namespace solver{

    //Forward declaration
    class RealVariable;
    class ComplexVariable;

    double solve(RealVariable);//Function has to clear the varables of the reference
    complex<double> solve(ComplexVariable);

    class RealVariable{
        double _re;

    public:
        RealVariable(): _re(1.0){};//Default C'tor
        //We want make it friend in order to enable something like 7 * RealVariable
        friend RealVariable operator +(const RealVariable &, const RealVariable &);
        friend RealVariable operator +(const RealVariable &, const int);
        friend RealVariable operator +(const int, const RealVariable &);
        friend RealVariable operator -(const RealVariable &, const RealVariable &);
        friend RealVariable operator -(const RealVariable &, const int);
        friend RealVariable operator *(const int, const RealVariable &);
        friend RealVariable operator /(const RealVariable &, const int);
        friend RealVariable operator ^(RealVariable const &, const int);
        friend RealVariable operator ==(const RealVariable &, const RealVariable &);
        friend RealVariable operator ==(const RealVariable &, const int);
    };

    class ComplexVariable {
        double _im;
        double _re;

    public:
        ComplexVariable(): _im(0.0), _re(0.0){}; //Default C'tor

        friend ComplexVariable operator +(const ComplexVariable &, const ComplexVariable &);
        friend ComplexVariable operator +(const ComplexVariable &, const int);
        friend ComplexVariable operator +(const int, const ComplexVariable &);
        friend ComplexVariable operator +(const ComplexVariable &, complex<double>);
        friend ComplexVariable operator -(const ComplexVariable &, const ComplexVariable &);
        friend ComplexVariable operator -(const ComplexVariable &, const int);
        friend ComplexVariable operator *(const int, ComplexVariable const &);
        friend ComplexVariable operator /(ComplexVariable const &, const int);
        friend ComplexVariable operator^(ComplexVariable const &, const int);
        friend ComplexVariable operator ==(const ComplexVariable &, const int);
        friend ComplexVariable operator ==(const ComplexVariable &, const ComplexVariable &);
    };
}

#endif //SOLVER_A_SOLVER_HPP