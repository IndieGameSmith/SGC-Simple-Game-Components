/** 
 *  \file Vector2T.hpp
 *  
 *  \brief Header file for Vector2T of 2 Ting point integers.
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

template <typename T>
struct Vector2T
{
    Vector2T();
    Vector2T(T x, T y);

	Vector2T operator+(const Vector2T& other) const;
	Vector2T operator-(const Vector2T& other) const;
	Vector2T operator*(double scaler) const;
	Vector2T operator*(const Game::Math::Matrix2f& matrix) const;
	Vector2T operator/(double scaler) const;
	bool operator==(const Vector2T& other) const;
	bool operator!=(const Vector2T& other) const;
	
	Vector2T Add(const Vector2T& other) const;
	Vector2T Sub(const Vector2T& other) const;
	Vector2T Multiply(const double scaler) const;
	Vector2T Divide(const double scaler) const;
	double DotProduct(const Vector2T& other) const;
	double CrossProduct(const Vector2T& other) const;
	double Magnitude() const;
	Vector2T Normalize() const;
	
	Vector2T GetVec() const;
	void SetVec(T x, T y);
    
    T x, y;
};

enum class Vec2T_Round_Flag
{
    ToFloor,
    ToCeil,
    ToNearest
};

/** Mathematical Opreations */
template <typename T>
Vector2T<T> Vec2T_Add(const Vector2T<T>& v1, const Vector2T<T>& v2);
/**
 *  \param v1 First Vector2T.
 *  \param v2 Second Vector2T.
 *
 *  \brief Add two Vector2T quantities.
 *
 *  \return Returns a Resultant Vector2T quantity.
 *
 *  \sa Vec2T_Subtract()
 *  \sa Vec2T_Multiply()
 *  \sa Vec2T_Divide()
 *
 */
template <typename T>
Vector2T<T> Vec2T_Subtract(const Vector2T<T>& v1, const Vector2T<T>& v2);
/**
 *  \param v1 First Vector2T.
 *  \param v2 Second Vector2T.
 *
 *  \brief Subtract two Vector2T quantities.
 *
 *  \return Returns a Resultant Vector2T quantity.
 *
 *  \sa Vec2T_Add()
 *  \sa Vec2T_Multiply()
 *  \sa Vec2T_Divide()
 *
 */
template <typename T>
Vector2T<T> Vec2T_Multiply(const Vector2T<T>& v, const double scaler);
/**
 *  \param v Vector2T quantity.
 *  \param scaler Scaler quantity to be mutilplied.
 *
 *  \brief Multipy a Vector2T quantity with a scaler.
 *
 *  \return Returns a Resultant Vector2T quantity.
 *
 *  \sa Vec2T_Add()
 *  \sa Vec2T_Subtract()
 *  \sa Vec2T_Divide()
 *
 */
template <typename T>
Vector2T<T> Vec2T_Multiply(const Vector2T<T>& v1, const Vector2T<T>& v2);
/**
 *  \param v1 Vector2T quantity.
 *  \param v2 Vector2T quantity.
 *
 *  \brief Multipy a Vector2T quantity with other Vector2T quantity.
 *
 *  \return Returns a Resultant Vector2T quantity.
 *
 *  \sa Vec2T_Add()
 *  \sa Vec2T_Subtract()
 *  \sa Vec2T_Divide()
 *
 */
template <typename T>
Vector2T<T> Vec2T_Divide(const Vector2T<T>& v, const double scaler);
/**
 *  \param v Vector2T quantity.
 *  \param scaler Scaler quantity to be divided.
 *
 *  \brief Multipy a Vector2T quantity with a scaler.
 *
 *  \throw DivisionByZero Error if division by zero '0' occurs.
 *
 *  \return Returns a Resultant Vector2T quantity.
 *
 *
 *  \sa Vec2T_Add()
 *  \sa Vec2T_Subtract()
 *  \sa Vec2T_Multiply()
 *
 */
template <typename T>
Vector2T<T> Vec2T_MultipyByMatrix(const Vector2T<T>& v, const Game::Math::Matrix2f& mat);
/**
 *  \param v Vector2T quantity.
 *  \param mat Matrix2f.
 *
 *  \brief Multipy a Vector2T quantity with Matrix2x 
 *
 *  \return Returns a Resultant Vector2T quantity.
 *
 */
template <typename T>
double Vec2T_DotProduct(const Vector2T<T>& v1, const Vector2T<T>& v2);
/**
 *  \param v1 First Vector2T.
 *  \param v2 Second Vector2T.
 *
 *  \brief Dot product of 2 Vector2T quantities.
 *  
 *  \returns a Rsultant Vector2T quantity.
 *  
 *  \sa Vec2T_Normalize()
 *  \sa Vec2T_Magnitude()
 *  \sa Vec2T_Distance()
 *
 */
template <typename T>
double Vec2T_CrossProduct(const Vector2T<T>& v1, const Vector2T<T>& v2);
/**
 *  \param v1 First Vector2T.
 *  \param v2 Second Vector2T.
 *
 *  \brief Cross product of 2 Vector2T quantities.
 *  
 *  \returns a Rsultant Vector2T quantity.
 *  
 *  \sa Vec2T_DotProduct()
 *
 */
