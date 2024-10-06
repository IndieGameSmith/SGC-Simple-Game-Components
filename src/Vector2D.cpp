/** 
 *  \file Vector2D.cpp
 *  
 *  \brief Source file for Vector2D.
 *
 *  This supports Vector2D related functions.
 *
 *  \author IndieGameSmith
 *  \date 2024-08-23
 */

#include "Maths/Vector2D.hpp"
#include "Utils/Exceptions/Math_Exception.hpp"

#include <iostream>
#include <cmath>

constexpr double VEC2D_TOLERANCE_VALUE = 1e-6;

template <typename T>
std::ostream& operator<<(std::ostream &str, Game::Math::Vector2D<T> const &v)
{
	str << "[" << v.x << ", " << v.y << "]";
	return str;
}

template <typename T>
Game::Math::Vector2D<T> :: Vector2D() : x(0.0f), y(0.0f)
{
    
}

template <typename T>
Game::Math::Vector2D<T> :: Vector2D(T p_x, T p_y) : x(p_x), y(p_y)
{
    
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T> :: operator+(const Game::Math::Vector2D<T>& other) const
{
	return Vector2D<T>(x + other.x, y + other.y);
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T> :: operator-(const Game::Math::Vector2D<T>& other) const
{
	return Vector2D<T>(x - other.x, y - other.y);
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T> :: operator*(const double scaler) const
{
    return Vector2D<T>(x * scaler, y * scaler);
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T>::operator*(const Matrix2D<T>& matrix) const
{
    return Vector2D<T>(
        x * matrix.GetElement(0, 0) + y * matrix.GetElement(1, 0),
        x * matrix.GetElement(0, 1) + y * matrix.GetElement(1, 1)
    );
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T> :: operator/(const double scaler) const
{
	if (scaler == 0)
		throw Game::Math::Exception::DivisionByZero("Can't be divided by 0");
	
	return Vector2D<T>(x / scaler, y / scaler);
}

template <typename T>
bool Game::Math::Vector2D<T> :: operator==(const Vector2D<T>& other) const
{
    return x == other.x && y == other.y;
}

template <typename T>
bool Game::Math::Vector2D<T> :: operator!=(const Vector2D<T>& other) const
{
    return !(x == other.x && y == other.y);
}

template <typename T>
bool Game::Math::Vector2D<T> :: operator<(const Vector2D<T>& other) const
{
    return Magnitude() < other.Magnitude();
}

template <typename T>
bool Game::Math::Vector2D<T> :: operator>(const Vector2D<T>& other) const
{
    return Magnitude() > other.Magnitude();
}

template <typename T>
bool Game::Math::Vector2D<T> :: operator<=(const Vector2D<T>& other) const
{
    return Magnitude() < other.Magnitude() || Magnitude() == other.Magnitude();
}

template <typename T>
bool Game::Math::Vector2D<T> :: operator>=(const Vector2D<T>& other) const
{
    return Magnitude() > other.Magnitude() || Magnitude() == other.Magnitude();
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T> :: Add(const Game::Math::Vector2D<T>& other) const
{
    return Vector2D<T>(x + other.x, y + other.y);
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T> :: Sub(const Game::Math::Vector2D<T>& other) const
{
    return Vector2D<T>(x - other.x, y - other.y);
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T> :: Multiply(const double scaler) const
{
    return Vector2D<T>(x * scaler, y * scaler);
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T> :: Divide(const double scaler) const
{
    if (scaler == 0)
	throw Game::Math::Exception::DivisionByZero("Can't be divided by 0");
	
    return Vector2D<T>(x / scaler, y / scaler);
}

template <typename T>
double Game::Math::Vector2D<T> :: DotProduct(const Game::Math::Vector2D<T>& other) const
{
    return x * other.x + y * other.y;
}

template <typename T>
double Game::Math::Vector2D<T> :: CrossProduct(const Game::Math::Vector2D<T>& other) const
{
    return x * other.x - y * other.y;
}

template <typename T>
double Game::Math::Vector2D<T> :: Magnitude() const
{
    return std::sqrt(x * x + y * y);
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T> :: Normalize() const
{
    double mag = Magnitude();
    
    Vector2D<T> NormalizedVector;
    
    if (std::abs(mag) < VEC2D_TOLERANCE_VALUE)
    {
        NormalizedVector.x = NormalizedVector.y = 0.0f;
    }
    NormalizedVector = Vector2D<T>(x / mag, y / mag);
    
    *this = NormalizedVector;
    return NormalizedVector;
}

template <typename T>
double Game::Math::Vector2D<T> :: DistanceFrom(const Game::Math::Vector2D<T>& other) const
{
    double dx = other.x - x;
    double dy = other.y - y;
    return std::sqrt(dx * dx + dy * dy);
}

template <typename T>
double Game::Math::Vector2D<T> :: Angle(const Game::Math::Vector2D<T>& other) const
{
    double dotProduct = Game::Math::Vec2D_DotProduct(*this, other);
    double v1_magnitude = Game::Math::Vec2D_Magnitude(*this);
    double v2_magnitude = Game::Math::Vec2D_Magnitude(other);
    
    double cosThetha = dotProduct / (v1_magnitude * v2_magnitude);
    double angle = std::acos(cosThetha);
    return angle;
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T> :: ProjectOn(const Game::Math::Vector2D<T>& Target) const
{
    Game::Math::Vector2D<T> Target_Normalized = Game::Math::Vec2D_Normalize(Target);

    double DotProduct = Game::Math::Vec2D_DotProduct(*this, Target_Normalized);
     
    Vector2D<T> ProjectedVector = Game::Math::Vec2D_Multiply(Target_Normalized, DotProduct);
    
    return ProjectedVector;
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T> :: Reflect(const Game::Math::Vector2D<T>& SurfaceNormal)
{
    double DotProduct = Game::Math::Vec2D_DotProduct(*this, SurfaceNormal);
    Vector2D<T> ScaledVector = SurfaceNormal * 2.0f * DotProduct;
    
    Vector2D<T> ReflectedVector = Game::Math::Vec2D_Subtract(*this, ScaledVector);
    *this = ReflectedVector;
    
    return ReflectedVector;
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T> :: Rotate(const double angle)
{
    double cosTheta = std::cos(angle);
    double sinTheta = std::sin(angle);
    
    // This could be done by Matrix2f But I preferred to do it like this
    Game::Math::Vector2D<T> RotatedVector(
                                          x * cosTheta - y * sinTheta,
                                          x * sinTheta + y * cosTheta
                                         );
    *this = RotatedVector;
    return RotatedVector;
}

template <typename T>
void Game::Math::Vector2D<T> :: Clamp(const Vector2D<T>& min, const Vector2D<T>& max)
{
    x = std::clamp(x, min.x, max.x);
    y = std::clamp(y, min.y, max.y);
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T> :: Round(const Game::Math::Vec2D_Round_Flag& flag)
{
    Vector2D<T> RoundedVector;
    switch (flag)
    {
        case Game::Math::Vec2D_Round_Flag::ToFloor:
            RoundedVector.SetVec((std::floor(x)), (std::floor(y)));
	    break;
            
        case Game::Math::Vec2D_Round_Flag::ToCeil:
            RoundedVector.SetVec((std::ceil(x)), (std::ceil(y)));
	    break;
            
        case Game::Math::Vec2D_Round_Flag::ToNearest:
            RoundedVector.SetVec((std::round(x)), (std::round(y)));
	    break;
            
        default:
            throw Game::Math::Exception::InvalidRoundFlag("Invalid Round Flag");
    }
            
        *this = RoundedVector;
        return RoundedVector;
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T> :: Lerp(const Game::Math::Vector2D<T>& other, const float t) const
{
    T x = x + (other.x - x) * t;
    T y = y + (other.y - y) * t;
    return Vector2D<T>(x, y);
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T> :: Perpendicular() const
{
	return Vector2D<T>(-y, x);
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T> :: Translate(const T a, const T b)
{
	Vector2D<T> TranslatedVector(x + a, y + b);
	*this = TranslatedVector;
	return TranslatedVector;
}

template <typename T>
bool Game::Math::Vector2D<T> :: IsEmpty() const
{
	return (Magnitude() == 0.0f);
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T> :: GetVec() const
{
    return Vector2D<T>(x, y);
}

template <typename T>
void Game::Math::Vector2D<T> :: SetVec(T p_x, T p_y)
{
    x = p_x;
    y = p_y;
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vec2D_Add(const Game::Math::Vector2D<T>& v1, const Game::Math::Vector2D<T>& v2)
{
    return Vector2D<T>(v1.x + v2.x, v1.y + v2.y);
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vec2D_Subtract(const Game::Math::Vector2D<T>& v1, const Game::Math::Vector2D<T>& v2)
{
    return Vector2D<T>(v1.x - v2.x, v1.y - v2.y);
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vec2D_Multiply(const Game::Math::Vector2D<T>& v, const double scaler)
{
    return Vector2D<T>(v.x * scaler, v.y * scaler);
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vec2D_Multiply(const Game::Math::Vector2D<T>& v1, const Game::Math::Vector2D<T>& v2)
{   
    return Vector2D<T>(v1.x * v2.x , v1.y * v2.y);
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vec2D_Divide(const Game::Math::Vector2D<T>& v , const double scaler)
{
    if (scaler == 0.0f)
        throw Game::Math::Exception::DivisionByZero("Can't be divided by 0");
    
    return Vector2D<T>(v.x / scaler, v.y / scaler);
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vec2D_MultipyByMatrix(const Game::Math::Vector2D<T>& v, const Game::Math::Matrix2D<T>& matrix)
{
    return Vector2D<T>(
        v.x * matrix.GetElement(0, 0) + v.y * matrix.GetElement(1, 0),
        v.x * matrix.GetElement(0, 1) + v.y * matrix.GetElement(1, 1)
    );
}

template <typename T>
double Game::Math::Vec2D_DotProduct(const Game::Math::Vector2D<T>& v1, const Game::Math::Vector2D<T>& v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

template <typename T>
double Game::Math::Vec2D_CrossProduct(const Game::Math::Vector2D<T>& v1, const Game::Math::Vector2D<T>& v2)
{
    return v1.x * v2.x - v1.y * v2.y;
}

template <typename T>
double Game::Math::Vec2D_Magnitude(const Game::Math::Vector2D<T>& v)
{
    return std::sqrt(v.x * v.x + v.y * v.y);
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vec2D_Normalize(Game::Math::Vector2D<T>& v)
{
    double mag = Game::Math::Vec2D_Magnitude(v);
    
    Vector2D<T> NormalizedVector;
    
    if (std::abs(mag) < VEC2D_TOLERANCE_VALUE)
    {
        NormalizedVector.x = NormalizedVector.y = 0.0f;
    }
    NormalizedVector = Vector2D<T>(v.x / mag, v.y / mag);
    
    v = NormalizedVector;
    return NormalizedVector;
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vec2D_Perpendicular(const Game::Math::Vector2D<T>& v)
{
	return Vector2D<T>(-v.y, v.x);
}

template <typename T>
double Game::Math::Vec2D_Distance(const Game::Math::Vector2D<T>& v1, const Game::Math::Vector2D<T>& v2)
{
   double dx = v2.x - v1.x;
   double dy = v2.y - v1.y;
   
   return sqrt(dx * dx + dy * dy);
}

template <typename T>
double Game::Math::Vec2D_Angle(const Game::Math::Vector2D<T>& v1, const Game::Math::Vector2D<T>& v2)
{
    double dotProduct = Game::Math::Vec2D_DotProduct(v1, v2);
    double v1_magnitude = Game::Math::Vec2D_Magnitude(v1);
    double v2_magnitude = Game::Math::Vec2D_Magnitude(v2);
    
    double cosThetha = dotProduct / (v1_magnitude * v2_magnitude);
    double angle = std::acos(cosThetha);
    return angle;
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vec2D_ProjectOn(const Game::Math::Vector2D<T>& Vector, const Game::Math::Vector2D<T>& Target)
{
    Game::Math::Vector2D<T> Target_Normalized = Game::Math::Vec2D_Normalize(Target);

    double DotProduct = Game::Math::Vec2D_DotProduct(Vector, Target_Normalized);
     
    Vector2D<T> ProjectedVector = Game::Math::Vec2D_Multiply(Target_Normalized, DotProduct);
    
    return ProjectedVector;
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vec2D_Translate(Game::Math::Vector2D<T>& Vector, const T a, const T b)
{
	Vector2D<T> TranslatedVector(Vector.x + a,Vector.y + b);
	Vector = TranslatedVector;
	return TranslatedVector;
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vec2D_Reflect(Game::Math::Vector2D<T>& OrignalVector, const Game::Math::Vector2D<T>& SurfaceNormal)
{
    double DotProduct = Game::Math::Vec2D_DotProduct(OrignalVector, SurfaceNormal);
    Vector2D<T> ScaledVector = SurfaceNormal * 2.0f * DotProduct;
    
    Vector2D<T> ReflectedVector = Game::Math::Vec2D_Subtract(OrignalVector, ScaledVector);
    OrignalVector = ReflectedVector;
    
    return ReflectedVector;
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vec2D_Rotate(Game::Math::Vector2D<T>& vector, const double angle)
{
    double cosTheta = cos(angle);
    double sinTheta = sin(angle);
    
    // This could be done by Matrix2D But I preferred to do it like this
    Game::Math::Vector2D<T> RotatedVector(
                                          vector.x * cosTheta - vector.y * sinTheta,
                                          vector.x * sinTheta + vector.y * cosTheta
                                         );
    vector = RotatedVector;
    return RotatedVector;
}

template <typename T>
void Game::Math::Vec2D_Clamp(Game::Math::Vector2D<T>& vector, const Game::Math::Vector2D<T>& min, const Game::Math::Vector2D<T>& max)
{
    vector.x = std::clamp(vector.x, min.x, max.x);
    vector.y = std::clamp(vector.y, min.y, max.y);
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vec2D_Round(Game::Math::Vector2D<T>& v, const Game::Math::Vec2D_Round_Flag flag)
{
    Vector2D<T> RoundedVector;
    switch (flag)
    {
        case Game::Math::Vec2D_Round_Flag::ToFloor:
            RoundedVector.SetVec((std::floor(v.x)), (std::floor(v.y)));
	    break;
            
        case Game::Math::Vec2D_Round_Flag::ToCeil:
            RoundedVector.SetVec((std::ceil(v.x)), (std::ceil(v.y)));
	    break;
            
        case Game::Math::Vec2D_Round_Flag::ToNearest:
            RoundedVector.SetVec((std::round(v.x)), (std::round(v.y)));
	    break;
            
        default:
            throw Game::Math::Exception::InvalidRoundFlag("Invalid Round Flag");
    }
            
        v = RoundedVector;
        return RoundedVector;
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vec2D_Lerp(const Game::Math::Vector2D<T>& start, const Game::Math::Vector2D<T>& end, const float t)
{
    T x = start.x + (end.x - start.x) * t;
    T y = start.y + (end.y - start.y) * t;
    return Vector2D<T>(x, y);
}

template <typename T>
bool Game::Math::Vec2D_IsEqual(const Game::Math::Vector2D<T>& v1, const Game::Math::Vector2D<T>& v2)
{
    return v1.x == v2.x && v1.y == v2.y;
}

template <typename T>
bool Game::Math::Vec2D_IsNotEqual(const Game::Math::Vector2D<T>& v1, const Game::Math::Vector2D<T>& v2)
{
    return !(v1.x == v2.x && v1.y == v2.y);
}

template <typename T>
bool Game::Math::Vec2D_IsGreaterThan(const Game::Math::Vector2D<T>& v1, const Game::Math::Vector2D<T>& v2)
{
    return v1.Magnitude() > v2.Magnitude();
}

template <typename T>
bool Game::Math::Vec2D_IsLessThan(const Game::Math::Vector2D<T>& v1, const Game::Math::Vector2D<T>& v2)
{
    return v1.Magnitude() < v2.Magnitude();
}

