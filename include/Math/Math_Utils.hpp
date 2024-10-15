/** 
 *  \file Math_Utils.hpp
 *  
 *  \brief Source file for Utility Functions.
 *
 *  This supports various utility functions.
 *
 *  \author IndieGameSmith
 *  \date 2024-08-23
 */

#ifndef MATH_UTILS_HPP_
#define MATH_UTILS_HPP_

#include <cmath>
#include <random>

#include "Utils/Exceptions/Math_Exception.hpp"

namespace Game
{
namespace Math
{
	
// Function to calculate the factorial of a number
int Factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * Factorial(n - 1);
    }
}

// Function to calculate the greatest common divisor (GCD) of two numbers
int GCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GCD(b, a % b);
    }
}

// Function to calculate the least common multiple (LCM) of two numbers
int LCM(int a, int b) {
    return (a * b) / GCD(a, b);
}

// Function to calculate the square root of a number
double Sqrt(double x) {
    return std::sqrt(x);
}

// Function to calculate the sine of an angle in radians
double Sin(double x) {
    return std::sin(x);
}

// Function to calculate the cosine of an angle in radians
double Cos(double x) {
    return std::cos(x);
}

// Function to calculate the tangent of an angle in radians
double Tan(double x) {
    return std::tan(x);
}

// Function to calculate the arcsine of a value (in radians)
double Arcsin(double x) {
    return std::asin(x);
}

// Function to calculate the arccosine of a value (in radians)
double Arccos(double x) {
    return std::acos(x);
}

// Function to calculate the arctangent of a value (in radians)
double Arctan(double x) {
    return std::atan(x);
}
	
// Function to convert degrees to radians
double RadianToDegree(double radian)
{
	return radian * (180 / M_PI);
}

// Function to convert radians to degrees
double DegreeToRadian(double degree)
{
	return degree * (M_PI /180);
}
	
// Function to find logrithims
double Log(double x, double base = M_E)
{
    if (x < 0 || base <= 0)
    {
        Game::Math::Exception::InvalidArgumentException("Invalid Number for logrithim function");
    }
    
    return std::log(x) / std::log(base);
}

// Function to find exponential
double Exponent(double base = M_E, double power = 1)
{
	return std::pow(base, power);
}

// Function to Clamp 
template <typename T>
T Clamp(T& value, T min = 0, T max = 1)
{
	if (min > max)
	{
	    Game::Math::Exception::InvalidArgumentException("Min can not be bigger than max");
	}
	
	if (value < min)
	{
	    value = min;
	}
	else (value > max)
        {
	    value = max;
	}
	
	return value;
}

// Function to interpolate 
template <typename T>
T Lerp(T start, T end, float t)
{
	if (start == end)
	{
	    return start;
	}
	
	return start + (end - start) * t;
}

// Function to genrate random number
template <typename T>
T GenrateRandom(T min, T max)
{
	if (min > max)
	{
	    Game::Math::Exception::InvalidArgumentException("Min can not be bigger than max");
	}
	
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(gen);
}

// Function to negate a value
template <typename T>
T Negate(T val)
{
	return 0 - val;
}
	
} // Math

} // Game

#endif // MATH_UTILS_HPP_
