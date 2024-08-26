/** 
 *  \file Vector2D.hpp
 *  
 *  \brief Header file for Vector2D of Numbers.
 *
 *  This supports Vector on 2 dimesionsal related functions.
 *
 *  \author IndieGameSmith
 *  \date 2024-08-23
 */
 
#ifndef VECTOR2D_HPP_
#define VECTOR2D_HPP_

#include <iostream>
#include "Matrix2f.hpp"

namespace Game
{
    
namespace Math
{

enum class Vec2D_Round_Flag
{
    ToFloor,
    ToCeil,
    ToNearest
};

template <typename T>
struct Vector2D
{
    Vector2D();
    Vector2D(T x, T y);

	Vector2D operator+(const Vector2D& other) const;
	Vector2D operator-(const Vector2D& other) const;
	Vector2D operator*(const double scaler) const;
	Vector2D operator*(const Game::Math::Matrix2f& matrix) const;
	Vector2D operator/(const double scaler) const;
	bool operator==(const Vector2D& other) const;
	bool operator!=(const Vector2D& other) const;
	bool operator<(const Vector2D& other) const;
	bool operator>(const Vector2D& other) const;
	bool operator<=(const Vector2D& other) const;
	bool operator>=(const Vector2D& other) const;
	
	Vector2D Add(const Vector2D& other) const;
	Vector2D Sub(const Vector2D& other) const;
	Vector2D Multiply(const double scaler) const;
	Vector2D Divide(const double scaler) const;
	double DotProduct(const Vector2D& other) const;
	double CrossProduct(const Vector2D& other) const;
	double Magnitude() const;
	Vector2D Normalize() const;
	double DistanceFrom(const Vector2D& other) const;
	double Angle(const Vector2D& other) const;
	Vector2D ProjectOn(const Vector2D& Target) const;
	Vector2D Reflect(const Vector2D& SurfaceNormal);
	Vector2D Rotate(const double angle);
	void Clamp(const Vector2D& min, const Vector2D& max);
	Vector2D Round(const Vec2D_Round_Flag& flag);
	Vector2D Lerp(const Vector2D& other, const float t) const;
	Vector2D Perpendicular() const;
	
	Vector2D GetVec() const;
	void SetVec(T x, T y);
    
