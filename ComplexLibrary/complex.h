#pragma oncec
#ifndef __COMPLEX__
#define __COMPLEX__

#include <iostream>
#include <cmath>

using namespace std;

class complex {
public:
	// Default constructor
	complex() { re = 0.0; im = 0.0; };
	complex(double a) : re(a), im(0.0) {}; // constructor that converts a double to a complex 
	complex(double a, double b) : re(a), im(b) {}; // constructor for cartesian coordinate represenation

	// Copy constructor
	// uses the object c to access real and imaginary parts directly because it has access to these private variables
	complex(const complex& c) {
		re = c.re;
		im = c.im;
	}
	// Assignment overloader
	// this points to the object we're copying to
	// as long as their data doesn't already match, it'll change the "this" guy to match what rhs has
	// then bring it back to the original guy on the left using a *this
	complex& operator=(const complex& rhs) {
		if (this != &rhs) {
			this->re = rhs.re;
			this->im = rhs.im;
		}

		return *this;
	}

	// Accessors
	// can get the private variable "re" directly
	double real() const { return re; }

	// can get the private variable "im" directly
	double imag() const { return im; }

	// return magnitude, which can never be negative
	// this function does get access to "im" and "re" directly
	double magnitude() const;

	// member helper functions
	complex& operator+=(const double x);
	complex& operator+=(const complex& z1);

	complex& operator-=(const double x);
	complex& operator-=(const complex& z1);

	complex& operator*=(const double x);
	complex& operator*=(const complex& z1);

	complex& operator/=(const double x);
	complex& operator/=(const complex& z1);

private:
	double re;
	double im;
};

// HELPER FUNCTIONS (FREE/NON-MEMBERS)
// Binary Arithmetic function declarations
complex operator+(const complex& z1, const complex& z2);
complex operator+(const complex& z1, const double x);
complex operator+(const double x, const complex& z);

complex operator-(const complex& z1, const complex& z2);
complex operator-(const complex& z1, const double x);
complex operator-(const double x, const complex& z);

complex operator*(const complex& z1, const complex& z2);
complex operator*(const complex& z1, const double x);
complex operator*(const double x, const complex& z);

complex operator/(const complex& z1, const complex& z2);
complex operator/(const complex& z1, const double x);
complex operator/(const double x, const complex& z);


// Other helper functions
double magnitude(const complex& z);
double real(const complex& z);
double imag(const complex& z);
complex polar(const double r, const double theta);
complex polar(const double r);
complex conj(const complex& z);
double norm(const complex& z);

// Input/Output Function Declarations
istream& operator>>(istream&, complex& complex1);
ostream& operator<<(ostream&, const complex& complex);

//<cmath> to implement this arg() function.
double arg(const complex& z);

// Unary Arithmetic Helper Functions
complex operator+(const complex& z);
complex operator-(const complex& z);

// Comparison Helper Functions
bool operator==(const complex& z1, const complex& z2);
bool operator!= (const complex& z1, const complex& z2);


#endif