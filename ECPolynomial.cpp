//
//  ECPolynomial.cpp
//
//
//  Created by Yufeng Wu on 9/17/22.
//

#include "ECPolynomial.h"

// Constructor for a constant polynomial
ECPolynomial::ECPolynomial(int value)
{
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
    if (coefficients.empty())
    {
        return 0;
    }
    return coefficients.size() - 1; // The highest index is the degree
}

// Set the coefficient at a specific index
void ECPolynomial::SetCoeffAt(size_t index, double value)
{
    if (index >= coefficients.size())
    {
        coefficients.resize(index + 1, 0.0); // Resize and initialize new coefficients to 0
    }
    coefficients[index] = value;

    while (!coefficients.empty() && fabs(coefficients.back()) < 1e-10)
    {
        coefficients.pop_back();
    }
}

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

    // Remove trailing zeros from the result
    while (!result.empty() && fabs(result.back()) < 1e-10)
    {
        result.pop_back();
    }

    return ECPolynomial(result);
}

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
    while (!result.empty() && fabs(result.back()) < 1e-10)
    {
        result.pop_back();
    }

    return ECPolynomial(result);
}

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

        // Remove trailing zeros
        while (!remainder.empty() && std::fabs(remainder.back()) < 1e-10)
        {
            remainder.pop_back();
        }
    }

    return ECPolynomial(quotient);
}

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

void ECPolynomial::Dump() const
{
    std::ostringstream oss;
    int degree = GetDegree();

    if (degree == -1)
    {
        oss << "0"; // Empty polynomial
    }
    else
    {
        std::cout << "Deg: " << GetDegree() << ":  ";
        for (int x = 0; x < coefficients.size(); ++x)
        {
            std::cout << coefficients[x] << " ";
        }
        std::cout << std::endl;
    }
}