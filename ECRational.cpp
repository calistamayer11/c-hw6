#include "ECRational.h"

// Constructor with numerator and denominator
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

// Accessor for numerator
template <class T>
T ECRational<T>::GetNumerator() const
{
    return numerator;
}

// Accessor for denominator
template <class T>
T ECRational<T>::GetDenominator() const
{
    return denominator;
}

// Friend arithmetic operators for ECRational<T>
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

// mixed types
template <class T>
ECRational<T> ECRational<T>::operator+(const T &rhs) const
{
    return *this + ECRational(rhs);
}

template <class T>
ECRational<T> ECRational<T>::operator-(const T &rhs) const
{
    return *this - ECRational(rhs);
}

template <class T>
ECRational<T> ECRational<T>::operator*(const T &rhs) const
{
    return *this * ECRational(rhs);
}

template <class T>
ECRational<T> ECRational<T>::operator/(const T &rhs) const
{
    if (rhs == T(0))
    {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return ECRational(GetNumerator(), GetDenominator() * rhs);
}

// T + ECRational<T>, T - ECRational<T>, etc.
template <class T>
ECRational<T> operator+(const T &lhs, const ECRational<T> &rhs)
{
    return ECRational(lhs) + rhs;
}

template <class T>
ECRational<T> operator-(const T &lhs, const ECRational<T> &rhs)
{
    return ECRational(lhs) - rhs;
}

template <class T>
ECRational<T> operator*(const T &lhs, const ECRational<T> &rhs)
{
    return ECRational(lhs) * rhs;
}

template <class T>
ECRational<T> operator/(const T &lhs, const ECRational<T> &rhs)
{
    if (rhs.GetNumerator() == T(0))
    {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return ECRational(lhs * rhs.GetDenominator(), rhs.GetNumerator());
}

// Explicit instantiation for int and ECPolynomial to fix linker error?
template class ECRational<int>;
template class ECRational<ECPolynomial>;
