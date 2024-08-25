/** 
 *  \file Vector2T.cpp
 *  
 *  \brief Source file for Vector2T<T> of 2 double point integers.
 *
 *  This supports vector related functions.
 *
 *  \author IndieGameSmith
 *  \date 2024-08-23
 */

#include "include/Maths/Vector2f.hpp"
#include "include/Utils/Exceptions/Math_Exception.hpp"

#include <iostream>
#include <cmath>

constexpr double TOLERANCE_VALUE = 1e-6;

template <typename T>
std::ostream& operator<<(std::ostream &str, Game::Math::Vector2T<T> const &v)
{
	str << "[" << v.x << ", " << v.y << "]";
	return str;
}

template <typename T>
Game::Math::Vector2T<T> :: Vector2T() : x(0.0f), y(0.0f)
{
    
}

template <typename T>
Game::Math::Vector2T<T> :: Vector2T(T p_x, T p_y) : x(p_x), y(p_y)
{
    
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vector2T<T> :: operator+(const Game::Math::Vector2T<T>& other) const
{
	return Vector2T<T>(x + other.x, y + other.y);
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vector2T<T> :: operator-(const Game::Math::Vector2T<T>& other) const
{
	return Vector2T<T>(x - other.x, y - other.y);
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vector2T<T> :: operator*(const double scaler) const
{
    return Vector2T<T>(x * scaler, y * scaler);
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vector2T<T>::operator*(const Matrix2f& matrix) const
{
    return Vector2T<T>(
        x * matrix.GetElement(0, 0) + y * matrix.GetElement(1, 0),
        x * matrix.GetElement(0, 1) + y * matrix.GetElement(1, 1)
    );
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vector2T<T> :: operator/(const double scaler) const
{
	if (scaler == 0)
		throw Game::Math::Exception::DivisionByZero("Can't be divided by 0");
	
	return Vector2T<T>(x / scaler, y / scaler);
}

template <typename T>
bool Game::Math::Vector2T<T> :: operator==(const Vector2T<T>& other) const
{
    return x == other.x && y == other.y;
}

template <typename T>
bool Game::Math::Vector2T<T> :: operator!=(const Vector2T<T>& other) const
{
    return !(x == other.x && y == other.y);
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vector2T<T> :: Add(const Game::Math::Vector2T<T>& other) const
{
	return Vector2T<T>(x + other.x, y + other.y);
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vector2T<T> :: Sub(const Game::Math::Vector2T<T>& other) const
{
	return Vector2T<T>(x - other.x, y - other.y);
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vector2T<T> :: Multiply(const double scaler) const
{
    return Vector2T<T>(x * scaler, y * scaler);
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vector2T<T> :: Divide(const double scaler) const
{
	if (scaler == 0)
		throw Game::Math::Exception::DivisionByZero("Can't be divided by 0");
	
	return Vector2T<T>(x / scaler, y / scaler);
}

template <typename T>
double Game::Math::Vector2T<T> :: DotProduct(const Game::Math::Vector2T<T>& other) const
{
    return x * other.x + y * other.y;
}

template <typename T>
double Game::Math::Vector2T<T> :: CrossProduct(const Game::Math::Vector2T<T>& other) const
{
    return x * other.x - y * other.y;
}

template <typename T>
double Game::Math::Vector2T<T> :: Magnitude() const
{
	return std::sqrt(x * x + y * y);
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vector2T<T> :: Normalize() const
{
	double mag = Magnitude();
    
    Vector2T<T> NormalizedVector;
    
    if (std::abs(mag) < TOLERANCE_VALUE)
    {
        NormalizedVector.x = NormalizedVector.y = 0.0f;
    }
    NormalizedVector = Vector2T<T>(x / mag, y / mag);
    
    *this = NormalizedVector;
    return NormalizedVector;
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vector2T<T> :: GetVec() const
{
    Vector2T<T> result;
    result.x = x;
    result.y = y;
    return result;
}

template <typename T>
void Game::Math::Vector2T<T> :: SetVec(T p_x, T p_y)
{
    x = p_x;
    y = p_y;
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vec2T_Add(const Game::Math::Vector2T<T>& v1, const Game::Math::Vector2T<T>& v2)
{
    return Vector2T<T>(v1.x + v2.x, v1.y + v2.y);
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vec2T_Subtract(const Game::Math::Vector2T<T>& v1, const Game::Math::Vector2T<T>& v2)
{
    return Vector2T<T>(v1.x - v2.x, v1.y - v2.y);
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vec2T_Multiply(const Game::Math::Vector2T<T>& v, const double scaler)
{
    return Vector2T<T>(v.x * scaler, v.y * scaler);
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vec2T_Multiply(const Game::Math::Vector2T<T>& v1, const Game::Math::Vector2T<T>& v2)
{   
    return Vector2T<T>(v1.x * v2.x , v1.y * v2.y);
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vec2T_Divide(const Game::Math::Vector2T<T>& v , const double scaler)
{
    if (scaler == 0.0f)
        throw Game::Math::Exception::DivisionByZero("Can't be divided by 0");
    
    return Vector2T<T>(v.x / scaler, v.y / scaler);
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vec2T_MultipyByMatrix(const Game::Math::Vector2T<T>& v, const Game::Math::Matrix2f& matrix)
{
    return Vector2T<T>(
        v.x * matrix.GetElement(0, 0) + v.y * matrix.GetElement(1, 0),
        v.x * matrix.GetElement(0, 1) + v.y * matrix.GetElement(1, 1)
    );
}

template <typename T>
double Game::Math::Vec2T_DotProduct(const Game::Math::Vector2T<T>& v1, const Game::Math::Vector2T<T>& v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

template <typename T>
double Game::Math::Vec2T_CrossProduct(const Game::Math::Vector2T<T>& v1, const Game::Math::Vector2T<T>& v2)
{
    return v1.x * v2.x - v1.y * v2.y;
}

template <typename T>
double Game::Math::Vec2T_Magnitude(const Game::Math::Vector2T<T>& v)
{
    return std::sqrt(v.x * v.x + v.y * v.y);
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vec2T_Normalize(Game::Math::Vector2T<T>& v)
{
    double mag = Game::Math::Vec2T_Magnitude(v);
    
    Vector2T<T> NormalizedVector;
    
    if (std::abs(mag) < TOLERANCE_VALUE)
    {
        NormalizedVector.x = NormalizedVector.y = 0.0f;
    }
    NormalizedVector = Vector2T<T>(v.x / mag, v.y / mag);
    
    v = NormalizedVector;
    return NormalizedVector;
}

template <typename T>
double Game::Math::Vec2T_Distance(const Game::Math::Vector2T<T>& v1, const Game::Math::Vector2T<T>& v2)
{
   double dx = v2.x - v1.x;
   double dy = v2.y - v1.y;
   
   return sqrt(dx * dx + dy * dy);
}

template <typename T>
double Game::Math::Vec2T_Angle(const Game::Math::Vector2T<T>& v1, const Game::Math::Vector2T<T>& v2)
{
    double dotProduct = Game::Math::Vec2T_DotProduct(v1, v2);
    double v1_magnitude = Game::Math::Vec2T_Magnitude(v1);
    double v2_magnitude = Game::Math::Vec2T_Magnitude(v2);
    
    double cosThetha = dotProduct / (v1_magnitude * v2_magnitude);
    double angle = std::acos(cosThetha);
    return angle;
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vec2T_ProjectOnto(Game::Math::Vector2T<T>& Vector, const Game::Math::Vector2T<T>& Target)
{
    Game::Math::Vector2T<T> Target_Normalized = Game::Math::Vec2T_Normalize(Target);

    double DotProduct = Game::Math::Vec2T_DotProduct(Vector, Target_Normalized);
     
    Vector2T<T> ProjectedVector = Game::Math::Vec2T_Multiply(Target_Normalized, DotProduct);
    Vector = ProjectedVector;
    
    return ProjectedVector;
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vec2T_Reflect(Game::Math::Vector2T<T>& OrignalVector, const Game::Math::Vector2T<T>& SurfaceNormal)
{
    double DotProduct = Game::Math::Vec2T_DotProduct(OrignalVector, SurfaceNormal);
    Vector2T<T> ScaledVector = SurfaceNormal * 2.0f * DotProduct;
    
    Vector2T<T> ReflectedVector = Game::Math::Vec2T_Subtract(OrignalVector, ScaledVector);
    OrignalVector = ReflectedVector;
    
    return ReflectedVector;
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vec2T_Rotate(Game::Math::Vector2T<T>& vector, const double angle)
{
    double cosTheta = cos(angle);
    double sinTheta = sin(angle);
    
    // This could be done by Matrix2f But I preferred to do it like this
    Game::Math::Vector2T<T> RotatedVector(
                                          vector.x * cosTheta - vector.y * sinTheta,
                                          vector.x * sinTheta + vector.y * cosTheta
                                         );
    vector = RotatedVector;
    return RotatedVector;
}

template <typename T>
void Game::Math::Vec2T_Clamp(Game::Math::Vector2T<T>& vector, const Game::Math::Vector2T<T>& min, const Game::Math::Vector2T<T>& max)
{
    vector.x = std::clamp(vector.x, min.x, max.x);
    vector.y = std::clamp(vector.y, min.y, max.y);
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vec2T_Round(Game::Math::Vector2T<T>& v, const Game::Math::Vec2T_Round_Flag flag)
{
    switch (flag)
    {
        Vector2T<T> RoundedVector;
        case Game::Math::Vec2T_Round_Flag::ToFloor:
            RoundedVector.SetVec((std::floor(v.x)), (std::floor(v.y)));
            
        case Game::Math::Vec2T_Round_Flag::ToCeil:
            RoundedVector.SetVec((std::ceil(v.x)), (std::ceil(v.y)));
            
        case Game::Math::Vec2T_Round_Flag::ToNearest:
            RoundedVector.SetVec((std::round(v.x)), (std::round(v.y)));
            
        default:
            throw Game::Math::Exception::InvalidRoundFlag("Invalid Round Flag");
            
        v = RoundedVector;
        return RoundedVector;
    }
}

template <typename T>
Game::Math::Vector2T<T> Game::Math::Vec2T_Lerp(const Game::Math::Vector2T<T>& start, const Game::Math::Vector2T<T>& end, const float t)
{
    T x = start.x + (end.x - start.x) * t;
    T y = start.y + (end.y - start.y) * t;
    return Vector2T<T>(x, y);
}

template <typename T>
bool Game::Math::Vec2T_IsEqual(const Game::Math::Vector2T<T>& v1, const Game::Math::Vector2T<T>& v2)
{
    return v1.x == v2.x && v1.y == v2.y;
}

template <typename T>
bool Game::Math::Vec2T_IsNotEqual(const Game::Math::Vector2T<T>& v1, const Game::Math::Vector2T<T>& v2)
{
    return !(v1.x == v2.x && v1.y == v2.y);
}
