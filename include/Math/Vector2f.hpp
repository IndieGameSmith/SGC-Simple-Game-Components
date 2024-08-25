/** 
 *  \file Vector2f.hpp
 *  
 *  \brief Header file for Vector2f of 2 doubleing point integers.
 *
 *  This supports vector related functions.
 *
 *  \author IndieGameSmith
 *  \date 2024-08-23
 */
 
#ifndef VECTOR2F_HPP_
#define VECTOR2F_HPP_

#include <iostream>
#include "Matrix2f.hpp"

namespace Game
{

namespace Math
{

struct Vector2f
{
    Vector2f();
    Vector2f(double x, double y);

	Vector2f& operator+(const Vector2f& other);
	Vector2f& operator-(const Vector2f& other);
	Vector2f& operator*(double scaler);
	Vector2f operator*(const Matrix2f& matrix) const;
	Vector2f& operator/(double scaler);
	bool operator==(const Vector2f& other) const;
	bool operator!=(const Vector2f& other) const;
	
	Vector2f& Add(const Vector2f& other);
	Vector2f& Sub(const Vector2f& other);
	Vector2f& Multiply(const double scaler);
	Vector2f& Divide(const double scaler);
	double DotProduct(const Vector2f& other) const;
	double CrossProduct(const Vector2f& other) const;
	double Magnitude() const;
	Vector2f Normalize() const;
	
	Vector2f GetVec() const;
	void SetVec(double x, double y);
    
