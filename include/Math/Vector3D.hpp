/** 
 *  \file Vector3D.hpp
 *  
 *  \brief Header file for Vector3D of Numbers.
 *
 *  This supports Vector on 3 dimesionsal related functions.
 *
 *  \author IndieGameSmith
 *  \date 2024-10-04
 */
 
#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

#include <iostream>
#include "Matrix3D.hpp"

namespace Game
{
    
namespace Math
{

enum class Vec3D_Round_Flag
{
    ToFloor,
    ToCeil,
    ToNearest
};

template <typename T>
struct Vector3D
{
    Vector3D();
    Vector3D(T x, T y);

	Vector3D<T> operator+(const Vector3D<T>& other) const;
	Vector3D<T> operator-(const Vector3D<T>& other) const;
	Vector3D<T> operator*(const double scaler) const;
	Vector3D<T> operator*(const Game::Math::Matrix3D<T>& matrix) const;
	Vector3D<T> operator/(const double scaler) const;
	bool operator==(const Vector3D<T>& other) const;
	bool operator!=(const Vector3D<T>& other) const;
	bool operator<(const Vector3D<T>& other) const;
	bool operator>(const Vector3D<T>& other) const;
	bool operator<=(const Vector3D<T>& other) const;
	bool operator>=(const Vector3D<T>& other) const;
	
	Vector3D<T> Add(const Vector3D<T>& other) const;
	Vector3D<T> Sub(const Vector3D<T>& other) const;
	Vector3D<T> Multiply(const double scaler) const;
	Vector3D<T> Divide(const double scaler) const;
	double DotProduct(const Vector3D<T>& other) const;
	double CrossProduct(const Vector3D<T>& other) const;
	double Magnitude() const;
	Vector3D<T> Normalize() const;
	double DistanceFrom(const Vector3D<T>& other) const;
	double Angle(const Vector3D<T>& other) const;
	Vector3D<T> ProjectOn(const Vector3D<T>& Target) const;
	Vector3D<T> Reflect(const Vector3D<T>& SurfaceNormal);
	Vector3D<T> Rotate(const double angle);
	void Clamp(const Vector3D<T>& min, const Vector3D<T>& max);
	Vector3D<T> Round(const Vec3D_Round_Flag& flag);
	Vector3D<T> Lerp(const Vector3D<T>& other, const float t) const;
	Vector3D<T> Perpendicular() const;
	
	Vector3D<T> GetVec() const;
	void SetVec(T x, T y, T z);
    