    T x, y;
};

/** Mathematical Opreations */
template <typename T>
Vector2D<T> Vec2D_Add(const Vector2D<T>& v1, const Vector2D<T>& v2);
/**
 *  \param v1 First Vector2D.
 *  \param v2 Second Vector2D.
 *
 *  \brief Add two Vector2D quantities.
 *
 *  \return Returns a Resultant Vector2D quantity.
 *
 *  \sa Vec2D_Subtract()
 *  \sa Vec2D_Multiply()
 *  \sa Vec2D_Divide()
 *
 */
template <typename T>
Vector2D<T> Vec2D_Subtract(const Vector2D<T>& v1, const Vector2D<T>& v2);
/**
 *  \param v1 First Vector2D.
 *  \param v2 Second Vector2D.
 *
 *  \brief Subtract two Vector2D quantities.
 *
 *  \return Returns a Resultant Vector2D quantity.
 *
 *  \sa Vec2D_Add()
 *  \sa Vec2D_Multiply()
 *  \sa Vec2D_Divide()
 *
 */
template <typename T>
Vector2D<T> Vec2D_Multiply(const Vector2D<T>& v, const double scaler);
/**
 *  \param v Vector2D quantity.
 *  \param scaler Scaler quantity to be mutilplied.
 *
 *  \brief Multipy a Vector2D quantity with a scaler.
 *
 *  \return Returns a Resultant Vector2D quantity.
 *
 *  \sa Vec2D_Add()
 *  \sa Vec2D_Subtract()
 *  \sa Vec2D_Divide()
 *
 */
template <typename T>
Vector2D<T> Vec2D_Multiply(const Vector2D<T>& v1, const Vector2D<T>& v2);
/**
 *  \param v1 Vector2D quantity.
 *  \param v2 Vector2D quantity.
 *
 *  \brief Multipy a Vector2D quantity with other Vector2D quantity.
 *
 *  \return Returns a Resultant Vector2D quantity.
 *
 *  \sa Vec2D_Add()
 *  \sa Vec2D_Subtract()
 *  \sa Vec2D_Divide()
 *
 */
template <typename T>
Vector2D<T> Vec2D_Divide(const Vector2D<T>& v, const double scaler);
/**
 *  \param v Vector2D quantity.
 *  \param scaler Scaler quantity to be divided.
 *
 *  \brief Multipy a Vector2D quantity with a scaler.
 *
 *  \throw DivisionByZero Error if division by zero '0' occurs.
 *
 *  \return Returns a Resultant Vector2D quantity.
 *
 *
 *  \sa Vec2D_Add()
 *  \sa Vec2D_Subtract()
 *  \sa Vec2D_Multiply()
 *
 */
template <typename T>
Vector2D<T> Vec2D_MultipyByMatrix(const Vector2D<T>& v, const Game::Math::Matrix2f& mat);
/**
 *  \param v Vector2D quantity.
 *  \param mat Matrix2f.
 *
 *  \brief Multipy a Vector2D quantity with Matrix2x 
 *
 *  \return Returns a Resultant Vector2D quantity.
 *
 */
template <typename T>
double Vec2D_DotProduct(const Vector2D<T>& v1, const Vector2D<T>& v2);
/**
 *  \param v1 First Vector2D.
 *  \param v2 Second Vector2D.
 *
 *  \brief Dot product of 2 Vector2D quantities.
 *  
 *  \returns a Rsultant Vector2D quantity.
 *  
 *  \sa Vec2D_Normalize()
 *  \sa Vec2D_Magnitude()
 *  \sa Vec2D_Distance()
 *
 */
template <typename T>
double Vec2D_CrossProduct(const Vector2D<T>& v1, const Vector2D<T>& v2);
/**
 *  \param v1 First Vector2D.
 *  \param v2 Second Vector2D.
 *
 *  \brief Cross product of 2 Vector2D quantities.
 *  
 *  \returns a Rsultant Vector2D quantity.
 *  
 *  \sa Vec2D_DotProduct()
 *
 */
template <typename T>
double Vec2D_Magnitude(const Vector2D<T>& v);
/**
 *  \param v Vector2D.
 *
 *  \brief Magnitude of a Vector2D.
 *  
 *  \returns a Rsultant Floating point quantity.
 *
 *  \sa Vec2D_Normalize()
 *  \sa Vec2D_DotProduct()
 *  \sa Vec2D_Distance()
 *
 */
template <typename T>
Vector2D<T> Vec2D_Normalize(Vector2D<T>& v);
/**
 *  \param v Vector2D.
 *
 *  \brief Normalizes of a Vector2D.
 *  
 *  \returns a Rsultant Vector2D quantity.
 *
 *  \sa Vec2D_Magnitude()
 *  \sa Vec2D_DotProduct()
 *  \sa Vec2D_Distance()
 *
 */

template <typename T>
Vector2D<T> Vec2D_Perpendicular(const Vector2D<T>& v);
/**
 *  \param v Vector2D.
 *
 *  \brief Calculates Perpendicular of a Vector2D.
 *  
 *  \returns a Rsultant  Vector2D quantity.
 *
 *  \sa Vec2D_Magnitude()
 *  \sa Vec2D_DotProduct()
 *  \sa Vec2D_Distance()
 *
 */

template <typename T>
double Vec2D_Distance(const Vector2D<T>& v1, const Vector2D<T>& v2);
/** 
 *  \param v1 First Vector2D.
 *  \param v2 Second Vector2D.
 *  
 *  \brief Calculates Distance between 2 Vector2D.
 *
 *  \returns Resulting distance.
 *
 *  \sa Vec2D_Normalize()
 *  \sa Vec2D_DotProduct()
 *  \sa Vec2D_Magnitude()
 */
template <typename T> 
double Vec2D_Angle(const Vector2D<T>& v1, const Vector2D<T>& v2);
/** 
 *  \param v1 First Vector2D.
 *  \param v2 Second Vector2D.
 *  
 *  \brief Calculates Angle between 2 Vector2D.
 *
 *  \returns Returns Resulting angle.
 */
template <typename T>
Vector2D<T> Vec2D_ProjectOn(const Vector2D<T>& Vector, const Vector2D<T>& Target);
/** 
 *  \param Vector First Vector2D.
 *  \param Target Second Vector2D.
 *  
 *  \brief Project Vector to Target.
 *
 *  \returns Returns Resulting Vector2D.
 */
template <typename T> 
Vector2D<T> Vec2D_Reflect(Vector2D<T>& OrignalVector, const Vector2D<T>& SurfaceNormal);
/** 
 *  \param OrignalVector Vector2D.
 *  \param SurfaceNormal Normal Surface, Vector2D
 *  
 *  \brief Reflectes Orignal Vector.
 *
 *  \returns Returns Resulting Vector2D.
 */
template <typename T>
Vector2D<T> Vec2D_Rotate(Vector2D<T>& v, const double angle);
/** 
 *  \param v Vector2D.
 *  \param angle Angle [Radians] by which v will be rotated.
 *  
 *  \brief Rotates v by angle[in Radians].
 *
 *  \returns Returns Resulting Vector2D.
 */
template <typename T>
void Vec2D_Clamp(Vector2D<T>& GivenVector, const Vector2D<T>& MinClampVector, const Vector2D<T>& MaxClampVector);
/** 
 *  \param GivenVector Given Vector2D.
 *  \param MinClampVector Min range Clamping Vector2D.
 *  \param MaxClampVector Max range Clamping Vector2D.
 *  
 *  \brief Clamps v1 to v2.
 *
 *  \returns Returns Resulting Vector2D.
 */
template <typename T>
Vector2D<T> Vec2D_Round(Vector2D<T>& v, const Vec2D_Round_Flag flag);
/** 
 *  \param v Given Vector2D.
 *  \param flag Flag for rounding Vector2D.
 *  
 *  \brief Rounds v depending on flag.
 *
 *  \returns Returns Resulting Vector2D.
 */
template <typename T>
Vector2D<T> Vec2D_Lerp(const Vector2D<T>& v1, const Vector2D<T>& v2, const float t);
/**
 *  \param v1 First Vector2D.
 *  \param v2 Second Vector2D.
 *  \param t  Interpolation Factor ranges from 0 =< t =< 1.
 *
 *  \brief Linearly interpolate 2 Vector2D.
 *
 *  \return Returns Lerp Vector2D.
 */
 
/** Logical Operations */
template <typename T>
bool Vec2D_IsEqual(const Vector2D<T>& v1, const Vector2D<T>& v2);
/**
 *  \param v1 First Vector2D.
 *  \param v2 Second Vector2D.
 *
 *  \brief Logically compare two Vector2D quantities.
 *
 *  \return Returns true or false.
 *
 *  \sa Vec2D_IsNotEqual()
 *
 */
template <typename T>
bool Vec2D_IsNotEqual(const Vector2D<T>& v1, const Vector2D<T>& v2);
/**
 *  \param v1 First Vector2D.
 *  \param v2 Second Vector2D.
 *
 *  \brief Logically compare two Vector2D quantities.
 *
 *  \return Returns true or false.
 *
 *  \sa Vec2D_IsEqual()
 *
 */

template <typename T>
bool Vec2D_IsGreaterThan(const Vector2D<T>& v1, const Vector2D<T>& v2);
/**
 *  \param v1 First Vector2D.
 *  \param v2 Second Vector2D.
 *
 *  \brief Logically compare two Vector2D quantities.
 *
 *  \return Returns true or false.
 *
 *  \sa Vec2D_IsLessThan()
 *
 */
 
template <typename T>
bool Vec2D_IsLessThan(const Vector2D<T>& v1, const Vector2D<T>& v2);
/**
 *  \param v1 First Vector2D.
 *  \param v2 Second Vector2D.
 *
 *  \brief Logically compare two Vector2D quantities.
 *
 *  \return Returns true or false.
 *
 *  \sa Vec2D_IsGreaterThan()
 *
 */
 
/** For printing Vector2D on console, For debugging Purposes */
template <typename T>
std::ostream& operator<<(std::ostream str, Vector2D<T>& vec);

} // namespace Math

} // namespace Game

#endif // VECTOR2D_HPP_
