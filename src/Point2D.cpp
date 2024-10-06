/** 
 *  \file Point2D.cpp
 *  
 *  \brief Source file for Point2D.hpp.
 *
 *  This supports Point related functions.
 *
 *  \author IndieGameSmith
 *  \date 2024-08-25
 */

#include "Maths/Point2D.hpp"
#include "Utils/Exceptions/Math_Exception.hpp"

#include <iostream>
#include <cmath>

constexpr double POINT2D_TOLERANCE_VALUE = 1e-6;

template <typename T>
std::ostream& operator<<(std::ostream &str, Game::Math::Point2D<T> const &p)
{
	str << "[" << p.x << ", " << p.y << "]";
	return str;
}

template <typename T>
Game::Math::Point2D<T> :: Point2D() : x(0.0f), y(0.0f)
{
    
}

template <typename T>
Game::Math::Point2D<T> :: Point2D(T p_x, T p_y) : x(p_x), y(p_y)
{
    
}

template <typename T>
bool Game::Math::Point2D<T> :: operator==(const Point2D<T>& other) const
{
    return x == other.x && y == other.y;
}

template <typename T>
bool Game::Math::Point2D<T> :: operator!=(const Point2D<T>& other) const
{
    return !(x == other.x && y == other.y);
}

template <typename T>
double Game::Math::Point2D<T> :: DotProduct(const Game::Math::Point2D<T>& other) const
{
    return x * other.x + y * other.y;
}

template <typename T>
double Game::Math::Point2D<T> :: CrossProduct(const Game::Math::Point2D<T>& other) const
{
    return x * other.x - y * other.y;
}

template <typename T>
double Game::Math::Point2D<T> :: Magnitude() const
{
	return std::sqrt(x * x + y * y);
}

template <typename T>
Game::Math::Point2D<T> Game::Math::Point2D<T> :: Normalize() const
{
	double mag = Magnitude();
    
    Point2D<T> NormalizedPoint;
    
    if (std::abs(mag) < POINT2D_TOLERANCE_VALUE)
    {
        NormalizedPoint.x = NormalizedPoint.y = 0.0f;
    }
    NormalizedPoint = Point2D<T>(x / mag, y / mag);
    
    *this = NormalizedPoint;
    return NormalizedPoint;
}

template <typename T>
double Game::Math::Point2D<T> :: DistanceFrom(const Game::Math::Point2D<T>& other) const
{
    double dx = other.x - x;
    double dy = other.y - y;
    return std::sqrt(dx * dx + dy * dy);
}

template <typename T>
double Game::Math::Point2D<T> :: DistanceFromLine(const Game::Math::Vector2D<T>& lineStart, const Game::Math::Vector2D<T>& lineEnd) const
{
    Game::Math::Vector2D point(x, y);
    Game::Math::Vector2D pointToLineVector = lineStart - point;
    Game::Math::Vector2D lineDirection = lineEnd - lineStart;
    lineDirection.Normalize();
    Game::Math::Vector2D lineNormal = lineDirection.Perpendicular();
    return std::abs(pointToLineVector.DotProduct(lineNormal));
}

template <typename T>
Game::Math::Point2D<T> Game::Math::Point2D<T> :: Rotate(const double angle)
{
    double cosTheta = std::cos(angle);
    double sinTheta = std::sin(angle);
    
    // This could be done by Matrix2f But I preferred to do it like this
    Game::Math::Point2D<T> RotatedPoint(
                                          x * cosTheta - y * sinTheta,
                                          x * sinTheta + y * cosTheta
                                         );
    *this = RotatedPoint;
    return RotatedPoint;
}

template <typename T>
Game::Math::Point2D<T> Game::Math::Point2D<T> :: Translate(const T a, const T b)
{
	Game::Math::Point2D<T> TranslatedPoint(*this.x + a,*this.y + b);
	*this = TranslatedPoint;
	return TranslatedPoint;
}

template <typename T>
void Game::Math::Point2D<T> :: Clamp(const Game::Math::Point2D<T>& min, const Game::Math::Point2D<T>& max)
{
    x = std::clamp(x, min.x, max.x);
    y = std::clamp(y, min.y, max.y);
}

template <typename T>
Game::Math::Point2D<T> Game::Math::Point2D<T> :: Round(const Game::Math::Point2D_Round_Flag& flag)
{
    Point2D<T> RoundedPoint;
    switch (flag)
    {
        case Game::Math::Point2D_Round_Flag::ToFloor:
            RoundedPoint.SetVec((std::floor(x)), (std::floor(y)));
            break;
            
        case Game::Math::Point2D_Round_Flag::ToCeil:
            RoundedPoint.SetVec((std::ceil(x)), (std::ceil(y)));
            break;
            
        case Game::Math::Point2D_Round_Flag::ToNearest:
            RoundedPoint.SetVec((std::round(x)), (std::round(y)));
            break;
            
        default:
            throw Game::Math::Exception::InvalidRoundFlag("Invalid Round Flag");
    }
            
        *this = RoundedPoint;
        return RoundedPoint;
}

template <typename T>
Game::Math::Point2D<T> Game::Math::Point2D<T> :: Lerp(const Game::Math::Point2D<T>& other, const float t) const
{
    T px = x + (other.x - x) * t;
    T py = y + (other.y - y) * t;
    return Point2D<T>(px, py);
}

