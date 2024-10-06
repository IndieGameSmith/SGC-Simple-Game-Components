/** 
 *  \file Matrix2f.cpp
 *  
 *  \brief Source file for Matrix2f of 2 double point integers.
 *
 *  This supports Matrix2f related functions.
 *
 *  \author IndieGameSmith
 *  \date 2024-08-25
 */

#include "Math/Matrix3D.hpp"
#include "Utils/Exceptions/Math_Exception.hpp"

#include <iostream>
#include <cmath>

template <typename T>
Game::Math::Matrix3D<T> :: Matrix3D()
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			element[i][j] = 0.0f;
		}
	}
}

template <typename T>
Game::Math::Matrix3D<T> :: Matrix3D(T a, T b, T c, T d, T e, T f, T g, T h, T i)
{
	element[0][0] = a;
	element[0][1] = b;
	element[0][2] = c;
	element[1][0] = d;
	element[1][1] = e;
	element[1][2] = f;
	element[2][0] = g;
	element[2][1] = h;
	element[2][2] = i;
}

template <typename T>
Game::Math::Matrix3D<T> Game::Math::Matrix3D<T> :: operator+(const Game::Math::Matrix3D<T>& other) const
{
    Game::Math::Matrix3D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.element[i][j] = element[i][j] + other.element[i][j];
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix3D<T> Game::Math::Matrix3D<T> :: operator-(const Game::Math::Matrix3D<T>& other) const
{
    Game::Math::Matrix3D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.element[i][j] = element[i][j] - other.element[i][j];
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix3D<T> Game::Math::Matrix3D<T> :: operator*(const T& scaler) const
{
    Game::Math::Matrix3D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.element[i][j] = element[i][j] * scaler;
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix3D<T> Game::Math::Matrix3D<T> :: operator*(const Game::Math::Matrix3D<T>& other) const
{
    Game::Math::Matrix3D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.element[i][j] = element[i][j] * other.element[i][j];
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix3D<T> Game::Math::Matrix3D<T> :: operator/(const T& scaler) const
{
    if (scaler == 0)
          throw Exception::DivisionByZero("Can't be divided 0");
    
    Game::Math::Matrix3D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.element[i][j] = element[i][j] / scaler;
        }
    }
    return result;
}

template <typename T>
bool Game::Math::Matrix3D<T> :: operator==(const Game::Math::Matrix3D<T>& other) const
{
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            if(element[i][j] != other.element[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
bool Game::Math::Matrix3D<T> :: operator!=(const Game::Math::Matrix3D<T>& other) const
{
    return !(*this == other);
}

template <typename T>
Game::Math::Matrix3D<T> Game::Math::Matrix3D<T> :: Add(const Game::Math::Matrix3D<T>& other) const
{
    Game::Math::Matrix3D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.element[i][j] = element[i][j] + other.element[i][j];
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix3D<T> Game::Math::Matrix3D<T> :: Sub(const Game::Math::Matrix3D<T>& other) const
{
    Game::Math::Matrix3D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.element[i][j] = element[i][j] - other.element[i][j];
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix3D<T> Game::Math::Matrix3D<T> :: Multiply(const T& scaler) const
{
    Game::Math::Matrix3D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.element[i][j] = element[i][j] * scaler;
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix3D<T> Game::Math::Matrix3D<T> :: Multiply(const Game::Math::Matrix3D<T>& other) const
{
    Game::Math::Matrix3D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.element[i][j] = element[i][j] * other.element[i][j];
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix3D<T> Game::Math::Matrix3D<T> :: Divide(const T& scaler) const
{
    if (scaler == 0)
       throw Game::Math::Exception::DivisionByZero("Can't be divided 0");
    
    Game::Math::Matrix3D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.element[i][j] = element[i][j] / scaler;
        }
    }
    return result;
}

template <typename T>
T Game::Math::Matrix3D<T> :: Determinant() const
{
    T det = 0;

    // Calculate the determinant using cofactor expansion along the first row
    det += element[0][0] * (element[1][1] * element[2][2] - element[1][2] * element[2][1]);
    det -= element[0][1] * (element[1][0] * element[2][2] - element[1][2] * element[2][0]);
    det += element[0][2] * (element[1][0] * element[2][1] - element[1][1] * element[2][0]);

    return det;
}

template <typename T>
Game::Math::Matrix3D<T> Game::Math::Matrix3D<T> :: Inverse() const
{
    T det = Determinant();
    if (det == 0.0)
    {
        throw Game::Math::Exception::MatrixIsSingular("Matrix is singular");
    }
    
    Matrix3D<T> result;
    // Calculate the adjugate matrix
    int adjugate[3][3];
    adjugate[0][0] = element[1][1] * element[2][2] - element[1][2] * element[2][1];
    adjugate[0][1] = -(element[1][0] * element[2][2] - element[1][2] * element[2][0]);
    adjugate[0][2] = element[1][0] * element[2][1] - element[1][1] * element[2][0];
    adjugate[1][0] = -(element[0][1] * element[2][2] - element[0][2] * element[2][1]);
    adjugate[1][1] = element[0][0] * element[2][2] - element[0][2] * element[2][0];
    adjugate[1][2] = -(element[0][0] * element[2][1] - element[0][1] * element[2][0]);
    adjugate[2][0] = element[0][1] * element[1][2] - element[0][2] * element[1][1];
    adjugate[2][1] = -(element[0][0] * element[1][2] - element[0][2] * element[1][0]);
    adjugate[2][2] = element[0][0] * element[1][1] - element[0][1] * element[1][0];
    
    // Calculate the inverse matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = adjugate[j][i] / det;
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix3D<T> Game::Math::Matrix3D<T> :: Transpose() const
{
	Matrix3D<T> result;
	
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[j][i] = element[i][j];
        }
    }
    return result;
}

template <typename T>
bool Game::Math::Matrix3D<T> :: IsEmpty() const
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (element[i][j] != 0.0f)
            {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
T Game::Math::Matrix3D<T> :: GetElement(int row, int col) const
{
    return element[row][col];
}

template <typename T>
void Game::Math::Matrix3D<T> :: SetElement(int row, int col, T value)
{
    element[row][col] = value;
}

template <typename T>
Game::Math::Matrix3D<T> Game::Math :: Mat3D_Add(const Game::Math::Matrix3D<T>& mat1, const Game::Math::Matrix3D<T>& mat2)
{
    Game::Math::Matrix3D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            T val = mat1.GetElement(i, j) + mat2.GetElement(i, j);
            result.SetElement(i, j, val);
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix3D<T> Game::Math :: Mat3D_Subtract(const Game::Math::Matrix3D<T>& mat1, const Game::Math::Matrix3D<T>& mat2)
{
    Game::Math::Matrix3D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            T val = mat1.GetElement(i, j) - mat2.GetElement(i, j);
            result.SetElement(i, j, val);
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix3D<T> Game::Math :: Mat3D_Multiply(const Game::Math::Matrix3D<T>& mat1, const Game::Math::Matrix3D<T>& mat2)
{
    Game::Math::Matrix3D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            T val = mat1.GetElement(i, j) * mat2.GetElement(i, j);
            result.SetElement(i, j, val);
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix3D<T> Game::Math :: Mat3D_Multiply(const Game::Math::Matrix3D<T>& mat1, const T& scaler)
{
    Game::Math::Matrix3D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            T val = mat1.GetElement(i, j) * scaler;
            result.SetElement(i, j, val);
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix3D<T> Game::Math :: Mat3D_Divide(const Game::Math::Matrix3D<T>& mat1, const T& scaler)
{
    if (scaler == 0)
      throw Game::Math::Exception::DivisionByZero("Can't be divided by zero.");
        
    Game::Math::Matrix3D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            T val = mat1.GetElement(i, j) / scaler;
            result.SetElement(i, j, val);
        }
    }
    return result;
}

template <typename T>
T Game::Math :: Mat3D_Determinant(const Game::Math::Matrix3D<T>& mat)
{
    T det = 0;

    // Calculate the determinant using cofactor expansion along the first row
    det += mat.GetElement(0, 0) * (mat.GetElement(1, 1) * mat.GetElement(2, 2) - mat.GetElement(1, 2) * mat.GetElement(2, 1));
    det -= mat.GetElement(0, 1) * (mat.GetElement(1, 0) * mat.GetElement(2, 2) - mat.GetElement(1, 2) * mat.GetElement(2, 0));
    det += mat.GetElement(0, 2) * (mat.GetElement(1, 0) * mat.GetElement(2, 1) - mat.GetElement(1, 1) * mat.GetElement(2, 0));

    return det;
}

template <typename T>
Game::Math::Matrix3D<T> Game::Math::Mat3D_Inverse(const Game::Math::Matrix3D<T>& mat)
{
    T det = mat.Determinant();
    if (det == 0.0)
    {
       throw Game::Math::Exception::MatrixIsSingular("Matrix is singular");
    }
    
    Matrix3D<T> result = mat.Inverse();
    return result;
}

template <typename T>
Game::Math::Matrix3D<T> Game::Math::Mat3D_Transpose(const Game::Math::Matrix3D<T>& mat)
{
    T det = mat.Determinant();
    if (det == 0.0)
    {
        throw Game::Math::Exception::MatrixIsSingular("Matrix is singular");
    }
    
    Matrix3D<T> result = mat.Transpose();
    return result;
}

template <typename T>
bool Game::Math :: Mat3D_IsEqual(const Game::Math::Matrix3D<T>& mat1, const Game::Math::Matrix3D<T>& mat2)
{
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            if(mat1.GetElement(i, j) != mat2.GetElement(i, j))
            {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
bool Game::Math :: Mat3D_IsNotEqual(const Game::Math::Matrix3D<T>& mat1, const Game::Math::Matrix3D<T>& mat2)
{
    return !(Game::Math::Mat3D_IsEqual(mat1, mat2));
}

template <typename T>
std::ostream& operator<<(std::ostream& str, Game::Math::Matrix3D<T>& mat)
{
    str << "[ " << mat.GetElement(0, 0) << ", " << mat.GetElement(0, 1) << ", " << mat.GetElement(0, 2) << "\n  "
        << mat.GetElement(1, 0) << ", " << mat.GetElement(1, 1) << ", " << mat.GetElement(1, 2) << "\n  "
        << mat.GetElement(2, 0) << ", " << mat.GetElement(2, 1) << ", " << mat.GetElement(2, 2) << " ] " << "\n";
    return str;
}
