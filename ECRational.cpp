//
//  ECRational.cpp
//
//  Created by Yufeng Wu on 1/7/23.
//
#include "ECRational.h"

// Custom constructor
template <class T>
ECRational<T>::ECRational(const T &numeratorIn, const T &denominatorIn)
    : numerator(numeratorIn), denominator(denominatorIn)
{
    if (denominatorIn == T(0))
    {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
}

// Copy constructor
template <class T>
ECRational<T>::ECRational(const ECRational &other)
    : numerator(other.numerator), denominator(other.denominator) {}

// Assignment operator
template <class T>
ECRational<T> &ECRational<T>::operator=(const ECRational &other)
{
    if (this != &other)
    {
        numerator = other.numerator;
        denominator = other.denominator;
    }
    return *this;
}

// Addition operator
template <class T>
ECRational<T> operator+(const ECRational<T> &lhs, const ECRational<T> &rhs)
{
    return ECRational<T>(
        lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator,
        lhs.denominator * rhs.denominator);
}

// Subtraction operator
template <class T>
ECRational<T> operator-(const ECRational<T> &lhs, const ECRational<T> &rhs)
{
    return ECRational<T>(
        lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator,
        lhs.denominator * rhs.denominator);
}

// Multiplication operator
template <class T>
ECRational<T> operator*(const ECRational<T> &lhs, const ECRational<T> &rhs)
{
    return ECRational<T>(
        lhs.numerator * rhs.numerator,
        lhs.denominator * rhs.denominator);
}

// Division operator
template <class T>
ECRational<T> operator/(const ECRational<T> &lhs, const ECRational<T> &rhs)
{
    if (rhs.numerator == T(0))
    {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return ECRational<T>(
        lhs.numerator * rhs.denominator,
        lhs.denominator * rhs.numerator);
}

// Access numerator
template <class T>
T ECRational<T>::GetNumerator() const
{
    return numerator;
}

// Access denominator
template <class T>
T ECRational<T>::GetDenominator() const
{
    return denominator;
}

// Explicit instantiation for common types (optional, but can improve compilation speed)
template class ECRational<int>;
template class ECRational<double>;