template <typename T>
Game::Math::Point2D<T> Game::Math::Point2D<T> :: GetPoint() const
{
    return Point2D<T>(x, y);
}

template <typename T>
void Game::Math::Point2D<T> :: SetPoint(T p_x, T p_y)
{
    x = p_x;
    y = p_y;
}

template <typename T>
double Game::Math::Point2D_DotProduct(const Game::Math::Point2D<T>& p1, const Game::Math::Point2D<T>& p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}

template <typename T>
double Game::Math::Point2D_CrossProduct(const Game::Math::Point2D<T>& p1, const Game::Math::Point2D<T>& p2)
{
    return p1.x * p2.x - p1.y * p2.y;
}

template <typename T>
double Game::Math::Point2D_Magnitude(const Game::Math::Point2D<T>& p)
{
    return std::sqrt(p.x * p.x + p.y * p.y);
}

template <typename T>
Game::Math::Point2D<T> Game::Math::Point2D_Normalize(Game::Math::Point2D<T>& p)
{
    double mag = Game::Math::Point2D_Magnitude(p);
    
    Point2D<T> NormalizedPoint;
    
    if (std::abs(mag) < POINT2D_TOLERANCE_VALUE)
    {
        NormalizedPoint.x = NormalizedPoint.y = 0.0f;
    }
    NormalizedPoint = Point2D<T>(p.x / mag, p.y / mag);
    
    p = NormalizedPoint;
    return NormalizedPoint;
}

template <typename T>
double Game::Math::Point2D_Distance(const Game::Math::Point2D<T>& p1, const Game::Math::Point2D<T>& p2)
{
   double dx = p2.x - p1.x;
   double dy = p2.y - p1.y;
   
   return sqrt(dx * dx + dy * dy);
}

template <typename T>
double Game::Math::Point2D_DistanceFromLine(const Game::Math::Point2D<T>& p, const Game::Math::Vector2D<T>& lineStart, const Game::Math::Vector2D<T>& lineEnd)
{
    Game::Math::Vector2D point(p.x, p.y);
    Game::Math::Vector2D pointToLineVector = lineStart - point;
    Game::Math::Vector2D lineDirection = lineEnd - lineStart;
    lineDirection.Normalize();
    Game::Math::Vector2D lineNormal = lineDirection.Perpendicular();
    return std::abs(pointToLineVector.DotProduct(lineNormal));
}

template <typename T>
Game::Math::Point2D<T> Game::Math::Point2D_Rotate(Game::Math::Point2D<T>& Point, const double angle)
{
    double cosTheta = std::cos(angle);
    double sinTheta = std::sin(angle);
    
    // This could be done by Matrix2f But I preferred to do it like this
    Game::Math::Point2D<T> RotatedPoint(
                                          Point.x * cosTheta - Point.y * sinTheta,
                                          Point.x * sinTheta + Point.y * cosTheta
                                         );
    Point = RotatedPoint;
    return RotatedPoint;
}

template <typename T>
Game::Math::Point2D<T> Game::Math::Point2D_Translate(Game::Math::Point2D<T> Point, const T a, const T b)
{
	Game::Math::Point2D<T> TranslatedPoint(Point.x + a,Point.y + b);
	Point = TranslatedPoint;
	return TranslatedPoint;
}

template <typename T>
void Game::Math::Point2D_Clamp(Game::Math::Point2D<T>& Point, const Game::Math::Point2D<T>& min, const Game::Math::Point2D<T>& max)
{
    Point.x = std::clamp(Point.x, min.x, max.x);
    Point.y = std::clamp(Point.y, min.y, max.y);
}

template <typename T>
Game::Math::Point2D<T> Game::Math::Point2D_Round(Game::Math::Point2D<T>& p, const Game::Math::Point2D_Round_Flag& flag)
{
    Point2D<T> RoundedPoint;
    switch (flag)
    {
        case Game::Math::Point2D_Round_Flag::ToFloor:
            RoundedPoint.SetPoint((std::floor(p.x)), (std::floor(p.y)));
	    break;
            
        case Game::Math::Point2D_Round_Flag::ToCeil:
            RoundedPoint.SetPoint((std::ceil(p.x)), (std::ceil(p.y)));
	    break;
            
        case Game::Math::Point2D_Round_Flag::ToNearest:
            RoundedPoint.SetPoint((std::round(p.x)), (std::round(p.y)));
	    break;
            
        default:
            throw Game::Math::Exception::InvalidRoundFlag("Invalid Round Flag");
    }
            
        p = RoundedPoint;
        return RoundedPoint;
}

template <typename T>
Game::Math::Point2D<T> Game::Math::Point2D_Lerp(const Game::Math::Point2D<T>& start, const Game::Math::Point2D<T>& end, const float t)
{
    T x = start.x + (end.x - start.x) * t;
    T y = start.y + (end.y - start.y) * t;
    return Point2D<T>(x, y);
}

template <typename T>
bool Game::Math::Point2D_IsEqual(const Game::Math::Point2D<T>& p1, const Game::Math::Point2D<T>& p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

template <typename T>
bool Game::Math::Point2D_IsNotEqual(const Game::Math::Point2D<T>& p1, const Game::Math::Point2D<T>& p2)
{
    return !(p1.x == p2.x && p1.y == p2.y);
}
