/** 
 *  \file Vector3D.cpp
 *  
 *  \brief Source file for Vector3D.
 *
 *  This supports Vector3D related functions.
 *
 *  \author IndieGameSmith
 *  \date 2024-08-23
 */

#include "Math/Vector3D.hpp"
#include "Utils/Exceptions/Math_Exception.hpp"

#include <iostream>
#include <cmath>

constexpr double Vec3D_TOLERANCE_VALUE = 1e-6;

template <typename T>
std::ostream &operator<<(std::ostream &str, Game::Math::Vector3D<T> const& v)
{
	str << "[" << v.x << ", " << v.y << "," << v.z << "]";
	return str;
}

template <typename T>
Game::Math::Vector3D<T>::Vector3D() : x(0.0f), y(0.0f)
{
}

template <typename T>
Game::Math::Vector3D<T>::Vector3D(T p_x, T p_y, T p_z) : x(p_x), y(p_y), z(p_z)
{
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vector3D<T>::operator+(const Game::Math::Vector3D<T> &other) const
{
	return Vector3D<T>(x + other.x, y + other.y, z + other.z);
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vector3D<T>::operator-(const Game::Math::Vector3D<T> &other) const
{
	return Vector3D<T>(x - other.x, y - other.y, z - other.z);
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vector3D<T>::operator*(const double scaler) const
{
	return Vector3D<T>(x * scaler, y * scaler, z * scaler);
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vector3D<T>::operator*(const Matrix3D<T> &matrix) const
{
	return Vector3D<T>(
		x * matrix.GetElement(0, 0) + y * matrix.GetElement(1, 0) + z * matrix.GetElement(2, 0),
		x * matrix.GetElement(0, 1) + y * matrix.GetElement(1, 1) + z * matrix.GetElement(2, 1),
		x * matrix.GetElement(0, 2) + y * matrix.GetElement(1, 2) + z * matrix.GetElement(2, 2));
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vector3D<T>::operator/(const double scaler) const
{
	if (scaler == 0)
		throw Game::Math::Exception::DivisionByZero("Can't be divided by 0");

	return Vector3D<T>(x / scaler, y / scaler, z / scaler);
}

template <typename T>
bool Game::Math::Vector3D<T>::operator==(const Vector3D<T> &other) const
{
	return x == other.x && y == other.y && z == other.z;
}

template <typename T>
bool Game::Math::Vector3D<T>::operator!=(const Vector3D<T> &other) const
{
	return !(x == other.x && y == other.y && z == other.z);
}

template <typename T>
bool Game::Math::Vector3D<T>::operator<(const Vector3D<T> &other) const
{
	return Magnitude() < other.Magnitude();
}

template <typename T>
bool Game::Math::Vector3D<T>::operator>(const Vector3D<T> &other) const
{
	return Magnitude() > other.Magnitude();
}

template <typename T>
bool Game::Math::Vector3D<T>::operator<=(const Vector3D<T> &other) const
{
	return Magnitude() < other.Magnitude() || Magnitude() == other.Magnitude();
}

template <typename T>
bool Game::Math::Vector3D<T>::operator>=(const Vector3D<T> &other) const
{
	return Magnitude() > other.Magnitude() || Magnitude() == other.Magnitude();
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vector3D<T>::Add(const Game::Math::Vector3D<T> &other) const
{
	return Vector3D<T>(x + other.x, y + other.y, z + other.z);
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vector3D<T>::Sub(const Game::Math::Vector3D<T> &other) const
{
	return Vector3D<T>(x - other.x, y - other.y, z - other.z);
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vector3D<T>::Multiply(const double scaler) const
{
	return Vector3D<T>(x * scaler, y * scaler, z * scaler);
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vector3D<T>::Divide(const double scaler) const
{
	if (scaler == 0)
		throw Game::Math::Exception::DivisionByZero("Can't be divided by 0");

	return Vector3D<T>(x / scaler, y / scaler, z / scaler);
}

template <typename T>
double Game::Math::Vector3D<T>::DotProduct(const Game::Math::Vector3D<T> &other) const
{
	return x * other.x + y * other.y, z * other.z;
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vector3D<T>::CrossProduct(const Game::Math::Vector3D<T> &other) const
{
	Vector3D<T> result;

	result.x = y * other.z - z * other.y;
	result.y = z * other.x - x * other.z;
	result.z = x * other.y - y * other.x;

	return result;
}

template <typename T>
double Game::Math::Vector3D<T>::Magnitude() const
{
	return std::sqrt(x * x + y * y + z * z);
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vector3D<T>::Normalize() const
{
	double mag = Magnitude();

	Vector3D<T> NormalizedVector;

	if (std::abs(mag) < Vec3D_TOLERANCE_VALUE)
	{
		NormalizedVector.x = NormalizedVector.y = Normalized.z = 0.0f;
	}
	NormalizedVector = Vector3D<T>(x / mag, y / mag, z / mag);

	*this = NormalizedVector;
	return NormalizedVector;
}

template <typename T>
double Game::Math::Vector3D<T>::DistanceFrom(const Game::Math::Vector3D<T> &other) const
{
	double dx = other.x - x;
	double dy = other.y - y;
	double dz = other.z - z;
	return std::sqrt(dx * dx + dy * dy + dz * dz);
}

template <typename T>
double Game::Math::Vector3D<T>::Angle(const Game::Math::Vector3D<T> &other) const
{
	if (IsEmpty() == true || other.IsEmpty() == true)
	{
		Game::Math::Exception::ZeroLengthVector("Vector can't be zero length");
	}

	double dotProduct = Game::Math::Vec3D_DotProduct(*this, other);
	double v1_magnitude = Game::Math::Vec3D_Magnitude(*this);
	double v2_magnitude = Game::Math::Vec3D_Magnitude(other);

	double cosThetha = dotProduct / (v1_magnitude * v2_magnitude);
	double angle = std::acos(cosThetha);
	return angle;
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vector3D<T>::ProjectOn(const Game::Math::Vector3D<T> &Target) const
{
	if (IsEmpty() == true || Target.IsEmpty() == true)
	{
		Game::Math::Exception::ZeroLengthVector("Vector can't be zero length");
	}

	Game::Math::Vector3D<T> Target_Normalized = Game::Math::Vec3D_Normalize(Target);

	double DotProduct = Game::Math::Vec3D_DotProduct(*this, Target_Normalized);

	Vector3D<T> ProjectedVector = Game::Math::Vec3D_Multiply(Target_Normalized, DotProduct);

	return ProjectedVector;
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vector3D<T>::Reflect(const Game::Math::Vector3D<T> &SurfaceNormal)
{
	if (IsEmpty() == true || SurfaceNormal.IsEmpty() == true)
	{
		Game::Math::Exception::ZeroLengthVector("Vector can't be zero length");
	}

	double DotProduct = Game::Math::Vec3D_DotProduct(*this, SurfaceNormal);
	Vector3D<T> ScaledVector = SurfaceNormal * 2.0f * DotProduct;

	Vector3D<T> ReflectedVector = Game::Math::Vec3D_Subtract(*this, ScaledVector);
	*this = ReflectedVector;

	return ReflectedVector;
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vector3D<T>::Rotate(const double angle)
{
	if (IsEmpty() == true)
	{
		Game::Math::Exception::ZeroLengthVector("Vector can't be zero length");
	}

	double cosTheta = std::cos(angle);
	double sinTheta = std::sin(angle);

	Matrix3D<T> rotationMatrix(
		cosTheta, -sinTheta, 0,
		sinTheta, cosTheta, 0,
		0, 0, 1);

	Game::Math::Vector3D<T> RotatedVector = *this * rotationMatrix;
	*this = RotatedVector;
	return RotatedVector;
}

template <typename T>
void Game::Math::Vector3D<T>::Clamp(const Vector3D<T> &min, const Vector3D<T> &max)
{
	x = std::clamp(x, min.x, max.x);
	y = std::clamp(y, min.y, max.y);
	z = std::clamp(z, min.z, max.z);
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vector3D<T>::Round(const Game::Math::Vec3D_Round_Flag &flag)
{
	Vector3D<T> RoundedVector;
	switch (flag)
	{
	case Game::Math::Vec3D_Round_Flag::ToFloor:
		RoundedVector.SetVec((std::floor(x)), (std::floor(y)), (std::floor(z)));
		break;

	case Game::Math::Vec3D_Round_Flag::ToCeil:
		RoundedVector.SetVec((std::ceil(x)), (std::ceil(y)), (std::ceil(z)));
		break;

	case Game::Math::Vec3D_Round_Flag::ToNearest:
		RoundedVector.SetVec((std::round(x)), (std::round(y)), (std::round(z)));
		break;

	default:
		throw Game::Math::Exception::InvalidRoundFlag("Invalid Round Flag");
	}

	*this = RoundedVector;
	return RoundedVector;
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vector3D<T>::Lerp(const Game::Math::Vector3D<T> &other, const float t) const
{
	T x = x + (other.x - x) * t;
	T y = y + (other.y - y) * t;
	T z = z + (other.z - z) * t;
	return Vector3D<T>(x, y);
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vector3D<T>::Perpendicular() const
{
	Vector3D<T> arbitararyVector(0, 0, 1);
	return CrossProduct(*this, arbitararyVector);
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vector3D<T>::Translate(const T a, const T b, const T c)
{
	Vector3D<T> TranslatedVector(x + a, y + b, z + c);
	*this = TranslatedVector;
	return TranslatedVector;
}

template <typename T>
bool Game::Math::Vector3D<T>::IsEmpty() const
{
	return (Magnitude() == 0.0f);
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vector3D<T>::GetVec() const
{
	return Vector3D<T>(x, y, z);
}

template <typename T>
void Game::Math::Vector3D<T>::SetVec(T p_x, T p_y, T p_z)
{
	x = p_x;
	y = p_y;
	z = p_z;
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vec3D_Add(const Game::Math::Vector3D<T>& v1, const Game::Math::Vector3D<T>& v2)
{
	return Vector3D<T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vec3D_Subtract(const Game::Math::Vector3D<T>& v1, const Game::Math::Vector3D<T>& v2)
{
	return Vector3D<T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vec3D_Multiply(const Game::Math::Vector3D<T>& v, const double scaler)
{
	return Vector3D<T>(v.x * scaler, v.y * scaler, v.z * scaler);
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vec3D_Multiply(const Game::Math::Vector3D<T>& v1, const Game::Math::Vector3D<T>& v2)
{
	return Vector3D<T>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vec3D_Divide(const Game::Math::Vector3D<T>& v, const double scaler)
{
	if (scaler == 0.0f)
		throw Game::Math::Exception::DivisionByZero("Can't be divided by 0");

	return Vector3D<T>(v.x / scaler, v.y / scaler, v.z / scaler);
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vec3D_MultipyByMatrix(const Game::Math::Vector3D<T>& v, const Game::Math::Matrix3D<T> &matrix)
{
	return Vector3D<T>(
		v.x * matrix.GetElement(0, 0) + v.y * matrix.GetElement(1, 0) + v.z * matrix.GetElement(2, 0),
		v.x * matrix.GetElement(0, 1) + v.y * matrix.GetElement(1, 1) + v.z * matrix.GetElement(2, 1),
		v.x * matrix.GetElement(0, 2) + v.y * matrix.GetElement(1, 2) + v.z * matrix.GetElement(2, 2));
}

template <typename T>
double Game::Math::Vec3D_DotProduct(const Game::Math::Vector3D<T>& v1, const Game::Math::Vector3D<T>& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template <typename T>
double Game::Math::Vec3D_CrossProduct(const Game::Math::Vector3D<T>& v1, const Game::Math::Vector3D<T>& v2)
{
	Vector3D<T> result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;

	return result;
}

template <typename T>
double Game::Math::Vec3D_Magnitude(const Game::Math::Vector3D<T>& v)
{
	return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vec3D_Normalize(Game::Math::Vector3D<T>& v)
{
	double mag = Game::Math::Vec3D_Magnitude(v);

	Vector3D<T> NormalizedVector;

	if (std::abs(mag) < Vec3D_TOLERANCE_VALUE)
	{
		NormalizedVector.x = NormalizedVector.y = NormalizedVector.z = 0.0f;
	}
	NormalizedVector = Vector3D<T>(v.x / mag, v.y / mag, v.z / mag);

	v = NormalizedVector;
	return NormalizedVector;
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vec3D_Perpendicular(const Game::Math::Vector3D<T>& v)
{
	Vector3D<T> arbitararyVector(0, 0, 1);
	return CrossProduct(v, arbitararyVector);
}

template <typename T>
double Game::Math::Vec3D_Distance(const Game::Math::Vector3D<T>& v1, const Game::Math::Vector3D<T>& v2)
{
	double dx = v2.x - v1.x;
	double dy = v2.y - v1.y;
	double dz = v2.z - v1.z;

	return sqrt(dx * dx + dy * dy + dz * dz);
}

template <typename T>
double Game::Math::Vec3D_Angle(const Game::Math::Vector3D<T>& v1, const Game::Math::Vector3D<T>& v2)
{
	if (v1.IsEmpty() == true || v2.IsEmpty() == true)
	{
		Game::Math::Exception::ZeroLengthVector("Vector can't be zero length");
	}
	
	double dotProduct = Game::Math::Vec3D_DotProduct(v1, v2);
	double v1_magnitude = Game::Math::Vec3D_Magnitude(v1);
	double v2_magnitude = Game::Math::Vec3D_Magnitude(v2);

	double cosThetha = dotProduct / (v1_magnitude * v2_magnitude);
	double angle = std::acos(cosThetha);
	return angle;
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vec3D_ProjectOn(const Game::Math::Vector3D<T>& Vector, const Game::Math::Vector3D<T>& Target)
{
	if (Vector.IsEmpty() == true || Target.IsEmpty() == true)
	{
		Game::Math::Exception::ZeroLengthVector("Vector can't be zero length");
	}
	
	Game::Math::Vector3D<T> Target_Normalized = Game::Math::Vec3D_Normalize(Target);

	double DotProduct = Game::Math::Vec3D_DotProduct(Vector, Target_Normalized);

	Vector3D<T> ProjectedVector = Game::Math::Vec3D_Multiply(Target_Normalized, DotProduct);

	return ProjectedVector;
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vec3D_Translate(Game::Math::Vector3D<T>& Vector, const T a, const T b, const T c)
{
	Vector3D<T> TranslatedVector(Vector.x + a, Vector.y + b, Vector.z + c);
	Vector = TranslatedVector;
	return TranslatedVector;
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vec3D_Reflect(Game::Math::Vector3D<T>& OrignalVector, const Game::Math::Vector3D<T>& SurfaceNormal)
{
	if (OrignalVector.IsEmpty() == true || SurfaceNormal.IsEmpty() == true)
	{
		Game::Math::Exception::ZeroLengthVector("Vector can't be zero length");
	}
	
	double DotProduct = Game::Math::Vec3D_DotProduct(OrignalVector, SurfaceNormal);
	Vector3D<T> ScaledVector = SurfaceNormal * 2.0f * DotProduct;

	Vector3D<T> ReflectedVector = Game::Math::Vec3D_Subtract(OrignalVector, ScaledVector);
	OrignalVector = ReflectedVector;

	return ReflectedVector;
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vec3D_Rotate(Game::Math::Vector3D<T>& vector, const double angle)
{
	if (vector.IsEmpty() == true)
	{
		Game::Math::Exception::ZeroLengthVector("Vector can't be zero length");
	}
	
	double cosTheta = std::cos(angle);
	double sinTheta = std::sin(angle);

	Matrix3D<T> rotationMatrix(
		cosTheta, -sinTheta, 0,
		sinTheta, cosTheta, 0,
		0, 0, 1);

	Game::Math::Vector3D<T> RotatedVector = vector * rotationMatrix;
	vector = RotatedVector;
	return RotatedVector;
}

template <typename T>
void Game::Math::Vec3D_Clamp(Game::Math::Vector3D<T>& vector, const Game::Math::Vector3D<T> &min, const Game::Math::Vector3D<T> &max)
{
	vector.x = std::clamp(vector.x, min.x, max.x);
	vector.y = std::clamp(vector.y, min.y, max.y);
	vector.z = std::clamp(vector.z, min.z, max.z);
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vec3D_Round(Game::Math::Vector3D<T>& v, const Game::Math::Vec3D_Round_Flag flag)
{
	Vector3D<T> RoundedVector;
	switch (flag)
	{
	case Game::Math::Vec3D_Round_Flag::ToFloor:
		RoundedVector.SetVec((std::floor(v.x)), (std::floor(v.y)), (std::floor(v.z)));
		break;

	case Game::Math::Vec3D_Round_Flag::ToCeil:
		RoundedVector.SetVec((std::ceil(v.x)), (std::ceil(v.y)), (std::ceil(v.z)));
		break;

	case Game::Math::Vec3D_Round_Flag::ToNearest:
		RoundedVector.SetVec((std::round(v.x)), (std::round(v.y)), (std::round(v.z)));
		break;

	default:
		throw Game::Math::Exception::InvalidRoundFlag("Invalid Round Flag");
	}

	v = RoundedVector;
	return RoundedVector;
}

template <typename T>
Game::Math::Vector3D<T> Game::Math::Vec3D_Lerp(const Game::Math::Vector3D<T> &start, const Game::Math::Vector3D<T> &end, const float t)
{
	T x = start.x + (end.x - start.x) * t;
	T y = start.y + (end.y - start.y) * t;
	T z = start.z + (end.z - start.z) * t;
	return Vector3D<T>(x, y, z);
}

template <typename T>
bool Game::Math::Vec3D_IsEqual(const Game::Math::Vector3D<T>& v1, const Game::Math::Vector3D<T>& v2)
{
	return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
}

template <typename T>
bool Game::Math::Vec3D_IsNotEqual(const Game::Math::Vector3D<T>& v1, const Game::Math::Vector3D<T>& v2)
{
	return !(v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}

template <typename T>
bool Game::Math::Vec3D_IsGreaterThan(const Game::Math::Vector3D<T>& v1, const Game::Math::Vector3D<T>& v2)
{
	return v1.Magnitude() > v2.Magnitude();
}

template <typename T>
bool Game::Math::Vec3D_IsLessThan(const Game::Math::Vector3D<T>& v1, const Game::Math::Vector3D<T>& v2)
{
	return v1.Magnitude() < v2.Magnitude();
}
