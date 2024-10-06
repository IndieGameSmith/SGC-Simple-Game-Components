/** 
 *  \file Math_Utils.hpp
 *  
 *  \brief Source file for Vector2D.
 *
 *  This supports Vector2D related functions.
 *
 *  \author IndieGameSmith
 *  \date 2024-08-23
 */

#ifndef MATH_UTILS_HPP_
#define MATH_UTILS_HPP_

#include <cmath>

namespace Game
{
namespace Math
{
	
// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
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
	
// Trignometric Functions

	
} // Math

} // Game

#endif // MATH_UTILS_HPP_