    T x, y, z;
};

/** Mathematical Opreations */
template <typename T>
Vector3D<T> Vec3D_Add(const Vector3D<T>& v1, const Vector3D<T>& v2);
/**
 *  \param v1 First Vector3D.
 *  \param v2 Second Vector3D.
 *
 *  \brief Add two Vector3D quantities.
 *
 *  \return Returns a Resultant Vector3D quantity.
 *
 *  \sa Vec3D_Subtract()
 *  \sa Vec3D_Multiply()
 *  \sa Vec3D_Divide()
 *
 */
template <typename T>
Vector3D<T> Vec3D_Subtract(const Vector3D<T>& v1, const Vector3D<T>& v2);
/**
 *  \param v1 First Vector3D.
 *  \param v2 Second Vector3D.
 *
 *  \brief Subtract two Vector3D quantities.
 *
 *  \return Returns a Resultant Vector3D quantity.
 *
 *  \sa Vec3D_Add()
 *  \sa Vec3D_Multiply()
 *  \sa Vec3D_Divide()
 *
 */
template <typename T>
Vector3D<T> Vec3D_Multiply(const Vector3D<T>& v, const double scaler);
/**
 *  \param v Vector3D quantity.
 *  \param scaler Scaler quantity to be mutilplied.
 *
 *  \brief Multipy a Vector3D quantity with a scaler.
 *
 *  \return Returns a Resultant Vector3D quantity.
 *
 *  \sa Vec3D_Add()
 *  \sa Vec3D_Subtract()
 *  \sa Vec3D_Divide()
 *
 */
template <typename T>
Vector3D<T> Vec3D_Multiply(const Vector3D<T>& v1, const Vector3D<T>& v2);
/**
 *  \param v1 Vector3D quantity.
 *  \param v2 Vector3D quantity.
 *
 *  \brief Multipy a Vector3D quantity with other Vector3D quantity.
 *
 *  \return Returns a Resultant Vector3D quantity.
 *
 *  \sa Vec3D_Add()
 *  \sa Vec3D_Subtract()
 *  \sa Vec3D_Divide()
 *
 */
template <typename T>
Vector3D<T> Vec3D_Divide(const Vector3D<T>& v, const double scaler);
/**
 *  \param v Vector3D quantity.
 *  \param scaler Scaler quantity to be divided.
 *
 *  \brief Multipy a Vector3D quantity with a scaler.
 *
 *  \throw DivisionByZero Error if division by zero '0' occurs.
 *
 *  \return Returns a Resultant Vector3D quantity.
 *
 *
 *  \sa Vec3D_Add()
 *  \sa Vec3D_Subtract()
 *  \sa Vec3D_Multiply()
 *
 */
template <typename T>
Vector3D<T> Vec3D_MultipyByMatrix(const Vector3D<T>& v, const Game::Math::Matrix3D<T>& mat);
/**
 *  \param v Vector3D quantity.
 *  \param mat Matrix2f.
 *
 *  \brief Multipy a Vector3D quantity with Matrix2x 
 *
 *  \return Returns a Resultant Vector3D quantity.
 *
 */
template <typename T>
double Vec3D_DotProduct(const Vector3D<T>& v1, const Vector3D<T>& v2);
/**
 *  \param v1 First Vector3D.
 *  \param v2 Second Vector3D.
 *
 *  \brief Dot product of 2 Vector3D quantities.
 *  
 *  \returns a Rsultant Vector3D quantity.
 *  
 *  \sa Vec3D_Normalize()
 *  \sa Vec3D_Magnitude()
 *  \sa Vec3D_Distance()
 *
 */
template <typename T>
double Vec3D_CrossProduct(const Vector3D<T>& v1, const Vector3D<T>& v2);
/**
 *  \param v1 First Vector3D.
 *  \param v2 Second Vector3D.
 *
 *  \brief Cross product of 2 Vector3D quantities.
 *  
 *  \returns a Rsultant Vector3D quantity.
 *  
 *  \sa Vec3D_DotProduct()
 *
 */
template <typename T>
double Vec3D_Magnitude(const Vector3D<T>& v);
/**
 *  \param v Vector3D.
 *
 *  \brief Magnitude of a Vector3D.
 *  
 *  \returns a Rsultant Floating point quantity.
 *
 *  \sa Vec3D_Normalize()
 *  \sa Vec3D_DotProduct()
 *  \sa Vec3D_Distance()
 *
 */
template <typename T>
Vector3D<T> Vec3D_Normalize(Vector3D<T>& v);
/**
 *  \param v Vector3D.
 *
 *  \brief Normalizes of a Vector3D.
 *  
 *  \returns a Rsultant Vector3D quantity.
 *
 *  \sa Vec3D_Magnitude()
 *  \sa Vec3D_DotProduct()
 *  \sa Vec3D_Distance()
 *
 */

template <typename T>
Vector3D<T> Vec3D_Perpendicular(const Vector3D<T>& v);
/**
 *  \param v Vector3D.
 *
 *  \brief Calculates Perpendicular of a Vector3D.
 *  
 *  \returns a Rsultant  Vector3D quantity.
 *
 *  \sa Vec3D_Magnitude()
 *  \sa Vec3D_DotProduct()
 *  \sa Vec3D_Distance()
 *
 */

template <typename T>
double Vec3D_Distance(const Vector3D<T>& v1, const Vector3D<T>& v2);
/** 
 *  \param v1 First Vector3D.
 *  \param v2 Second Vector3D.
 *  
 *  \brief Calculates Distance between 2 Vector3D.
 *
 *  \returns Resulting distance.
 *
 *  \sa Vec3D_Normalize()
 *  \sa Vec3D_DotProduct()
 *  \sa Vec3D_Magnitude()
 */
template <typename T> 
double Vec3D_Angle(const Vector3D<T>& v1, const Vector3D<T>& v2);
/** 
 *  \param v1 First Vector3D.
 *  \param v2 Second Vector3D.
 *  
 *  \brief Calculates Angle between 2 Vector3D.
 *
 *  \returns Returns Resulting angle.
 */
template <typename T>
Vector3D<T> Vec3D_ProjectOn(const Vector3D<T>& Vector, const Vector3D<T>& Target);
/** 
 *  \param Vector First Vector3D.
 *  \param Target Second Vector3D.
 *  
 *  \brief Project Vector to Target.
 *
 *  \returns Returns Resulting Vector3D.
 */
template <typename T> 
Vector3D<T> Vec3D_Reflect(Vector3D<T>& OrignalVector, const Vector3D<T>& SurfaceNormal);
/** 
 *  \param OrignalVector Vector3D.
 *  \param SurfaceNormal Normal Surface, Vector3D
 *  
 *  \brief Reflectes Orignal Vector.
 *
 *  \returns Returns Resulting Vector3D.
 */
template <typename T>
Vector3D<T> Vec3D_Rotate(Vector3D<T>& v, const double angle);
/** 
 *  \param v Vector3D.
 *  \param angle Angle [Radians] by which v will be rotated.
 *  
 *  \brief Rotates v by angle[in Radians].
 *
 *  \returns Returns Resulting Vector3D.
 */
template <typename T>
void Vec3D_Clamp(Vector3D<T>& GivenVector, const Vector3D<T>& MinClampVector, const Vector3D<T>& MaxClampVector);
/** 
 *  \param GivenVector Given Vector3D.
 *  \param MinClampVector Min range Clamping Vector3D.
 *  \param MaxClampVector Max range Clamping Vector3D.
 *  
 *  \brief Clamps v1 to v2.
 *
 *  \returns Returns Resulting Vector3D.
 */
template <typename T>
Vector3D<T> Vec3D_Round(Vector3D<T>& v, const Vec3D_Round_Flag flag);
/** 
 *  \param v Given Vector3D.
 *  \param flag Flag for rounding Vector3D.
 *  
 *  \brief Rounds v depending on flag.
 *
 *  \returns Returns Resulting Vector3D.
 */
template <typename T>
Vector3D<T> Vec3D_Lerp(const Vector3D<T>& v1, const Vector3D<T>& v2, const float t);
/**
 *  \param v1 First Vector3D.
 *  \param v2 Second Vector3D.
 *  \param t  Interpolation Factor ranges from 0 =< t =< 1.
 *
 *  \brief Linearly interpolate 2 Vector3D.
 *
 *  \return Returns Lerp Vector3D.
 */
 
/** Logical Operations */
template <typename T>
bool Vec3D_IsEqual(const Vector3D<T>& v1, const Vector3D<T>& v2);
/**
 *  \param v1 First Vector3D.
 *  \param v2 Second Vector3D.
 *
 *  \brief Logically compare two Vector3D quantities.
 *
 *  \return Returns true or false.
 *
 *  \sa Vec3D_IsNotEqual()
 *
 */
template <typename T>
bool Vec3D_IsNotEqual(const Vector3D<T>& v1, const Vector3D<T>& v2);
/**
 *  \param v1 First Vector3D.
 *  \param v2 Second Vector3D.
 *
 *  \brief Logically compare two Vector3D quantities.
 *
 *  \return Returns true or false.
 *
 *  \sa Vec3D_IsEqual()
 *
 */

template <typename T>
bool Vec3D_IsGreaterThan(const Vector3D<T>& v1, const Vector3D<T>& v2);
/**
 *  \param v1 First Vector3D.
 *  \param v2 Second Vector3D.
 *
 *  \brief Logically compare two Vector3D quantities.
 *
 *  \return Returns true or false.
 *
 *  \sa Vec3D_IsLessThan()
 *
 */
 
template <typename T>
bool Vec3D_IsLessThan(const Vector3D<T>& v1, const Vector3D<T>& v2);
/**
 *  \param v1 First Vector3D.
 *  \param v2 Second Vector3D.
 *
 *  \brief Logically compare two Vector3D quantities.
 *
 *  \return Returns true or false.
 *
 *  \sa Vec3D_IsGreaterThan()
 *
 */
 
/** For printing Vector3D on console, For debugging Purposes */
template <typename T>
std::ostream& operator<<(std::ostream str, Vector3D<T>& vec);

} // namespace Math

} // namespace Game

#endif // VECTOR3D_HPP_
