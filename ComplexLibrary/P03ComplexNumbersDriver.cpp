// P03ComplexNumbersDriver

/*

This project uses a complex class that has re and im as private variables to represent the two parts of a complex number.
Default constructors as well as constructors that take in different parameters (two values (imag and real) or one value (real) or none)

Member functions for +=, -=, /=, and *= help perform the operations based off whether an object is being operated on another object,
or whether an object is being operated on a non-object/regular number

The *this pointer is returned after performing the operations because each operator will call one of the member helper function

This project works to mimic actions that are performed by the <complex> library
The various helper functions demonstrate many of the operations that can be performed on the complex numbers

Test cases were also implemented following the example test cases to help ensure things work as expected
Assertx was used as well as a throw and catch block to help output any errors


*/

#include <iostream>
#include "complex.h"
#include <cmath>
#include <assert.h>
using namespace std;

// test function that drives multiple infix operators over complex and double arguments
complex f(const complex& z) {
	return z * z * z - 3 * z * z + 4 * z - 2;
}

//approx_value is used for testing equivalent values of type double
inline bool approx_value(double x, double y) {
	return (y - .0001 <= x && x <= y + .0001);
}

bool assertx(bool expr, unsigned line) {
	if (!expr) cerr << "Error at line " << line << endl; return expr;
}

