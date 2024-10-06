/** 
 *  \file Point3D.cpp
 *  
 *  \brief Source file for Point3D.hpp.
 *
 *  This supports Point related functions.
 *
 *  \author IndieGameSmith
 *  \date 2024-08-25
 */

#include "Math/Point3D.hpp"
#include "Utils/Exceptions/Math_Exception.hpp"

#include <iostream>
#include <cmath>

constexpr double POINT3D_TOLERANCE_VALUE = 1e-6;

template <typename T>
std::ostream& operator<<(std::ostream &str, Game::Math::Point3D<T> const &p)
{
	str << "[" << p.x << ", " << p.y << p.z << "]";
	return str;
}

template <typename T>
Game::Math::Point3D<T> :: Point3D() : x(0.0f), y(0.0f)
{
    
}

template <typename T>
Game::Math::Point3D<T> :: Point3D(T p_x, T p_y, T p_z) : x(p_x), y(p_y), z(p_z)
{
    
}

template <typename T>
bool Game::Math::Point3D<T> :: operator==(const Point3D<T>& other) const
{
    return x == other.x && y == other.y && z == other.z;
}

template <typename T>
bool Game::Math::Point3D<T> :: operator!=(const Point3D<T>& other) const
{
    return !(x == other.x && y == other.y && z == other.z);
}

template <typename T>
double Game::Math::Point3D<T> :: DotProduct(const Game::Math::Point3D<T>& other) const
{
    return x * other.x + y * other.y + z * other.z;
}

template <typename T>
double Game::Math::Point3D<T> :: CrossProduct(const Game::Math::Point3D<T>& other) const
{
    Point3D<T> result;

	result.x = y * other.z - z * other.y;
	result.y = z * other.x - x * other.z;
	result.z = x * other.y - y * other.x;

	return result;
}

template <typename T>
double Game::Math::Point3D<T> :: Magnitude() const
{
	return std::sqrt(x * x + y * y + z * z);
}

template <typename T>
Game::Math::Point3D<T> Game::Math::Point3D<T> :: Normalize() const
{
	double mag = Magnitude();
    
    Point3D<T> NormalizedPoint;
    
    if (std::abs(mag) < POINT3D_TOLERANCE_VALUE)
    {
        NormalizedPoint.x = NormalizedPoint.y = NormalizedPoint.z = 0.0f;
    }
    NormalizedPoint = Point3D<T>(x / mag, y / mag, z / mag);
    
    *this = NormalizedPoint;
    return NormalizedPoint;
}

