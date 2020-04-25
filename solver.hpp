#ifndef SOLVER_A_SOLVER_HPP
#define SOLVER_A_SOLVER_HPP

#include <complex>

namespace solver{

    double solve();
    std::complex<double> solve();
    class RealVariable{
        double _re;

    public:
        RealVariable(): _re(0.0){};//Default C'tor
        double solve();
        //We want make it friend in order to enable something like 7 * RealVariable
        friend RealVariable operator *(const int, const RealVariable &);
        friend RealVariable operator -(const RealVariable &, const int);
        friend RealVariable operator ==(const RealVariable &, const int);
        friend RealVariable operator ^(RealVariable const &, const int);
    };

    class ComplexVariable {
        double _im;
        double _re;

    public:
        ComplexVariable(): _im(0.0), _re(0.0){}; //Default C'tor
        std::complex<double> solve();

        friend ComplexVariable operator *(ComplexVariable const &);
        friend ComplexVariable operator ^(ComplexVariable const &, ComplexVariable const &);

    };
}

#endif //SOLVER_A_SOLVER_HPP