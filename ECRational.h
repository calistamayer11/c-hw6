#ifndef ECRational_h
#define ECRational_h

// #include <stdexcept>
// #include <iostream>
// #include "ECPolynomial.h"
template <class T>
class ECRational
{
private:
    T numerator;
    T denominator;

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

    // Accessors
    const T GetNumerator() const { return numerator; }
    const T GetDenominator() const { return denominator; }

    friend ECRational operator+(const ECRational &lhs, const ECRational &rhs)
    {

        T num = lhs.GetNumerator() * rhs.GetDenominator() + rhs.GetNumerator() * lhs.GetDenominator();
        T den = lhs.GetDenominator() * rhs.GetDenominator();
        return ECRational(num / den);
    }

    friend ECRational operator-(const ECRational &lhs, const ECRational &rhs)
    {
        T num = lhs.GetNumerator() * rhs.GetDenominator() - rhs.GetNumerator() * lhs.GetDenominator();
        T den = lhs.GetDenominator() * rhs.GetDenominator();
        return ECRational(num / den);
    }
    friend ECRational operator*(const ECRational &lhs, const ECRational &rhs)
    {

        T num = lhs.GetNumerator() * rhs.GetNumerator();
        T den = lhs.GetDenominator() * rhs.GetDenominator();
        return ECRational(num / den);
    }
    friend ECRational operator/(const ECRational &lhs, const ECRational &rhs)
    {
        T num = lhs.GetNumerator() * rhs.GetDenominator();
        T den = lhs.GetDenominator() * rhs.GetNumerator();
        return ECRational(num / den);
    }
};

#endif // ECRational_h
