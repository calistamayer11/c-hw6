//
//  ECRational.h
//
//
//  Created by Yufeng Wu on 1/7/23.
//

#ifndef ECRational_h
#define ECRational_h

// #include <stdexcept>
// #include <iostream>
// #include "ECPolynomial.h"

// *****************************************************************
// Generic rational of two quantities (e.g. integers, floating point, complex number, or polynomila)
// Assume the quantity class T supports (i) default constructor and copy constructor, (ii) assignment operator, and (iii) arithmatic operators: +, -, * and /
// Note: you don't need to simplify the rational. That is, it is OK to have common factors in numerator and denominoator. For example, 4/4 = 1/1

template <class T>
class ECRational
{

public:
    ECRational() {}
    // Constructor with numerator and denominator
    ECRational(const T &numeratorIn, const T &denominatorIn)
        : numerator(numeratorIn), denominator(denominatorIn) {}

    // Single argument constructor
    ECRational(const T &num) : numerator(num), denominator(1) {}

    // Copy constructor
    ECRational(const ECRational &other)
        : numerator(other.numerator), denominator(other.denominator) {}

    // Assignment operator
    ECRational &operator=(const ECRational &other)
    {
        if (this != &other)
        {
            this->numerator = other.numerator;
            this->denominator = other.denominator;
        }
        return *this;
    }

    // access numerator and denominator
    const T GetNumerator() const { return numerator; }
    const T GetDenominator() const { return denominator; }

    // operators: define +, -, *, / operators yourself
    friend ECRational operator+(const ECRational &lhs, const ECRational &rhs)
    {
        T num = lhs.GetNumerator() * rhs.GetDenominator() + rhs.GetNumerator() * lhs.GetDenominator();
        T den = lhs.GetDenominator() * rhs.GetDenominator();
        return ECRational(num, den);
    }

    friend ECRational operator-(const ECRational &lhs, const ECRational &rhs)
    {
        T num = lhs.GetNumerator() * rhs.GetDenominator() - rhs.GetNumerator() * lhs.GetDenominator();
        T den = lhs.GetDenominator() * rhs.GetDenominator();
        return ECRational(num, den);
    }
    friend ECRational operator*(const ECRational &lhs, const ECRational &rhs)
    {

        T num = lhs.GetNumerator() * rhs.GetNumerator();
        T den = lhs.GetDenominator() * rhs.GetDenominator();
        return ECRational(num, den);
    }
    friend ECRational operator/(const ECRational &lhs, const ECRational &rhs)
    {
        T num = lhs.GetNumerator() * rhs.GetDenominator();
        T den = lhs.GetDenominator() * rhs.GetNumerator();
        return ECRational(num, den);
    }

private:
    T numerator;
    T denominator;
};

#endif /* ECRational_h */
