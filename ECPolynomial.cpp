//
//  ECPolynomial.cpp
//
//
//  Created by Yufeng Wu on 9/17/22.
//
#include "ECPolynomial.h"

// Constructor for zero coefficients of a given degree
// ECPolynomial::ECPolynomial(int degree)
// {
//     coefficients.resize(degree + 1, 0.0); // Initialize all coefficients to zero
// }
ECPolynomial::ECPolynomial(int value)
{
    // Assuming you have an internal data structure for coefficients
    // Example: std::vector<int> coefficients;
    coefficients.resize(1);  // For constant polynomial
    coefficients[0] = value; // Set the constant term
}

// Constructor that takes a list of coefficients
ECPolynomial::ECPolynomial(const std::vector<double> &listCoeffsIn)
{
    // Filter out trailing zeros and assign coefficients
    coefficients = listCoeffsIn;
    while (!coefficients.empty() && fabs(coefficients.back()) < 1e-10)
    {
        coefficients.pop_back();
    }
}

// Copy constructor
ECPolynomial::ECPolynomial(const ECPolynomial &rhs)
{
    coefficients = rhs.coefficients;
}

// Get the degree of the polynomial
int ECPolynomial::GetDegree() const
{
    int degree = -1;
    for (int i = coefficients.size() - 1; i >= 0; i--)
    {
        if (coefficients[i] != 0)
        {
            degree = i;
            break;
        }
    }
    return degree;
}

// Set the coefficient at a specific index
void ECPolynomial::SetCoeffAt(size_t index, double value)
{
    if (index >= coefficients.size())
    {
        coefficients.resize(index + 1, 0.0);
    }
    coefficients[index] = value;
}

// Get the coefficient at a specific degree
double ECPolynomial::GetCoeff(int degree) const
{
    if (degree < 0 || degree >= coefficients.size())
    {
        return 0.0;
    }
    return coefficients[degree];
}

// Scale the polynomial by a factor
ECPolynomial ECPolynomial::Scale(double factor)
{
    std::vector<double> result(coefficients.size());
    for (size_t i = 0; i < coefficients.size(); ++i)
    {
        result[i] = coefficients[i] * factor;
    }

    return ECPolynomial(result);
}

// Add two polynomials
ECPolynomial ECPolynomial::operator+(const ECPolynomial &rhs) const
{
    size_t maxSize = std::max(coefficients.size(), rhs.coefficients.size());
    std::vector<double> result(maxSize, 0.0);

    for (size_t i = 0; i < maxSize; ++i)
    {
        if (i < coefficients.size())
            result[i] += coefficients[i];
        if (i < rhs.coefficients.size())
            result[i] += rhs.coefficients[i];
    }

    return ECPolynomial(result);
}

// Multiply two polynomials
ECPolynomial ECPolynomial::operator*(const ECPolynomial &rhs) const
{
    std::vector<double> result(coefficients.size() + rhs.coefficients.size() - 1, 0.0);

    for (size_t i = 0; i < coefficients.size(); ++i)
    {
        for (size_t j = 0; j < rhs.coefficients.size(); ++j)
        {
            result[i + j] += coefficients[i] * rhs.coefficients[j];
        }
    }

    return ECPolynomial(result);
}

// Divide two polynomials and return the quotient
ECPolynomial ECPolynomial::operator/(const ECPolynomial &rhs) const
{
    std::vector<double> quotient;
    std::vector<double> remainder = coefficients;

    while (remainder.size() >= rhs.coefficients.size())
    {
        int degreeDiff = remainder.size() - rhs.coefficients.size();
        double leadingCoeff = remainder.back() / rhs.coefficients.back();

        quotient.insert(quotient.begin(), leadingCoeff);

        for (size_t i = 0; i < rhs.coefficients.size(); ++i)
        {
            remainder[i + degreeDiff] -= leadingCoeff * rhs.coefficients[i];
        }

        while (!remainder.empty() && std::fabs(remainder.back()) < 1e-10)
        {
            remainder.pop_back();
        }
    }

    return ECPolynomial(quotient);
}

// Get the remainder when dividing two polynomials
ECPolynomial ECPolynomial::operator%(const ECPolynomial &rhs) const
{
    std::vector<double> remainder = coefficients;

    while (remainder.size() >= rhs.coefficients.size())
    {
        int degreeDiff = remainder.size() - rhs.coefficients.size();
        double leadingCoeff = remainder.back() / rhs.coefficients.back();

        for (size_t i = 0; i < rhs.coefficients.size(); ++i)
        {
            remainder[i + degreeDiff] -= leadingCoeff * rhs.coefficients[i];
        }

        while (!remainder.empty() && std::fabs(remainder.back()) < 1e-10)
        {
            remainder.pop_back();
        }
    }

    return ECPolynomial(remainder);
}

// Dump the polynomial for debugging
void ECPolynomial::Dump() const
{
    std::ostringstream oss;
    int degree = GetDegree();

    if (degree == -1)
    {
        oss << "0";
    }
    else
    {
        bool firstTerm = true;

        for (int i = degree; i >= 0; --i)
        {
            double coeff = coefficients[i];
            if (fabs(coeff) > 1e-10)
            {
                if (!firstTerm)
                {
                    if (coeff > 0)
                    {
                        oss << " + ";
                    }
                    else
                    {
                        oss << " - ";
                        coeff = -coeff;
                    }
                }

                if (i == 0)
                {
                    oss << coeff;
                }
                else if (i == 1)
                {
                    if (coeff == 1)
                    {
                        oss << "x";
                    }
                    else
                    {
                        oss << coeff << "x";
                    }
                }
                else
                {
                    if (coeff == 1)
                    {
                        oss << "x^" << i;
                    }
                    else
                    {
                        oss << coeff << "x^" << i;
                    }
                }

                firstTerm = false;
            }
        }
    }

    std::cout << oss.str() << std::endl;
}
