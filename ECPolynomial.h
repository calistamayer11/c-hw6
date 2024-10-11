//
//  ECPolynomial.h
//
//
//  Created by Yufeng Wu on 9/17/22.
//
#ifndef ECPolynomial_h
#define ECPolynomial_h

#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
// *****************************************************************
// Represent a polynomial of a single variable, x, and
// support common operations on polynomial: add, scaling, multiple
// and (long) division, etc

class ECPolynomial
{
public:
    // Construct a polynomial with coefficients, where the first position is the constant term and [i] is the coefficient of x^i
    // Example: given [1, 3, 0, 2], polynomial = 1 + 3x + 2x^3
    // We assume listCoeffsIn is not empty
    // Note: the last term in listCoeffsIn should not be zero (unless its length is 1). For example, if given [1, 3, 0], we should simply it to [1,3]. Since coefficient is a double, we consider a value is practically zero if its absolute value is sufficiently small (say less than 1e^(-10)
    ECPolynomial(const std::vector<double> &listCoeffsIn); // Constructor that takes a list of coefficients
    ECPolynomial(const ECPolynomial &rhs);                 // Copy constructor
    int GetDegree() const;                                 // Get degree of the polynomial

    // Scale by a constant and return the resulting polynomial. For example, if polynomial is 1+3x, and
    // factor = 2, the result is 2+6x
    ECPolynomial Scale(double factor);

    // Feel free to add more interface or implementation functions
    ECPolynomial(int value);
    ECPolynomial() : coefficients(std::vector<double>(1, 0.0)) {} // Default to a polynomial of 0

    double GetCoeff(int degree) const;           // Get coefficient at a specific degree
    void SetCoeffAt(size_t index, double value); // Set the coefficient at a specific index

    // operators
    ECPolynomial operator+(const ECPolynomial &rhs) const; // Add two polynomials
    ECPolynomial operator*(const ECPolynomial &rhs) const; // Multiply two polynomials
    ECPolynomial operator/(const ECPolynomial &rhs) const; // Divide two polynomials
    ECPolynomial operator%(const ECPolynomial &rhs) const; // Get the remainder of division

    // This is for testing only. It can be useful to dump out the polynomial (in some format) to the terminal for debugging
    void Dump() const;

private:
    std::vector<double> coefficients;
};

#endif /* ECPolynomial_h */
