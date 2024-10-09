//
//  ECRational.cpp
//
//  Created by Yufeng Wu on 1/7/23.
//
#include "ECRational.h"

template <class T>
ECRational<T>::ECRational(const T &numeratorIn, const T &denominatorIn)
    : numerator(numeratorIn), denominator(denominatorIn)
{
    if (denominatorIn == T(0))
    {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
}

template <class T>
ECRational<T>::ECRational(const ECRational &other)
    : numerator(other.numerator), denominator(other.denominator) {}

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

template <class T>
ECRational<T> operator+(const ECRational<T> &lhs, const ECRational<T> &rhs)
{
    return ECRational<T>(
        lhs.GetNumerator() * rhs.GetDenominator() + rhs.GetNumerator() * lhs.GetDenominator(),
        lhs.GetDenominator() * rhs.GetDenominator());
}

template <class T>
ECRational<T> operator-(const ECRational<T> &lhs, const ECRational<T> &rhs)
{
    return ECRational<T>(
        lhs.GetNumerator() * rhs.GetDenominator() - rhs.GetNumerator() * lhs.GetDenominator(),
        lhs.GetDenominator() * rhs.GetDenominator());
}

template <class T>
ECRational<T> operator*(const ECRational<T> &lhs, const ECRational<T> &rhs)
{
    return ECRational<T>(
        lhs.GetNumerator() * rhs.GetNumerator(),
        lhs.GetDenominator() * rhs.GetDenominator());
}

template <class T>
ECRational<T> operator/(const ECRational<T> &lhs, const ECRational<T> &rhs)
{
    if (rhs.GetNumerator() == T(0))
    {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return ECRational<T>(
        lhs.GetNumerator() * rhs.GetDenominator(),
        lhs.GetDenominator() * rhs.GetNumerator());
}
