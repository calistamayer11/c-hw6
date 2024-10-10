#include "ECRational.h"
// #include <stdexcept>

// Arithmetic operations for ECRational<T>
// template <class T>
// ECRational<T> operator+(const ECRational<T> &lhs, const ECRational<T> &rhs)
// {

//     T num = lhs.GetNumerator() * rhs.GetDenominator() + rhs.GetNumerator() * lhs.GetDenominator();
//     T den = lhs.GetDenominator() * rhs.GetDenominator();
//     return ECRational(num / den);
// }

// template <class T>
// ECRational<T> operator-(const ECRational<T> &lhs, const ECRational<T> &rhs)
// {
//     return ECRational<T>(
//         lhs.GetNumerator() * rhs.GetDenominator() - rhs.GetNumerator() * lhs.GetDenominator(),
//         lhs.GetDenominator() * rhs.GetDenominator());
// }

// template <class T>
// ECRational<T> operator*(const ECRational<T> &lhs, const ECRational<T> &rhs)
// {
//     return ECRational<T>(
//         lhs.GetNumerator() * rhs.GetNumerator(),
//         lhs.GetDenominator() * rhs.GetDenominator());
// }

// template <class T>
// ECRational<T> operator/(const ECRational<T> &lhs, const ECRational<T> &rhs)
// {
//     if (rhs.GetNumerator() == T(0))
//     {
//         throw std::invalid_argument("Division by zero is not allowed.");
//     }
//     return ECRational<T>(
//         lhs.GetNumerator() * rhs.GetDenominator(),
//         lhs.GetDenominator() * rhs.GetNumerator());
// }

// // Mixed type arithmetic with T
// template <class T>
// ECRational<T> ECRational<T>::operator+(const T &rhs) const
// {
//     return *this + ECRational<T>(rhs);
// }

// template <class T>
// ECRational<T> ECRational<T>::operator-(const T &rhs) const
// {
//     return *this - ECRational<T>(rhs);
// }

// template <class T>
// ECRational<T> ECRational<T>::operator*(const T &rhs) const
// {
//     return *this * ECRational<T>(rhs);
// }

// template <class T>
// ECRational<T> ECRational<T>::operator/(const T &rhs) const
// {
//     if (rhs == T(0))
//     {
//         throw std::invalid_argument("Division by zero is not allowed.");
//     }
//     return ECRational<T>(GetNumerator(), GetDenominator() * rhs);
// }

// // T + ECRational<T>, T - ECRational<T>, etc.
// template <class T>
// ECRational<T> operator+(const T &lhs, const ECRational<T> &rhs)
// {
//     return ECRational<T>(lhs) + rhs;
// }

// template <class T>
// ECRational<T> operator-(const T &lhs, const ECRational<T> &rhs)
// {
//     return ECRational<T>(lhs) - rhs;
// }

// template <class T>
// ECRational<T> operator*(const T &lhs, const ECRational<T> &rhs)
// {
//     return ECRational<T>(lhs) * rhs;
// }

// template <class T>
// ECRational<T> operator/(const T &lhs, const ECRational<T> &rhs)
// {
//     if (rhs.GetNumerator() == T(0))
//     {
//         throw std::invalid_argument("Division by zero is not allowed.");
//     }
//     return ECRational<T>(lhs * rhs.GetDenominator(), rhs.GetNumerator());
// }

// Explicit instantiation for common types
// template class ECRational<int>;
// template class ECRational<ECPolynomial>;

// template ECRational<int> operator+(const int &lhs, const ECRational<int> &rhs);
// template ECRational<int> operator-(const int &lhs, const ECRational<int> &rhs);
// template ECRational<int> operator*(const int &lhs, const ECRational<int> &rhs);
// template ECRational<int> operator/(const int &lhs, const ECRational<int> &rhs);
