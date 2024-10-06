/** 
 *  \file Point3D.hpp
 *  
 *  \brief Header file for Point3D of Numbers.
 *
 *  This supports Point on 3 dimesionsal related functions.
 *
 *  \author IndieGameSmith
 *  \date 2024-08-25
 */

#ifndef POINT3D_HPP_
#define POINT3D_HPP_

#include <iostream>
#include "Vector3D.hpp"

namespace Game
{
    
namespace Math
{
    
enum class Point3D_Round_Flag
{
    ToFloor,
    ToCeil,
    ToNearest
};

    
template <typename T>
struct Point3D
{
    Point3D();
    Point3D(T x, T y);

    bool operator==(const Point3D<T>& other) const;
    bool operator!=(const Point3D<T>& other) const;

    double DotProduct(const Point3D<T>& other) const;
    double CrossProduct(const Point3D<T>& other) const;
    double Magnitude() const;
    Point3D<T> Normalize() const;
    double DistanceFrom(const Point3D<T>& other) const;
    double DistanceFromLine(const Vector2D<T>& lineStart, const Vector2D<T>& lineEnd) const;
    Point3D<T> Rotate(const double angle);
	Point3D<T> Translate(const T a, const T b);
    void Clamp(const Point3D<T>& min, const Point3D<T>& max);
    Point3D<T> Round(const Point3D_Round_Flag& flag);
    Point3D<T> Lerp(const Point3D<T>& other, const float t) const;
    
    Point3D<T> GetPoint() const;
    void SetPoint(T x, T y);

    T x, y, z;
};

/** Mathematical Opreations */
template <typename T>
double Point3D_DotProduct(const Point3D<T>& p1, const Point3D<T>& p2);
/**
 *  \param p1 First Point3D.
 *  \param p2 Second Point3D.
 *
 *  \brief Dot product of 2 Point3D quantities.
 *  
 *  \returns a Rsultant Point3D quantity.
 *  
 *  \sa Point3D_Normalize()
 *  \sa Point3D_Magnitude()
 *  \sa Point3D_Distance()
 *
 */
template <typename T>
double Point3D_CrossProduct(const Point3D<T>& p1, const Point3D<T>& p2);
/**
 *  \param p1 First Point3D.
 *  \param p2 Second Point3D.
 *
 *  \brief Cross product of 2 Point3D quantities.
 *  
 *  \returns a Rsultant Point3D quantity.
 *  
 *  \sa Point3D_DotProduct()
 *
 */
template <typename T>
double Point3D_Magnitude(const Point3D<T>& p);
/**
 *  \param p Point3D.
 *
 *  \brief Magnitude of a Point3D.
 *  
 *  \returns a Rsultant Floating point quantity.
 *
 *  \sa Point3D_Normalize()
 *  \sa Point3D_DotProduct()
 *  \sa Point3D_Distance()
 *
 */
template <typename T>
Point3D<T> Point3D_Normalize(Point3D<T>& p);
/**
 *  \param p Point3D.
 *
 *  \brief Normalizes of a Point3D.
 *  
 *  \returns a Rsultant Floating point quantity.
 *
 *  \sa Point3D_Magnitude()
 *  \sa Point3D_DotProduct()
 *  \sa Point3D_Distance()
 *
 */

template <typename T>
double Point3D_Distance(const Point3D<T>& p1, const Point3D<T>& p2);
/** 
 *  \param p1 First Point3D.
 *  \param p2 Second Point3D.
 *  
 *  \brief Calculates Distance between 2 Point3D.
 *
 *  \returns Resulting distance.
 *
 *  \sa Point3D_Normalize()
 *  \sa Point3D_DotProduct()
 *  \sa Point3D_Magnitude()
 */

template <typename T>
double Point3D_DistanceFromLine(const Point3D<T>& point, const Vector2D<T>& lineStart, const Vector2D<T>& lineEnd);
/** 
 *  \param point Given Point3D.
 *  \param lineStart Start Point of line
 *  \param MaxClampPoint End Point of line.
 *  
 *  \brief calculates distance..
 *
 *  \returns Returns Resulting Point3D.
 */
 
template <typename T>
Point3D<T> Point3D_Rotate(Point3D<T>& point, const double angle);
/**
 *  \param point Given Point3D.
 *  \param angle Angle of rotation.
 *  
 *  \brief Rotates the point.
 *
 *  \returns Returns Resulting Point3D.
 */

template <typename T>
Point3D<T> Point3D_Translate(Point3D<T>& point, const T a, const T b);
 
template <typename T>
void Point3D_Clamp(Point3D<T>& GivenPoint, const Point3D<T>& MinClampPoint, const Point3D<T>& MaxClampPoint);
/** 
 *  \param GivenPoint Given Point3D.
 *  \param MinClampPoint Min point
 *  \param MaxClampPoint Max point.
 *  
 *  \brief Clamps GivenPoint.
 */
 
template <typename T>
Point3D<T> Point3D_Round(Point3D<T>& p, const Point3D_Round_Flag& flag);
/** 
 *  \param p Given Point3D.
 *  \param flag Flag for rounding Point3D.
 *  
 *  \brief Rounds p depending on flag.
 *
 *  \returns Returns Resulting Point3D.
 */
template <typename T>
Point3D<T> Point3D_Lerp(const Point3D<T>& p1, const Point3D<T>& p2, const float t);
/**
 *  \param p1 First Point3D.
 *  \param p2 Second Point3D.
 *  \param t  Interpolation Factor ranges from 0 =< t =< 1.
 *
 *  \brief Linearly interpolate 2 Point3D.
 *
 *  \return Returns Lerp Point3D.
 */

/** Logical Operations */
template <typename T>
bool Point3D_IsEqual(const Point3D<T>& p1, const Point3D<T>& p2);
/**
 *  \param p1 First Point3D.
 *  \param p2 Second Point3D.
 *
 *  \brief Logically compare two Point3D quantities.
 *
 *  \return Returns true or false.
 *
 *  \sa Point3D_IsNotEqual()
 *
 */
template <typename T>
bool Point3D_IsNotEqual(const Point3D<T>& p1, const Point3D<T>& p2);
/**
 *  \param p1 First Point3D.
 *  \param p2 Second Point3D.
 *
 *  \brief Logically compare two Point3D quantities.
 *
 *  \return Returns true or false.
 *
 *  \sa Point3D_IsEqual()
 *
 */

/** For printing Point3D on console, For debugging Purposes */
template <typename T>
std::ostream &operator<<(std::ostream str, Point3D<T>& p);

} // namespace Math

} // namespace Game

#endif // POINT3D_HPP_
