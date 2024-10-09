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

template <typename T>
class ECRational
{
public:
    // Default constructor
    ECRational() : numerator(T()), denominator(T(1)) {} // Default to 1 (like 1/1)

    // Constructor with numerator and denominator
    ECRational(const T &num, const T &denom);

    // Conversion constructor from an integer
    ECRational(int num) : numerator(T(num)), denominator(T(1)) {}

    // Copy constructor
    ECRational(const ECRational &other);

    // Assignment operator
    ECRational &operator=(const ECRational &other);

    // Getter for numerator
    T GetNumerator() const;

    // Getter for denominator
    T GetDenominator() const;

    // Operator + for ECRational
    ECRational operator+(const ECRational &rhs) const;

    // Operator - for ECRational
    ECRational operator-(const ECRational &rhs) const;

    // Operator * for ECRational
    ECRational operator*(const ECRational &rhs) const;

    // Operator / for ECRational
    ECRational operator/(const ECRational &rhs) const;

    // Optional: operator for outputting the rational for debugging
    void Dump() const;

private:
    T numerator;
    T denominator;
};

// Non-member multiplication operator for int and ECRational
template <typename T>
ECRational<T> operator*(const T &lhs, const ECRational<T> &rhs)
{
    return ECRational<T>(
        lhs * rhs.GetNumerator(),
        rhs.GetDenominator());
}
// Non-member addition operator for int and ECRational
template <typename T>
ECRational<T> operator+(const T &lhs, const ECRational<T> &rhs)
{
    return ECRational<T>(
        lhs * rhs.GetDenominator() + rhs.GetNumerator(),
        rhs.GetDenominator());
}

// Non-member division operator for int and ECRational
template <typename T>
ECRational<T> operator/(const T &lhs, const ECRational<T> &rhs)
{
    return ECRational<T>(
        lhs * rhs.GetDenominator(),
        rhs.GetNumerator());
}
// Specialization for ECPolynomial type
template <>
class ECRational<ECPolynomial>
{
public:
    // Default constructor
    ECRational() : numerator(ECPolynomial()), denominator(ECPolynomial(1)) {}

    // Constructor with numerator and denominator
    ECRational(const ECPolynomial &num, const ECPolynomial &denom);

    // Conversion constructor from an integer
    ECRational(int num) : numerator(ECPolynomial(num)), denominator(ECPolynomial(1)) {}

    // Copy constructor
    ECRational(const ECRational &other);

    // Assignment operator
    ECRational &operator=(const ECRational &other);

    // Getter for numerator
    ECPolynomial GetNumerator() const;

    // Getter for denominator
    ECPolynomial GetDenominator() const;

    // Operator + for ECRational
    ECRational operator+(const ECRational &rhs) const;

    // Operator - for ECRational
    ECRational operator-(const ECRational &rhs) const;

    // Operator * for ECRational
    ECRational operator*(const ECRational &rhs) const;

    // Operator / for ECRational
    ECRational operator/(const ECRational &rhs) const;

    // Optional: operator for outputting the rational for debugging
    void Dump() const;

private:
    ECPolynomial numerator;
    ECPolynomial denominator;
};

#endif /* ECRational_h */
