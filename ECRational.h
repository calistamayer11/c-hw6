//
//  ECRational.h
//
//  Created by Yufeng Wu on 1/7/23.
//
#ifndef ECRational_h
#define ECRational_h

#include <stdexcept>      // For std::invalid_argument
#include <iostream>       // For std::cout
#include "ECPolynomial.h" // Ensure you include your polynomial class

template <class T>
class ECRational
{
public:
    // Constructor with numerator and denominator
    ECRational(const T &num, const T &denom);

    // Copy constructor
    ECRational(const ECRational &other);

    // Assignment operator
    ECRational &operator=(const ECRational &other);

    T GetNumerator() const;

    T GetDenominator() const;

    //  templates needed for the ECRational<ECPolynomial> part?
    template <class U>
    friend ECRational<U> operator+(const ECRational<U> &lhs, const ECRational<U> &rhs);

    template <class U>
    friend ECRational<U> operator-(const ECRational<U> &lhs, const ECRational<U> &rhs);

    template <class U>
    friend ECRational<U> operator*(const ECRational<U> &lhs, const ECRational<U> &rhs);

    template <class U>
    friend ECRational<U> operator/(const ECRational<U> &lhs, const ECRational<U> &rhs);

private:
    T numerator;
    T denominator;
};

#endif
