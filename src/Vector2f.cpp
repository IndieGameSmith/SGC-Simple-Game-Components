/** 
 *  \file Vector2f.cpp
 *  
 *  \brief Source file for Vector2f of 2 double point integers.
 *
 *  This supports vector related functions.
 *
 *  \author IndieGameSmith
 *  \date 2024-08-23
 */

#include "include/Math/Vector2f.hpp"
#include "include/Math/Matrix2f.cpp"
#include "include/UtilsExceptions.hpp"

#include <iostream>
#include <cmath>

constexpr double TOLERANCE_VALUE = 1e-6;

std::ostream& operator<<(std::ostream &str, Math::Vector2f const &v)
{
	str << "[" << v.x << ", " << v.y << "]";
	return str;
}

Math::Vector2f :: Vector2f() : x(0.0f), y(0.0f)
{
    
}

Math::Vector2f :: Vector2f(double p_x, double p_y) : x(p_x), y(p_y)
{
    
}

Math::Vector2f& Math::Vector2f :: operator+(const Math::Vector2f& other)
{
	x += other.x;
	y += other.y;
	
	return *this;
}

Math::Vector2f& Math::Vector2f :: operator-(const Math::Vector2f& other) 
{
	x -= other.x;
	y -= other.y;
	
	return *this;
}

Math::Vector2f& Math::Vector2f :: operator*(double scaler) 
{
	x *= scaler;
	y *= scaler;
	
	return *this;
}

Math::Vector2f Math::Vector2f::operator*(const Matrix2f& matrix) const
{
    return Vector2f(
        x * matrix.getElement(0, 0) + y * matrix.getElement(1, 0),
        x * matrix.getElement(0, 1) + y * matrix.getElement(1, 1)
    );
}

Math::Vector2f& Math::Vector2f :: operator/(double scaler) 
{
	if (scaler == 0)
		throw Exception::DivisionByZero("Can't be divided by 0");
	
	x /= scaler;
	y /= scaler;
	
	return *this;
}

bool Math::Vector2f :: operator==(const Vector2f& other) const
{
    return x == other.x && y == other.y;
}

bool Math::Vector2f :: operator!=(const Vector2f& other) const
{
    return !(x == other.x && y == other.y);
}

Math::Vector2f& Math::Vector2f :: Add(const Math::Vector2f& other) 
{
	x += other.x;
	y += other.y;
	
	return *this;
}

Math::Vector2f& Math::Vector2f :: Sub(const Math::Vector2f& other) 
{
	x -= other.x;
	y -= other.y;
	
	return *this;
}

Math::Vector2f& Math::Vector2f :: Multiply(const double scaler) 
{
	x *= scaler;
	y *= scaler;
	
	return *this;
}

Math::Vector2f& Math::Vector2f :: Divide(const double scaler) 
{
	if (scaler == 0)
		throw Exception::DivisionByZero("Can't be divided by 0");
	
	x /= scaler;
	y /= scaler;
	
	return *this;
}

double Math::Vector2f :: DotProduct(const Math::Vector2f& other) const
{
    return x * other.x + y * other.y;
}

double Math::Vector2f :: CrossProduct(const Math::Vector2f& other) const
{
    return x * other.x - y * other.y;
}

double Math::Vector2f :: Magnitude() const
{
	return std::sqrt(x * x + y * y);
}

Math::Vector2f Math::Vector2f :: Normalize() const
{
	Vector2f v;
	v.x = x;
	v.y = y;
	double mag = Math::Vec2f_Magnitude(v);
    
    Vector2f result(v);
    
    if (std::abs(mag) < TOLERANCE_VALUE)
    {
        result.x = result.y = 0.0f;
    }
    result.x = result.x / mag;
    result.y = result.y / mag;
    return result;
}

Math::Vector2f Math::Vector2f :: GetVec() const
{
    Vector2f result;
    result.x = x;
    result.y = y;
    return result;
}

void Math::Vector2f :: SetVec(double p_x, double p_y)
{
    x = p_x;
    y = p_y;
}

Math::Vector2f Math::Vec2f_Add(Math::Vector2f& v1, Math::Vector2f& v2)
{
    Vector2f result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    
    return result;
}

Math::Vector2f Math::Vec2f_Substract(Math::Vector2f& v1, Math::Vector2f& v2)
{
    Vector2f result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    
    return result;
}

Math::Vector2f Math::Vec2f_Multiply(Math::Vector2f& v, const double scaler)
{
    Vector2f result;
    result.x = v.x * scaler;
    result.y = v.y * scaler;
    
    return result;
}

Math::Vector2f Math::Vec2f_Multiply(Math::Vector2f& v1, Math::Vector2f& v2)
{   
    return Vector2f(v1.x * v2.x , v1.y * v2.y);
}

Math::Vector2f Math::Vec2f_Divide(Math::Vector2f& v , const double scaler)
{
    if (scaler == 0.0f)
        throw Exception::DivisionByZero("Can't be divided by 0");
    
    Vector2f result;
    result.x = v.x / scaler;
    result.y = v.y / scaler;
    
    return result;
}

