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

#include "include/Maths/Vector2D.hpp"
#include "include/Utils/Exceptions/Math_Exception.hpp"

#include <iostream>
#include <cmath>

constexpr double TOLERANCE_VALUE = 1e-6;

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
Game::Math::Vector2D<T> Game::Math::Vector2D<T>::operator*(const Matrix2f& matrix) const
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
    
    if (std::abs(mag) < TOLERANCE_VALUE)
    {
        NormalizedVector.x = NormalizedVector.y = 0.0f;
    }
    NormalizedVector = Vector2D<T>(x / mag, y / mag);
    
    *this = NormalizedVector;
    return NormalizedVector;
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T> :: Perpendicular() const
{
	return Vector2D<T>(-y, x);
}

template <typename T>
Game::Math::Vector2D<T> Game::Math::Vector2D<T> :: GetVec() const
{
    Vector2D<T> result;
    result.x = x;
    result.y = y;
    return result;
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
Game::Math::Vector2D<T> Game::Math::Vec2D_MultipyByMatrix(const Game::Math::Vector2D<T>& v, const Game::Math::Matrix2f& matrix)
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
    
    if (std::abs(mag) < TOLERANCE_VALUE)
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
Game::Math::Vector2D<T> Game::Math::Vec2D_ProjectOnto(Game::Math::Vector2D<T>& Vector, const Game::Math::Vector2D<T>& Target)
{
    Game::Math::Vector2D<T> Target_Normalized = Game::Math::Vec2D_Normalize(Target);

    double DotProduct = Game::Math::Vec2D_DotProduct(Vector, Target_Normalized);
     
    Vector2D<T> ProjectedVector = Game::Math::Vec2D_Multiply(Target_Normalized, DotProduct);
    Vector = ProjectedVector;
    
    return ProjectedVector;
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
    
    // This could be done by Matrix2f But I preferred to do it like this
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
    switch (flag)
    {
        Vector2D<T> RoundedVector;
        case Game::Math::Vec2D_Round_Flag::ToFloor:
            RoundedVector.SetVec((std::floor(v.x)), (std::floor(v.y)));
            
        case Game::Math::Vec2D_Round_Flag::ToCeil:
            RoundedVector.SetVec((std::ceil(v.x)), (std::ceil(v.y)));
            
        case Game::Math::Vec2D_Round_Flag::ToNearest:
            RoundedVector.SetVec((std::round(v.x)), (std::round(v.y)));
            
        default:
            throw Game::Math::Exception::InvalidRoundFlag("Invalid Round Flag");
            
        v = RoundedVector;
        return RoundedVector;
    }
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