template <typename T>
double Game::Math::Point3D<T> :: DistanceFrom(const Game::Math::Point3D<T>& other) const
{
    double dx = other.x - x;
    double dy = other.y - y;
    double dz = other.z - z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

template <typename T>
double Game::Math::Point3D<T> :: DistanceFromLine(const Game::Math::Vector3D<T>& lineStart, const Game::Math::Vector3D<T>& lineEnd) const
{
    Game::Math::Vector3D point(x, y, z);
    Game::Math::Vector3D pointToLineVector = lineStart - point;
    Game::Math::Vector3D lineDirection = lineEnd - lineStart;
    lineDirection.Normalize();
    Game::Math::Vector3D lineNormal = lineDirection.Perpendicular();
    return std::abs(pointToLineVector.DotProduct(lineNormal));
}

template <typename T>
Game::Math::Point3D<T> Game::Math::Point3D<T> :: Rotate(const double angle)
{
    Game::Math::Vector3D<T> Vec(x, y, z);
    double cosTheta = std::cos(angle);
    double sinTheta = std::sin(angle);
    
    // Create the rotation matrix
    Matrix3D<T> rotationMatrix(
        cosTheta, -sinTheta, 0,
        sinTheta, cosTheta, 0,
        0, 0, 1
    );
    
    Game::Math::Vector3D<T> _RotatedPoint = Vec * rotationMatrix;
    Game::Math::Point3D<T> RotatedPoint(_RotatedPoint.x, _RotatedPoint.y, RotatedPoint.z);
    *this = RotatedPoint;
    return RotatedPoint;
}

template <typename T>
Game::Math::Point3D<T> Game::Math::Point3D<T> :: Translate(const T a, const T b, const T c)
{
	Game::Math::Point3D<T> TranslatedPoint(x + a, y + b, z + c);
	*this = TranslatedPoint;
	return TranslatedPoint;
}

template <typename T>
void Game::Math::Point3D<T> :: Clamp(const Game::Math::Point3D<T>& min, const Game::Math::Point3D<T>& max)
{
    x = std::clamp(x, min.x, max.x);
    y = std::clamp(y, min.y, max.y);
    z = std::clamp(z, min.z, max.z);
}

template <typename T>
Game::Math::Point3D<T> Game::Math::Point3D<T> :: Round(const Game::Math::Point3D_Round_Flag& flag)
{
    Point3D<T> RoundedPoint;
    switch (flag)
    {
        case Game::Math::Point3D_Round_Flag::ToFloor:
            RoundedPoint.SetVec((std::floor(x)), (std::floor(y)), (std::floor(z)));
            break;
            
        case Game::Math::Point3D_Round_Flag::ToCeil:
            RoundedPoint.SetVec((std::ceil(x)), (std::ceil(y)), (std::ceil(z)));
            break;
            
        case Game::Math::Point3D_Round_Flag::ToNearest:
            RoundedPoint.SetVec((std::round(x)), (std::round(y)), (std::round(z)));
            break;
            
        default:
            throw Game::Math::Exception::InvalidRoundFlag("Invalid Round Flag");
    }
            
        *this = RoundedPoint;
        return RoundedPoint;
}

template <typename T>
Game::Math::Point3D<T> Game::Math::Point3D<T> :: Lerp(const Game::Math::Point3D<T>& other, const float t) const
{
    T px = x + (other.x - x) * t;
    T py = y + (other.y - y) * t;
    T pz = z + (other.z - z) * t;
    return Point3D<T>(px, py, pz);
}

template <typename T>
Game::Math::Point3D<T> Game::Math::Point3D<T> :: GetPoint() const
{
    return Point3D<T>(x, y, z);
}

template <typename T>
void Game::Math::Point3D<T> :: SetPoint(T p_x, T p_y, T p_z)
{
    x = p_x;
    y = p_y;
    z = p_z;
}

template <typename T>
double Game::Math::Point3D_DotProduct(const Game::Math::Point3D<T>& p1, const Game::Math::Point3D<T>& p2)
{
    return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}

template <typename T>
double Game::Math::Point3D_CrossProduct(const Game::Math::Point3D<T>& p1, const Game::Math::Point3D<T>& p2)
{
    Point3D<T> result;

	result.x = p1.y * p2.z - p1.z * p2.y;
	result.y = p1.z * p2.x - p1.x * p2.z;
	result.z = p1.x * p2.y - p1.y * p2.x;

	return result;
}

template <typename T>
double Game::Math::Point3D_Magnitude(const Game::Math::Point3D<T>& p)
{
    return std::sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

template <typename T>
Game::Math::Point3D<T> Game::Math::Point3D_Normalize(Game::Math::Point3D<T>& p)
{
    double mag = Game::Math::Point3D_Magnitude(p);
    
    Point3D<T> NormalizedPoint;
    
    if (std::abs(mag) < POINT3D_TOLERANCE_VALUE)
    {
        NormalizedPoint.x = NormalizedPoint.y = NormalizedPoint.z = 0.0f;
    }
    NormalizedPoint = Point3D<T>(p.x / mag, p.y / mag, p.z / mag);
    
    p = NormalizedPoint;
    return NormalizedPoint;
}

template <typename T>
double Game::Math::Point3D_Distance(const Game::Math::Point3D<T>& p1, const Game::Math::Point3D<T>& p2)
{
   double dx = p2.x - p1.x;
   double dy = p2.y - p1.y;
   double dz = p2.z - p1.z;
      
   return sqrt(dx * dx + dy * dy + dz * dz);
}

template <typename T>
double Game::Math::Point3D_DistanceFromLine(const Game::Math::Point3D<T>& p, const Game::Math::Vector3D<T>& lineStart, const Game::Math::Vector3D<T>& lineEnd)
{
    Game::Math::Vector3D point(p.x, p.y, p.z);
    Game::Math::Vector3D pointToLineVector = lineStart - point;
    Game::Math::Vector3D lineDirection = lineEnd - lineStart;
    lineDirection.Normalize();
    Game::Math::Vector3D lineNormal = lineDirection.Perpendicular();
    return std::abs(pointToLineVector.DotProduct(lineNormal));
}

template <typename T>
Game::Math::Point3D<T> Game::Math::Point3D_Rotate(Game::Math::Point3D<T>& point, const double angle)
{
    Game::Math::Vector3D<T> Vec(point.x, point.y, point.z);
    double cosTheta = std::cos(angle);
    double sinTheta = std::sin(angle);
    
    // Create the rotation matrix
    Matrix3D<T> rotationMatrix(
        cosTheta, -sinTheta, 0,
        sinTheta, cosTheta, 0,
        0, 0, 1
    );
    
    Game::Math::Vector3D<T> _RotatedPoint = Vec * rotationMatrix;
    Game::Math::Point3D<T> RotatedPoint(_RotatedPoint.x, _RotatedPoint.y, RotatedPoint.z);
    point = RotatedPoint;
    return RotatedPoint;
}

template <typename T>
Game::Math::Point3D<T> Game::Math::Point3D_Translate(Game::Math::Point3D<T>& Point, const T a, const T b, const T c)
{
	Game::Math::Point3D<T> TranslatedPoint(Point.x + a, Point.y + b, Point.z + c);
	Point = TranslatedPoint;
	return TranslatedPoint;
}

template <typename T>
void Game::Math::Point3D_Clamp(Game::Math::Point3D<T>& Point, const Game::Math::Point3D<T>& min, const Game::Math::Point3D<T>& max)
{
    Point.x = std::clamp(Point.x, min.x, max.x);
    Point.y = std::clamp(Point.y, min.y, max.y);
    Point.z = std::clamp(Point.z , min.z, max.z);
}

template <typename T>
Game::Math::Point3D<T> Game::Math::Point3D_Round(Game::Math::Point3D<T>& p, const Game::Math::Point3D_Round_Flag& flag)
{
    Point3D<T> RoundedPoint;
    switch (flag)
    {
        case Game::Math::Point3D_Round_Flag::ToFloor:
            RoundedPoint.SetPoint((std::floor(p.x)), (std::floor(p.y)), (std::floor(p.z)));
	    break;
            
        case Game::Math::Point3D_Round_Flag::ToCeil:
            RoundedPoint.SetPoint((std::ceil(p.x)), (std::ceil(p.y)), (std::ceil(p.z)));
	    break;
            
        case Game::Math::Point3D_Round_Flag::ToNearest:
            RoundedPoint.SetPoint((std::round(p.x)), (std::round(p.y)), (std::round(p.z)));
	    break;
            
        default:
            throw Game::Math::Exception::InvalidRoundFlag("Invalid Round Flag");
    }
            
        p = RoundedPoint;
        return RoundedPoint;
}

template <typename T>
Game::Math::Point3D<T> Game::Math::Point3D_Lerp(const Game::Math::Point3D<T>& start, const Game::Math::Point3D<T>& end, const float t)
{
    T x = start.x + (end.x - start.x) * t;
    T y = start.y + (end.y - start.y) * t;
    T z = start.z + (end.z - start.z) * t;
    return Point3D<T>(x, y, z);
}

template <typename T>
bool Game::Math::Point3D_IsEqual(const Game::Math::Point3D<T>& p1, const Game::Math::Point3D<T>& p2)
{
    return p1.x == p2.x && p1.y == p2.y && p1.z == p2.z;
}

template <typename T>
bool Game::Math::Point3D_IsNotEqual(const Game::Math::Point3D<T>& p1, const Game::Math::Point3D<T>& p2)
{
    return !(p1.x == p2.x && p1.y == p2.y && p1.z == p2.z);
}
