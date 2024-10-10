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

    // Single argument constructor (defaults denominator to 1)
    ECRational(const T &num);

    // Copy constructor
    ECRational(const ECRational &other);

    // Assignment operator
    ECRational &operator=(const ECRational &other);

    // Accessors
    T GetNumerator() const;
    T GetDenominator() const;

    // Arithmetic operations
    friend ECRational operator+(const ECRational &lhs, const ECRational &rhs);
    friend ECRational operator-(const ECRational &lhs, const ECRational &rhs);
    friend ECRational operator*(const ECRational &lhs, const ECRational &rhs);
    friend ECRational operator/(const ECRational &lhs, const ECRational &rhs);

    // Mixed type arithmetic with T
    ECRational operator+(const T &rhs) const;
    ECRational operator-(const T &rhs) const;
    ECRational operator*(const T &rhs) const;
    ECRational operator/(const T &rhs) const;

    // T + ECRational<T>, T - ECRational<T>, etc.
    friend ECRational operator+(const T &lhs, const ECRational &rhs);
    friend ECRational operator-(const T &lhs, const ECRational &rhs);
    friend ECRational operator*(const T &lhs, const ECRational &rhs);
    friend ECRational operator/(const T &lhs, const ECRational &rhs);

private:
    T numerator;
    T denominator;
};

#endif
