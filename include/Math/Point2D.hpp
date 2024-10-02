/** 
 *  \file Point2D.hpp
 *  
 *  \brief Header file for Point2D of Numbers.
 *
 *  This supports Point on 2 dimesionsal related functions.
 *
 *  \author IndieGameSmith
 *  \date 2024-08-25
 */

#ifndef POINT2D_HPP_
#define POINT2D_HPP_

#include <iostream>
#include "Vector2D.hpp"

namespace Game
{
    
namespace Math
{
    
enum class Point2D_Round_Flag
{
    ToFloor,
    ToCeil,
    ToNearest
};

    
template <typename T>
struct Point2D
{
    Point2D();
    Point2D(T x, T y);

    bool operator==(const Point2D<T>& other) const;
    bool operator!=(const Point2D<T>& other) const;

    double DotProduct(const Point2D<T>& other) const;
    double CrossProduct(const Point2D<T>& other) const;
    double Magnitude() const;
    Point2D<T> Normalize() const;
    double DistanceFrom(const Point2D<T>& other) const;
    double DistanceFromLine(const Vector2D<T>& lineStart, const Vector2D<T>& lineEnd) const;
    Point2D<T> Rotate(const double angle);
    void Clamp(const Point2D<T>& min, const Point2D<T>& max);
    Point2D<T> Round(const Point2D_Round_Flag& flag);
    Point2D<T> Lerp(const Point2D<T>& other, const float t) const;
    
    Point2D<T> GetPoint() const;
    void SetPoint(T x, T y);

    T x, y;
};

/** Mathematical Opreations */
template <typename T>
double Point2D_DotProduct(const Point2D<T>& p1, const Point2D<T>& p2);
/**
 *  \param p1 First Point2D.
 *  \param p2 Second Point2D.
 *
 *  \brief Dot product of 2 Point2D quantities.
 *  
 *  \returns a Rsultant Point2D quantity.
 *  
 *  \sa Point2D_Normalize()
 *  \sa Point2D_Magnitude()
 *  \sa Point2D_Distance()
 *
 */
template <typename T>
double Point2D_CrossProduct(const Point2D<T>& p1, const Point2D<T>& p2);
/**
 *  \param p1 First Point2D.
 *  \param p2 Second Point2D.
 *
 *  \brief Cross product of 2 Point2D quantities.
 *  
 *  \returns a Rsultant Point2D quantity.
 *  
 *  \sa Point2D_DotProduct()
 *
 */
template <typename T>
double Point2D_Magnitude(const Point2D<T>& p);
/**
 *  \param p Point2D.
 *
 *  \brief Magnitude of a Point2D.
 *  
 *  \returns a Rsultant Floating point quantity.
 *
 *  \sa Point2D_Normalize()
 *  \sa Point2D_DotProduct()
 *  \sa Point2D_Distance()
 *
 */
template <typename T>
Point2D<T> Point2D_Normalize(Point2D<T>& p);
/**
 *  \param p Point2D.
 *
 *  \brief Normalizes of a Point2D.
 *  
 *  \returns a Rsultant Floating point quantity.
 *
 *  \sa Point2D_Magnitude()
 *  \sa Point2D_DotProduct()
 *  \sa Point2D_Distance()
 *
 */

template <typename T>
double Point2D_Distance(const Point2D<T>& p1, const Point2D<T>& p2);
/** 
 *  \param p1 First Point2D.
 *  \param p2 Second Point2D.
 *  
 *  \brief Calculates Distance between 2 Point2D.
 *
 *  \returns Resulting distance.
 *
 *  \sa Point2D_Normalize()
 *  \sa Point2D_DotProduct()
 *  \sa Point2D_Magnitude()
 */

template <typename T>
double Point2D_DistanceFromLine(const Point2D<T>& point, const Vector2D<T>& lineStart, const Vector2D<T>& lineEnd);
/** 
 *  \param point Given Point2D.
 *  \param lineStart Start Point of line
 *  \param MaxClampPoint End Point of line.
 *  
 *  \brief calculates distance..
 *
 *  \returns Returns Resulting Point2D.
 */
 
template <typename T>
Point2D<T> Point2D_Rotate(Point2D<T>& point, const double angle);
/**
 *  \param point Given Point2D.
 *  \param angle Angle of rotation.
 *  
 *  \brief Rotates the point.
 *
 *  \returns Returns Resulting Point2D.
 */
 
template <typename T>
void Point2D_Clamp(Point2D<T>& GivenPoint, const Point2D<T>& MinClampPoint, const Point2D<T>& MaxClampPoint);
/** 
 *  \param GivenPoint Given Point2D.
 *  \param MinClampPoint Min point
 *  \param MaxClampPoint Max point.
 *  
 *  \brief Clamps GivenPoint.
 */
 
template <typename T>
Point2D<T> Point2D_Round(Point2D<T>& p, const Point2D_Round_Flag& flag);
/** 
 *  \param p Given Point2D.
 *  \param flag Flag for rounding Point2D.
 *  
 *  \brief Rounds p depending on flag.
 *
 *  \returns Returns Resulting Point2D.
 */
template <typename T>
Point2D<T> Point2D_Lerp(const Point2D<T>& p1, const Point2D<T>& p2, const float t);
/**
 *  \param p1 First Point2D.
 *  \param p2 Second Point2D.
 *  \param t  Interpolation Factor ranges from 0 =< t =< 1.
 *
 *  \brief Linearly interpolate 2 Point2D.
 *
 *  \return Returns Lerp Point2D.
 */

/** Logical Operations */
template <typename T>
bool Point2D_IsEqual(const Point2D<T>& p1, const Point2D<T>& p2);
/**
 *  \param p1 First Point2D.
 *  \param p2 Second Point2D.
 *
 *  \brief Logically compare two Point2D quantities.
 *
 *  \return Returns true or false.
 *
 *  \sa Point2D_IsNotEqual()
 *
 */
template <typename T>
bool Point2D_IsNotEqual(const Point2D<T>& p1, const Point2D<T>& p2);
/**
 *  \param p1 First Point2D.
 *  \param p2 Second Point2D.
 *
 *  \brief Logically compare two Point2D quantities.
 *
 *  \return Returns true or false.
 *
 *  \sa Point2D_IsEqual()
 *
 */

/** For printing Point2D on console, For debugging Purposes */
template <typename T>
std::ostream &operator<<(std::ostream str, Point2D<T>& p);

} // namespace Math

} // namespace Game

#endif // POINT2D_HPP_