int main()
{
	const double PI = 3.141592653589793;
	const complex i(0, 1); // complex number i = 0 +1i
	complex z1, z2, z3;
	complex z4 = complex(1, 2);
	complex complex_number[] = { complex(2,3),  complex(-1,1), complex(1,1),
							  complex(1,-1), complex(1,0) };
	complex sum = 0.0;
	double x1;
	double y1;
	// for use with polar tests
	complex z8;
	double r_z8;
	double arg_z8;

	complex z5;
	cout << "\nTesting >>: input a complex number (3, -2): ";
	cin >> z5;
	assertx(z5.real() == 3.0, __LINE__);
	assertx(z5.imag() == -2.0, __LINE__);

	cout << "\nTesting <<: output a complex number(3, -2): " << z5;

	cout << "\n\nTesting Assignment Operator";
	z1 = complex(3, 2);
	z2 = complex(-4, 3);
	z4 = z3;

	cout << "\n\nTesting Complex Math Operators with Object";
	z3 += z2;
	assertx(z3 == z2, __LINE__);
	z3 -= z2;
	assertx(z4 == z3, __LINE__);
	z3 *= z2;
	z3 /= z2;
	assertx(z3 == z4, __LINE__);

	cout << "\n\nTesting Complex Math Operators with Constants";
	x1 = z3.real();
	y1 = z3.imag();
	const double C = 3.0;
	z3 += C;
	assertx((z3.real() == (x1 + C)) && (z3.imag() == y1), __LINE__);
	z3 -= C;
	assertx((z3.real() == x1) && (z3.imag() == y1), __LINE__);
	z3 *= C;
	assertx((z3.real() == (x1 * C)) && (z3.imag() == (y1 * C)), __LINE__);
	z3 /= C;
	assertx((z3.real() == x1) && (z3.imag() == y1), __LINE__);

	cout << "\n\nTesting Complex Infix Operators with Objects";
	assertx(z1 == complex(3, 2), __LINE__);
	assertx(z2 == complex(-4, 3), __LINE__);
	assertx((z1 + z2) == complex(-1, 5), __LINE__);
	assertx((z1 - z2) == complex(7, -1), __LINE__);
	assertx((z1 * z2) == complex(-18, 1), __LINE__);
	assertx((z1 / z2) == complex(-0.24, -0.68), __LINE__);

	cout << "\n\nTesting Polar Magnitude Calculation";
	z1 = complex(2, 3);  //note change of value bound to z1
	assertx(z1.real() == 2.0, __LINE__);
	assertx(z1.imag() == 3.0, __LINE__);
	assertx(real(z1) == 2.0, __LINE__);
	assertx(imag(z1) == 3.0, __LINE__);
	assertx(z1.magnitude() == sqrt(z1.real() * z1.real() + z1.imag() * z1.imag()), __LINE__);

	//cout << " reached end of polar magnitude" << endl;

	cout << "\n\nTesting Polar Arg Calculation";
	assertx(arg(complex(1., 0.)) == 0.0, __LINE__);
	assertx(approx_value(arg(complex(0, 1)), PI / 2.0), __LINE__);
	assertx(approx_value(arg(complex(-1, 0)), PI), __LINE__);

	cout << "\n\nTesting Coordinate to Polar";
	z8 = complex{ .5, 4.0 };
	r_z8 = magnitude(z8);
	arg_z8 = arg(complex(z8));
	//cout << "\nPolar arguments: r=" << r_z8 << "  arg=" << arg_z8;
	assertx(approx_value(polar(r_z8, arg_z8).real(), .5), __LINE__);
	assertx(approx_value(polar(r_z8, arg_z8).imag(), 4.0), __LINE__);

	z8 = complex{ -3.0, 7.0 };
	r_z8 = magnitude(z8);
	arg_z8 = arg(complex(z8));
	//cout << "\nPolar arguments: r=" << r_z8 << "  arg=" << arg_z8;
	assertx(approx_value(polar(r_z8, arg_z8).real(), -3.0), __LINE__);
	assertx(approx_value(polar(7.61577, 1.97569).imag(), 7.0), __LINE__);

	cout << "\n\nTesting Chained Calculations";
	// evaluate f(z), z = 2+3i, -1+i, 1+i, 1-i, 1+0i -- chaining
	assertx(f(complex_number[0]) == complex(-25, -15), __LINE__);
	assertx(f(complex_number[1]) == complex(-4, 12), __LINE__);
	assertx(f(complex_number[2]) == complex(0, 0), __LINE__);
	assertx(f(complex_number[3]) == complex(0, 0), __LINE__);
	assertx(f(complex_number[4]) == complex(0, 0), __LINE__);


	// ************************* ADDITIONAL TESTS **************************
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "***** Student's test cases below *****" << endl;

	complex z11, z12, z13, z14, z15, z16;


	cout << "\nTesting >>: Type in the complex number (7, 4) with parentheses and comma: ";
	cin >> z11;
	assertx(z11.real() == 7.0 && z11.imag() == 4.0, __LINE__);


	cout << "\nTesting <<: Output Overload with Ostream" << endl;
	cout << "Here is your complex number(7, 4) : " << z11;


	cout << "\n\nTesting Assignment Operator";
	z12 = complex(9, 1);
	z13 = complex(-4, 4);
	z14 = complex(5, 2);
	z15 = complex(3, 3);
	z16 = complex(1, 1);
	z13 = z14;
	assertx(z13.real() == 5.0 && z13.imag() == 2.0, __LINE__);


	cout << "\n\nTesting Complex Math Operators with Object";
	z14 += z14;
	assertx(z14.real() == 10.0 && z14.imag() == 4.0, __LINE__);
	z14 -= z12;
	assertx(z14.real() == 1.0 && z14.imag() == 3.0, __LINE__);
	z12 *= z12;
	assertx(z12.real() == 80.0 && z12.imag() == 18.0, __LINE__);
	z15 /= z16;
	assertx(z15.real() == 3.0 && z15.imag() == 0.0, __LINE__);


	cout << "\n\nTesting Complex Math Operators with Constants";
	double r1 = z12.real();
	double i1 = z12.imag();
	double randVal = 2.0;

	z12 += randVal;
	assertx((z12.real() == (r1 + randVal)) && (z12.imag() == i1), __LINE__);

	z12 -= randVal;
	assertx((z12.real() == r1) && (z12.imag() == i1), __LINE__);

	// Trying a different random value
	randVal = 10.0;

	z12 *= randVal;
	assertx((z12.real() == (r1 * randVal)) && (z12.imag() == (i1 * randVal)), __LINE__);

	z12 /= randVal;
	assertx((z12.real() == r1) && (z12.imag() == i1), __LINE__);



	cout << "\nTesting Divide by Zero";
	cout << endl;
	// using a try and catch block, the division function eventually gets called, 
	// where the exception is thrown
	try {
		z15 / 0.0;
	}

	catch (runtime_error& excpt) {
		cout << excpt.what();
		cout << endl;
		cout << "Divide by zero error" << endl;
	}



	cout << "\nTesting Conjugate" << endl;
	cout << "Your complex number is: " << z16;
	cout << endl;

	cout << "The conjugate of your complex number is: ";
	complex conjNumber;
	conjNumber = conj(z16);
	cout << conjNumber << endl;



	cout << "\nTesting Magnitude" << endl;
	complex z19;
	z19 = complex(4, 8);
	cout << "Your complex number is: " << z19;
	cout << endl;

	cout << "The magnitude of your complex number is: ";
	double giveMagnitude;
	giveMagnitude = magnitude(z19);

	cout << giveMagnitude << endl;



	cout << "\nTesting Norm" << endl;
	cout << "Your complex number is: " << z19;
	cout << endl;

	cout << "The norm of your complex number is: ";
	double giveNorm;
	giveNorm = norm(z19);

	cout << giveNorm;



	cout << endl;
	cout << "\nTesting Argument Angle Calculation" << endl;
	cout << "Your complex number is: " << z19;
	cout << endl;

	cout << "The arg theta of your complex number (in radians): ";
	double giveArgRad;
	giveArgRad = arg(z19);

	cout << giveArgRad << endl;

	cout << "The arg theta of your complex number (in degrees): ";
	double giveArgDeg = arg(z19);
	giveArgDeg *= (180 / PI);


	cout << ceil(giveArgDeg) << endl;



	cout << "\nTesting Unary Operations";
	cout << endl;
	complex z20;
	z20 = complex(5, 1);
	cout << "Your complex numbers are: " << z19 << " and " << z20;
	cout << endl;

	// Testing subtraction first
	complex unarySubtractFirst;
	unarySubtractFirst = -z19;

	complex unarySubtractSecond;
	unarySubtractSecond = -z20;

	cout << z19 << " after unary subtraction is: " << unarySubtractFirst << endl;
	cout << z20 << " after unary subtraction is: " << unarySubtractSecond << endl;

	// Testing addition afterwards
	complex unaryAdditionFirst;
	unaryAdditionFirst = +z19;

	complex unaryAdditionSecond;
	unaryAdditionSecond = +z20;
	cout << endl;
	cout << z19 << " after unary addition is: " << unaryAdditionFirst << endl;
	cout << z20 << " after unary addition is: " << unaryAdditionSecond << endl;



	cout << "\n\nPASSED TESTS\n";

	return 0;
} //end main
