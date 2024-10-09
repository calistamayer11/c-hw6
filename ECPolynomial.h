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

class ECPolynomial
{
public:
    // ECPolynomial(int degree); // Constructor for zero coefficients of a given degree
    ECPolynomial(int value);
    ECPolynomial() : coefficients(std::vector<double>(1, 0.0)) {} // Default to a polynomial of 0
    ECPolynomial(const std::vector<double> &listCoeffsIn);        // Constructor that takes a list of coefficients
    ECPolynomial(const ECPolynomial &rhs);                        // Copy constructor

    int GetDegree() const;                                 // Get the degree of the polynomial
    double GetCoeff(int degree) const;                     // Get coefficient at a specific degree
    void SetCoeffAt(size_t index, double value);           // Set the coefficient at a specific index
    ECPolynomial Scale(double factor);                     // Scale the polynomial by a factor
    ECPolynomial operator+(const ECPolynomial &rhs) const; // Add two polynomials
    ECPolynomial operator*(const ECPolynomial &rhs) const; // Multiply two polynomials
    ECPolynomial operator/(const ECPolynomial &rhs) const; // Divide two polynomials
    ECPolynomial operator%(const ECPolynomial &rhs) const; // Get the remainder of division
    void Dump() const;                                     // Dump the polynomial for debugging

private:
    std::vector<double> coefficients; // Coefficients of the polynomial
};

#endif /* ECPolynomial_h */