template <typename T>
double Vec2T_Magnitude(const Vector2T<T>& v);
/**
 *  \param v Vector2T.
 *
 *  \brief Magnitude of a Vector2T.
 *  
 *  \returns a Rsultant Floating point quantity.
 *
 *  \sa Vec2T_Normalize()
 *  \sa Vec2T_DotProduct()
 *  \sa Vec2T_Distance()
 *
 */
template <typename T>
Vector2T<T> Vec2T_Normalize(Vector2T<T>& v);
/**
 *  \param v Vector2T.
 *
 *  \brief Normalizes of a Vector2T.
 *  
 *  \returns a Rsultant Floating point quantity.
 *
 *  \sa Vec2T_Magnitude()
 *  \sa Vec2T_DotProduct()
 *  \sa Vec2T_Distance()
 *
 */
template <typename T>
double Vec2T_Distance(const Vector2T<T>& v1, const Vector2T<T>& v2);
/** 
 *  \param v1 First Vector2T.
 *  \param v2 Second Vector2T.
 *  
 *  \brief Calculates Distance between 2 Vector2T.
 *
 *  \returns Resulting distance.
 *
 *  \sa Vec2T_Normalize()
 *  \sa Vec2T_DotProduct()
 *  \sa Vec2T_Magnitude()
 */
template <typename T> 
double Vec2T_Angle(const Vector2T<T>& v1, const Vector2T<T>& v2);
/** 
 *  \param v1 First Vector2T.
 *  \param v2 Second Vector2T.
 *  
 *  \brief Calculates Angle between 2 Vector2T.
 *
 *  \returns Returns Resulting angle.
 */
template <typename T>
Vector2T<T> Vec2T_ProjectOnto(Vector2T<T>& Vector, const Vector2T<T>& Target);
/** 
 *  \param Vector First Vector2T.
 *  \param Target Second Vector2T.
 *  
 *  \brief Project Vector to Target.
 *
 *  \returns Returns Resulting Vector2T.
 */
template <typename T> 
Vector2T<T> Vec2T_Reflect(Vector2T<T>& OrignalVector, const Vector2T<T>& SurfaceNormal);
/** 
 *  \param OrignalVector Vector2T.
 *  \param SurfaceNormal Normal Surface, Vector2T
 *  
 *  \brief Reflectes Orignal Vector.
 *
 *  \returns Returns Resulting Vector2T.
 */
template <typename T>
Vector2T<T> Vec2T_Rotate(Vector2T<T>& v, const double angle);
/** 
 *  \param v Vector2T.
 *  \param angle Angle [Radians] by which v will be rotated.
 *  
 *  \brief Rotates v by angle[in Radians].
 *
 *  \returns Returns Resulting Vector2T.
 */
template <typename T>
void Vec2T_Clamp(Vector2T<T>& GivenVector, const Vector2T<T>& MinClampVector, const Vector2T<T>& MaxClampVector);
/** 
 *  \param GivenVector Given Vector2T.
 *  \param MinClampVector Min range Clamping Vector2T.
 *  \param MaxClampVector Max range Clamping Vector2T.
 *  
 *  \brief Clamps v1 to v2.
 *
 *  \returns Returns Resulting Vector2T.
 */
template <typename T>
Vector2T<T> Vec2T_Round(Vector2T<T>& v, const Vec2T_Round_Flag flag);
/** 
 *  \param v Given Vector2T.
 *  \param flag Flag for rounding Vector2T.
 *  
 *  \brief Rounds v depending on flag.
 *
 *  \returns Returns Resulting Vector2T.
 */
template <typename T>
Vector2T<T> Vec2T_Lerp(const Vector2T<T>& v1, const Vector2T<T>& v2, const float t);
/**
 *  \param v1 First Vector2T.
 *  \param v2 Second Vector2T.
 *  \param t  Interpolation Factor ranges from 0 =< t =< 1.
 *
 *  \brief Linearly interpolate 2 Vector2T.
 *
 *  \return Returns Lerp Vector2T.
 */
 
/** Logical Operations */
template <typename T>
bool Vec2T_IsEqual(const Vector2T<T>& v1, const Vector2T<T>& v2);
/**
 *  \param v1 First Vector2T.
 *  \param v2 Second Vector2T.
 *
 *  \brief Logically compare two Vector2T quantities.
 *
 *  \return Returns true or false.
 *
 *  \sa Vec2T_IsNotEqual()
 *
 */
template <typename T>
bool Vec2T_IsNotEqual(const Vector2T<T>& v1, const Vector2T<T>& v2);
/**
 *  \param v1 First Vector2T.
 *  \param v2 Second Vector2T.
 *
 *  \brief Logically compare two Vector2T quantities.
 *
 *  \return Returns true or false.
 *
 *  \sa Vec2T_IsEqual()
 *
 */
 
/** For printing Vector2T on console, For debugging Purposes */
template <typename T>
std::ostream& operator<<(std::ostream str, Vector2T<T>& vec);

} // namespace Math

} // namespace Game

#endif // VECTOR2F_HPP_