    double x, y;
};

enum class Vec2f_Round_Flag
{
    ToFloor,
    ToCeil,
    ToNearest
};

/** Mathematical Opreations */

Vector2f Vec2f_Add(Vector2f& v1, Vector2f& v2);
/**
 *  \param v1 First Vector2f.
 *  \param v2 Second Vector2f.
 *
 *  \brief Add two Vector2f quantities.
 *
 *  \return Returns a Resultant Vector2f quantity.
 *
 *  \sa Vec2f_Substract()
 *  \sa Vec2f_Multiply()
 *  \sa Vec2f_Divide()
 *
 */

Vector2f Vec2f_Substract(Vector2f& v1, Vector2f& v2);
/**
 *  \param v1 First Vector2f.
 *  \param v2 Second Vector2f.
 *
 *  \brief Substract two Vector2f quantities.
 *
 *  \return Returns a Resultant Vector2f quantity.
 *
 *  \sa Vec2f_Add()
 *  \sa Vec2f_Multiply()
 *  \sa Vec2f_Divide()
 *
 */
 
Vector2f Vec2f_Multiply(Vector2f& v, const double scaler);
/**
 *  \param v Vector2f quantity.
 *  \param scaler Scaler quantity to be mutilplied.
 *
 *  \brief Multipy a Vector2f quantity with a scaler.
 *
 *  \return Returns a Resultant Vector2f quantity.
 *
 *  \sa Vec2f_Add()
 *  \sa Vec2f_Substract()
 *  \sa Vec2f_Divide()
 *
 */
 
Vector2f Vec2f_Multiply(Vector2f& v1, Vector2f& v2);
/**
 *  \param v1 Vector2f quantity.
 *  \param v2 Vector2f quantity.
 *
 *  \brief Multipy a Vector2f quantity with other Vector2f quantity.
 *
 *  \return Returns a Resultant Vector2f quantity.
 *
 *  \sa Vec2f_Add()
 *  \sa Vec2f_Substract()
 *  \sa Vec2f_Divide()
 *
 */
 
Vector2f Vec2f_Divide(Vector2f& v, const double scaler);
/**
 *  \param v Vector2f quantity.
 *  \param scaler Scaler quantity to be divided.
 *
 *  \brief Multipy a Vector2f quantity with a scaler.
 *
 *  \throw DivisionByZero Error if division by zero '0' occurs.
 *
 *  \return Returns a Resultant Vector2f quantity.
 *
 *
 *  \sa Vec2f_Add()
 *  \sa Vec2f_Substract()
 *  \sa Vec2f_Multiply()
 *
 */
 
Vector2f Vec2f_MultipyByMatrix(Vector2f& v, Matrix2f& mat);
/**
 *  \param v Vector2f quantity.
 *  \param mat Matrix2f.
 *
 *  \brief Multipy a Vector2f quantity with Matrix2x 
 *
 *  \return Returns a Resultant Vector2f quantity.
 *
 */
 
double Vec2f_DotProduct(Vector2f& v1, Vector2f& v2);
/**
 *  \param v1 First Vector2f.
 *  \param v2 Second Vector2f.
 *
 *  \brief Dot product of 2 Vector2f quantities.
 *  
 *  \returns a Rsultant Vector2f quantity.
 *  
 *  \sa Vec2f_Normalize()
 *  \sa Vec2f_Magnitude()
 *  \sa Vec2f_Distance()
 *
 */
 
double Vec2f_CrossProduct(Vector2f& v1, Vector2f& v2);
/**
 *  \param v1 First Vector2f.
 *  \param v2 Second Vector2f.
 *
 *  \brief Cross product of 2 Vector2f quantities.
 *  
 *  \returns a Rsultant Vector2f quantity.
 *  
 *  \sa Vec2f_DotProduct()
 *
 */
 
double Vec2f_Magnitude(Vector2f& v);
/**
 *  \param v Vector2f.
 *
 *  \brief Magnitude of a Vector2f.
 *  
 *  \returns a Rsultant Floating point quantity.
 *
 *  \sa Vec2f_Normalize()
 *  \sa Vec2f_DotProduct()
 *  \sa Vec2f_Distance()
 *
 */

Vector2f Vec2f_Normalize(Vector2f& v);
/**
 *  \param v Vector2f.
 *
 *  \brief Normalizes of a Vector2f.
 *  
 *  \returns a Rsultant Floating point quantity.
 *
 *  \sa Vec2f_Magnitude()
 *  \sa Vec2f_DotProduct()
 *  \sa Vec2f_Distance()
 *
 */
 
double Vec2f_Distance(Vector2f& v1, Vector2f& v2);
/** 
 *  \param v1 First Vector2f.
 *  \param v2 Second Vector2f.
 *  
 *  \brief Calculates Distance between 2 Vector2f.
 *
 *  \returns Resulting distance.
 *
 *  \sa Vec2f_Normalize()
 *  \sa Vec2f_DotProduct()
 *  \sa Vec2f_Magnitude()
 */
 
double Vec2f_Angle(Vector2f& v1, Vector2f& v2);
/** 
 *  \param v1 First Vector2f.
 *  \param v2 Second Vector2f.
 *  
 *  \brief Calculates Angle between 2 Vector2f.
 *
 *  \returns Returns Resulting angle.
 */

Vector2f Vec2f_ProjectOnto(Vector2f& Vector, Vector2f& Target);
/** 
 *  \param Vector First Vector2f.
 *  \param Target Second Vector2f.
 *  
 *  \brief Project Vector to Target.
 *
 *  \returns Returns Resulting Vector2f.
 */
 
Vector2f Vec2f_Reflect(Vector2f& OrignalVector, Vector2f& SurfaceNormal);
/** 
 *  \param OrignalVector Vector2f.
 *  \param SurfaceNormal Normal Surface, Vector2f
 *  
 *  \brief Reflectes Orignal Vector.
 *
 *  \returns Returns Resulting Vector2f.
 */
 
Vector2f Vec2f_Rotate(Vector2f& v, double angle);
/** 
 *  \param v Vector2f.
 *  \param angle Angle [Radians] by which v will be rotated.
 *  
 *  \brief Rotates v by angle[in Radians].
 *
 *  \returns Returns Resulting Vector2f.
 */
 
void Vec2f_Clamp(Vector2f& GivenVector, Vector2f& MinClampVector, Vector2f& MaxClampVector);
/** 
 *  \param GivenVector Given Vector2f.
 *  \param MinClampVector Min range Clamping Vector2f.
 *  \param MaxClampVector Max range Clamping Vector2f.
 *  
 *  \brief Clamps v1 to v2.
 *
 *  \returns Returns Resulting Vector2f.
 */

Vector2f Vec2f_Round(Vector2f& v, Vec2f_Round_Flag flag);
/** 
 *  \param v Given Vector2f.
 *  \param flag Flag for rounding Vector2f.
 *  
 *  \brief Rounds v depending on flag.
 *
 *  \returns Returns Resulting Vector2f.
 */
 
Vector2f Vec2f_Lerp(Vector2f& v1, Vector2f& v2, double t);
/**
 *  \param v1 First Vector2f.
 *  \param v2 Second Vector2f.
 *  \param t  Interpolation Factor ranges from 0 =< t =< 1.
 *
 *  \brief Linearly interpolate 2 Vector2f.
 *
 *  \return Returns Lerp Vector2f.
 */
 
/** Logical Operations */

bool Vec2f_IsEqual(Vector2f& v1, Vector2f& v2);
/**
 *  \param v1 First Vector2f.
 *  \param v2 Second Vector2f.
 *
 *  \brief Logically compare two Vector2f quantities.
 *
 *  \return Returns true or false.
 *
 *  \sa Vec2f_IsNotEqual()
 *
 */
 
bool Vec2f_IsNotEqual(Vector2f& v1, Vector2f& v2);
/**
 *  \param v1 First Vector2f.
 *  \param v2 Second Vector2f.
 *
 *  \brief Logically compare two Vector2f quantities.
 *
 *  \return Returns true or false.
 *
 *  \sa Vec2f_IsEqual()
 *
 */
 
/** For printing Vector2f on console, For debugging Purposes */
 
std::ostream& operator<<(std::ostream str, Vector2f& vec);

} // namespace Math

} // namespace Game

#endif // VECTOR2F_HPP_
