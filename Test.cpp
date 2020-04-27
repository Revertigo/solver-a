#include "doctest.h"
#include "solver.hpp"

using namespace solver;
using namespace std;

#define EPSILON 0.0001

TEST_CASE("Check the correctness of addition"){
    RealVariable x;

    CHECK_LT(abs(solve(2+x == 5) -3.0), EPSILON);
    CHECK_LT(abs(solve(x+2 == 5) -3.0), EPSILON);
    CHECK_LT(abs(solve(x+2+x+2 == 10) -3.0), EPSILON);
    CHECK_LT(abs(solve(x+x+x+x+x+x+x+x+x+x == 10) - 1.0), EPSILON);
    CHECK_LT(abs(solve(x == 6) - 6.0), EPSILON);
    CHECK_LT(abs(solve(2+10+15+x+5+x == 0.0) + 16.0), EPSILON);
    CHECK_LT(abs(solve(x+x+x+x == 0.0)), EPSILON);
    CHECK_LT(abs(solve(4+x+x+x+x == 0.0) +1.0), EPSILON);

    ComplexVariable y;
    CHECK_LT(abs(solve(2+y == 5).real() - 3.0 ), EPSILON);
    CHECK_LT(abs(solve(2+y == 5).imag()), EPSILON);
    CHECK_LT(abs(solve(y+2i == 5).imag() - 2i), EPSILON);
    CHECK_LT(abs(solve(y+2i == 5).real() - 5.0), EPSILON);
    CHECK_LT(abs(solve(y+5i == y + y+3i).real()), EPSILON);
    CHECK_LT(abs(solve(y+5i == y + y+3i).imag() - 2i), EPSILON);
}

TEST_CASE("Check the correctness of subtraction"){
    RealVariable x;

    CHECK_LT(abs(solve(x-3 == 5) -8.0), EPSILON);//x = 8
    CHECK_LT(abs(solve(x-2-x-2-x-x == 10) +7.0), EPSILON);//x = -7
    CHECK_LT(abs(solve(x-x-x-x-x-x-x-x-x-x == 8.0) + 1.0), EPSILON); // x = -8
    CHECK_LT(abs(solve(x == -6) + 6.0), EPSILON);
    CHECK_LT(abs(solve(x-2-10-15-x-5-x-x == 0.0) + 16.0), EPSILON);
    CHECK_LT(abs(solve(x-x-x-x-x-x == 0.0)), EPSILON);
    CHECK_LT(abs(solve(x-3-x-x-x-x == 0.0) +1.0), EPSILON);
    CHECK_LT(abs(solve(x-3-x-x-x-x == -3.0)), EPSILON);//x = 0
    CHECK_LT(abs(solve(x-3-x-x-x-x == -12.0) - 3.0), EPSILON);

    ComplexVariable y;
    CHECK_LT(abs(solve(y-2 == 5).real()  -7.0 ), EPSILON);
    CHECK_LT(abs(solve(y-2 == 5).imag()), EPSILON);
    CHECK_LT(abs(solve(y-10 -5 + 1i == y + 5.0 -1i).imag() - 2i), EPSILON);
    CHECK_LT(abs(solve(y+2i == 5).real() - 5.0), EPSILON);
    CHECK_LT(abs(solve(y+5i == y + y+3i).real()), EPSILON);
    CHECK_LT(abs(solve(y+5i == y + y+3i).imag() - 2i), EPSILON);
}

TEST_CASE("Check the correctness of multiplication"){
    RealVariable x;

    CHECK_LT(abs(solve(3*x == 6) -2.0), EPSILON);//x = 2
    CHECK_LT(abs(solve(4*(3*x) == -24) +2.0), EPSILON);//x = -2
    CHECK_LT(abs(solve(5*(4*(3*(2*x))) == 120) -1.0), EPSILON);//x = -1
    CHECK_LT(abs(solve(11*x == 0)), EPSILON);//x = 0
    CHECK_LT(abs(solve(12*x == -0)), EPSILON);//x = 0
    CHECK_LT(abs(solve(1*x == 1) -1.0), EPSILON);//x = 1
}

TEST_CASE("Check the correctness of division"){
    RealVariable x;

    CHECK_LT(abs(solve(x/3 == (1/3)) -1.0), EPSILON);//x = 1
    CHECK_LT(abs(solve(x/2/3 == (1/3)) -2.0), EPSILON);//x = 2
    CHECK_LT(abs(solve(x/2/3/4/5 == (1/2/3/4/5)) -1.0), EPSILON);//x = 1
    CHECK_LT(abs(solve(x/72 == 0)), EPSILON);//x = 0
    CHECK_LT(abs(solve(x/1 == 1)), EPSILON);//x = 1
    CHECK_THROWS(abs(solve(x/0 == 0)));//throw exception
    CHECK_THROWS(abs(solve(x/5/0 == 5)));//throw exception
    CHECK_THROWS(abs(solve(x/5/0/10 == 1/5/10)));//throw exception
}

TEST_CASE("Check the correctness of power"){
    RealVariable x;

    CHECK_LT(abs(solve((x^2) == 9) -3.0), EPSILON);//x = 3
    CHECK_LT(abs(solve(((x^2)^1) == 64) -8.0), EPSILON);//x = 8
    CHECK_THROWS(abs(solve((x^2) == -64)) -8.0);// throw exception
    CHECK_THROWS(abs(solve(((x^2)^1) == -16)) -4.0);// throw exception
    CHECK_GT(abs(solve((x^2) == 17) -4.0), EPSILON);// x = 4.12
}

TEST_CASE("Check the correctness of equality"){
    RealVariable x;

    CHECK_LT(abs(solve((x^2) == (x^2))), EPSILON);//x = 0
    CHECK_LT(abs(solve(2*x == 3*x)), EPSILON);//x = 0
    CHECK_LT(abs(solve(2*x == 3*x+15) +15.0), EPSILON);//x = -15
    CHECK_LT(abs(solve(5*x+5 == 9*x +5)), EPSILON);//x = 0
    CHECK_LT(abs(solve(5+x == 3*x+15) +5.0), EPSILON);//x = -5
    CHECK_LT(abs(solve(3*(x^2) == 3*(x^2) + 3*x+15) +5.0), EPSILON);//x = -5
    CHECK_LT(abs(solve(2*x/4 + 3*x == -2*x/4 + 4) -1.0), EPSILON);//x = 1
    CHECK_LT(abs(solve(2*x/4 + 3*x == 2*x/4 + 3*x)), EPSILON);//x = 0
    CHECK_LT(abs(solve(x-2 + 3*x == x-3 + 2*x) +0.25), EPSILON);//x = -0.25
}

TEST_CASE("Check the correctness of all operators together"){
    RealVariable x;
    RealVariable x1;

    CHECK_LT(abs(solve(2*x1 - 4 == 10) - 7.0), EPSILON);
    bool check = (((abs(solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x) -4.0)) < EPSILON) ||
                 ((abs(solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x) +4.0)) <  EPSILON));
    CHECK(check);// x = 4 or -4
    CHECK_LT(abs(solve(3*x-x-x-x-x+x+x+x+x - 4 == 10) - 7.0), EPSILON); // x = 7
    CHECK_LT(abs(solve((x^2) + 3- 4 == 0.0) - 1), EPSILON); // x = 1
    CHECK_THROWS(abs(solve((x^2) + 1*x + 4 == 0.0) - 1)); // x = 1
}