Math::Vector2f Math::Vec2f_MultipyByMatrix(Math::Vector2f& v, Math::Matrix2f& matrix)
{
    return Vector2f(
        v.x * matrix.getElement(0, 0) + v.y * matrix.getElement(1, 0),
        v.x * matrix.getElement(0, 1) + v.y * matrix.getElement(1, 1)
    );
}

double Math::Vec2f_DotProduct(Math::Vector2f& v1, Math::Vector2f& v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

double Math::Vec2f_CrossProduct(Math::Vector2f& v1, Math::Vector2f& v2)
{
    return v1.x * v2.x - v1.y * v2.y;
}

double Math::Vec2f_Magnitude(Math::Vector2f& v)
{
    return std::sqrt(v.x * v.x + v.y * v.y);
}

Math::Vector2f Math::Vec2f_Normalize(Math::Vector2f& v)
{
    double mag = Math::Vec2f_Magnitude(v);
    
    Vector2f result(v);
    
    if (std::abs(mag) < TOLERANCE_VALUE)
    {
        result.x = result.y = 0.0f;
    }
    result.x = result.x / mag;
    result.y = result.y / mag;
    return result;
}

double Math::Vec2f_Distance(Math::Vector2f& v1, Math::Vector2f& v2)
{
   double dx = v2.x - v1.x;
   double dy = v2.y - v1.y;
   
   return sqrt(dx * dx + dy * dy);
}

double Math::Vec2f_Angle(Math::Vector2f& v1, Math::Vector2f& v2)
{
    double dotProduct = Math::Vec2f_DotProduct(v1, v2);
    double v1_magnitude = Math::Vec2f_Magnitude(v1);
    double v2_magnitude = Math::Vec2f_Magnitude(v2);
    
    double cosThetha = dotProduct / (v1_magnitude * v2_magnitude);
    double angle = std::acos(cosThetha);
    return angle;
}

Math::Vector2f Math::Vec2f_ProjectOnto(Math::Vector2f& Vector, Math::Vector2f& Target)
{
    Math::Vector2f Target_Normalized = Math::Vec2f_Normalize(Target);

    double DotProduct = Math::Vec2f_DotProduct(Vector, Target_Normalized);
     
    Vector2f ProjectedVector = Math::Vec2f_Multiply(Target_Normalized, DotProduct);
    return ProjectedVector;
}

Math::Vector2f Math::Vec2f_Reflect(Math::Vector2f& OrignalVector, Math::Vector2f& SurfaceNormal)
{
    double DotProduct = Math::Vec2f_DotProduct(OrignalVector, SurfaceNormal);
    Vector2f ScaledVector = SurfaceNormal * 2.0f * DotProduct;
    
    Vector2f ReflectedVector = Math::Vec2f_Substract(OrignalVector, ScaledVector);
    
    return ReflectedVector;
}

Math::Vector2f Math::Vec2f_Rotate(Math::Vector2f& vector, double angle)
{
    double cosTheta = cos(angle);
    double sinTheta = sin(angle);
    
    // This could be done by Matrix2f But I preferred to do it like this
    return Math::Vector2f(
        vector.x * cosTheta - vector.y * sinTheta,
        vector.x * sinTheta + vector.y * cosTheta
    );
}

void Math::Vec2f_Clamp(Math::Vector2f& vector, Math::Vector2f& min, Math::Vector2f& max)
{
    vector.x = std::clamp(vector.x, min.x, max.x);
    vector.y = std::clamp(vector.y, min.y, max.y);
}

Math::Vector2f Math::Vec2f_Round(Math::Vector2f& v, Math::Vec2f_Round_Flag flag)
{
    switch (flag)
    {
        case Math::Vec2f_Round_Flag::ToFloor:
            return Vector2f((std::floor(v.x)), (std::floor(v.y)));
            
        case Math::Vec2f_Round_Flag::ToCeil:
            return Vector2f((std::ceil(v.x)), (std::ceil(v.y)));
            
        case Math::Vec2f_Round_Flag::ToNearest:
            return Vector2f((std::round(v.x)), (std::round(v.y)));
            
        default:
            throw Exception::InvalidRoundFlag("Invalid Round Flag");
    }
}

Math::Vector2f Math::Vec2f_Lerp(Math::Vector2f& start, Math::Vector2f& end, double t)
{
    Vector2f result;
    result.x = start.x + (end.x - start.x) * t;
    result.y = start.y + (end.y - start.y) * t;
    return result;
}

bool Math::Vec2f_IsEqual(Math::Vector2f& v1, Math::Vector2f& v2)
{
    return v1.x == v2.x && v1.y == v2.y;
}

bool Math::Vec2f_IsNotEqual(Math::Vector2f& v1, Math::Vector2f& v2)
{
    return !(v1.x == v2.x && v1.y == v2.y);
}
