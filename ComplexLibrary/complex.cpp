#include <cmath>
#include "complex.h"

using namespace std;


double complex::magnitude() const {
	double magnitude = 0.0;
	magnitude = sqrt(pow(re, 2) + pow(im, 2));

	return magnitude;
}

// OTHER HELPER FUNCTIONS (FREE/NON-MEMBERS):

// This function can't directly access re and im because it's a non-member, so it has to use the getters
// z is passed in explicitly because this is an outside function and can't use "re" and "im" directly
double magnitude(const complex& z) {
	double magnitude;
	magnitude = sqrt(pow(z.real(), 2) + pow(z.imag(), 2));

	return magnitude;
}

// uses the object z to call real because it doesn't have access to "re"
double real(const complex& z) {

	return z.real();
}

// uses the object z to call imag because it doesn't have access to "im"
double imag(const complex& z) {

	return z.imag();
}

// constructs a complex via polar coords
complex polar(const double r, const double theta) {
	return complex((r * cos(theta)), (r * sin(theta)));
}

complex polar(const double r) {
	return complex(r, 0.0);
}

// returns the conjugate of complex number, makes the imag part negative
complex conj(const complex& z) {
	double real = 0.0;
	double imag = 0.0;

	real = z.real();
	imag = (-z.imag());

	return complex(real, imag);
}

// returns squared magnitude (absolute) value of z, calls the magnitude function then doubles it
double norm(const complex& z) {
	double temp = magnitude(z);

	return (temp * temp);
}

// returns arg (theta) value of complex number z
// theta is equal to atan2(b, a) and gives the angle of a 2D graph
double arg(const complex& z) {
	return atan2(z.imag(), z.real());
}


// BINARY ARITHMETIC HELPER FUNCTIONS

// Addition cases:
complex& complex::operator+=(const complex& z1) {
	re += z1.real();
	im += z1.imag();

	return *this;
}

complex& complex::operator+=(const double x) {
	re += x;

	return *this;
}

// calls (const complex& z1)
complex operator+(const complex& z1, const complex& z2) {
	return complex(z1) += z2;
}

// calls (const double x)
complex operator+(const complex& z1, const double x) {
	return complex(z1) += x;
}

// calls (const complex& z1)
complex operator+(const double x, const complex& z) {
	return complex(z) += x;
}



// Subtraction cases:
complex& complex::operator-=(const complex& z1) {
	re -= z1.real();
	im -= z1.imag();

	return *this;
}

complex& complex::operator-=(const double x) {
	re -= x;

	return *this;
}

// calls (const complex & z1)
complex operator-(const complex& z1, const complex& z2) {

	return complex(z1) -= z2;
}

// calls (const double x)
complex operator-(const complex& z1, const double x) {

	return complex(z1) -= x;
}
// calls (const complex& z1)
complex operator-(const double x, const complex& z) {

	return complex(z) -= x;
}


// Multiplication cases
complex& complex::operator*=(const complex& z1) {
	double tempReal = 0.0;
	double tempImag = 0.0;

	tempReal = (re * z1.real()) - (im * z1.imag());
	tempImag = (re * z1.imag()) + (im * z1.real());

	re = tempReal;
	im = tempImag;

	return *this;
}

complex& complex::operator*=(const double x) {
	re *= x;
	im *= x;

	return *this;
}

// calls const complex& z1
complex operator*(const complex& z1, const complex& z2) {

	return complex(z1) *= z2;
}

// calls (const double x)
complex operator*(const complex& z1, const double x) {

	return complex(z1) *= x;
}

// calls (const complex& z1)
complex operator*(const double x, const complex& z) {

	return complex(x) *= z;
}


// Division cases
complex& complex::operator/=(const complex& z1) {
	double denomonator = 0.0;
	denomonator = (pow(z1.real(), 2) + pow(z1.imag(), 2));
	double tempReal = 0.0;
	double tempImag = 0.0;


	tempReal = ((re * z1.real()) + (im * z1.imag())) / denomonator;
	tempImag = ((im * z1.real()) - (re * z1.imag())) / denomonator;

	re = tempReal;
	im = tempImag;

	return *this;
}

complex& complex::operator/=(const double x) {
	re /= x;
	im /= x;

	return *this;
}

// calls (const complex& z1)
complex operator/(const complex& z1, const complex& z2) {

	return complex(z1) /= z2;
}

// calls (const double x)
complex operator/(const complex& z1, const double x) {
	if (x == 0.0) {
		throw runtime_error("Zero in the denominator not allowed!");
		cout << endl;
	}

	return complex(z1) /= x;
}

// calls (const complex& z1)
complex operator/(const double x, const complex& z1) {

	return complex(x) /= z1;
}



// UNARY ARITHMETIC HELPER FUNCTIONS
complex operator+(const complex& z) {

	return z;
}

complex operator-(const complex& z) {

	return complex(-z.real(), -z.imag());
}


// INPUT/OUTPUT HELPER FUNCTIONS
ostream& operator<< (ostream& out, const complex& complex) {
	out << "(" << complex.real() << ", " << complex.imag() << ")";

	return out;
}

// Takes in two doubles and call the constructor
// ignores white space 
istream& operator>> (istream& in, complex& complex1) {
	char lParen = ' ';
	char comma = ' ';
	char rParen = ' ';
	double realNum = 0.0;
	double imagNum = 0.0;

	in >> lParen >> realNum >> comma >> imagNum >> rParen;
	complex1 = complex(realNum, imagNum);

	return in;
}


// COMPARISON HELPER FUNCTIONS
// Checks if the real parts and imaginary parts match and returns true if they do
bool operator==(const complex& z1, const complex& z2) {
	return ((z1.real() == z2.real()) && (z1.imag() == z2.imag()));
}

bool operator!=(const complex& z1, complex& z2) {
	return ((z1.real() != z2.real()) && (z1.imag() != z2.imag()));
}