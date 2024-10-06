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

#include "Maths/Matrix2f.hpp"
#include "Utils/Exceptions/Math_Exception.hpp"

#include <iostream>
#include <cmath>

template <typename T>
Game::Math::Matrix2D<T> Game::Math::Matrix2D<T> :: operator+(const Game::Math::Matrix2D<T>& other) const
{
    Game::Math::Matrix2D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] + other.elements[i][j];
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix2D<T> Game::Math::Matrix2D<T> :: operator-(const Game::Math::Matrix2D<T>& other) const
{
    Game::Math::Matrix2D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] - other.elements[i][j];
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix2D<T> Game::Math::Matrix2D<T> :: operator*(const T& scaler) const
{
    Game::Math::Matrix2D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] * scaler;
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix2D<T> Game::Math::Matrix2D<T> :: operator*(const Game::Math::Matrix2D<T>& other) const
{
    Game::Math::Matrix2D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] * other.elements[i][j];
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix2D<T> Game::Math::Matrix2D<T> :: operator/(const T& scaler) const
{
    if (scaler == 0)
          throw Exception::DivisionByZero("Can't be divided 0");
    
    Game::Math::Matrix2D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] / scaler;
        }
    }
    return result;
}

template <typename T>
bool Game::Math::Matrix2D<T> :: operator==(const Game::Math::Matrix2D<T>& other) const
{
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            if(elements[i][j] != other.elements[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
bool Game::Math::Matrix2D<T> :: operator!=(const Game::Math::Matrix2D<T>& other) const
{
    return !(*this == other);
}

template <typename T>
Game::Math::Matrix2D<T> Game::Math::Matrix2D<T> :: Add(const Game::Math::Matrix2D<T>& other) const
{
    Game::Math::Matrix2D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] + other.elements[i][j];
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix2D<T> Game::Math::Matrix2D<T> :: Sub(const Game::Math::Matrix2D<T>& other) const
{
    Game::Math::Matrix2D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] - other.elements[i][j];
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix2D<T> Game::Math::Matrix2D<T> :: Multiply(const T& scaler) const
{
    Game::Math::Matrix2D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] * scaler;
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix2D<T> Game::Math::Matrix2D<T> :: Multiply(const Game::Math::Matrix2D<T>& other) const
{
    Game::Math::Matrix2D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] * other.elements[i][j];
        }
    }
    return result;
}

template <typename T>
Game::Math::Matrix2D<T> Game::Math::Matrix2D<T> :: Divide(const T& scaler) const
{
    if (scaler == 0)
       throw Game::Math::Exception::DivisionByZero("Can't be divided 0");
    
    Game::Math::Matrix2D<T> result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] / scaler;
        }
    }
    return result;
}

template <typename T>
double Game::Math::Matrix2D<T> :: Determinant() const
{
    return elements[0][0] * elements[1][1] - elements[0][1] * elements[1][0];
}

template <typename T>
Game::Math::Matrix2D<T> Game::Math::Matrix2D<T> :: Inverse() const
{
    T det = Determinant();
    if (det == 0.0)
    {
        throw Game::Math::Exception::MatrixIsSingular("Matrix is singular");
    }
    
    Matrix2D<T> result;
    result.elements[0][0] = elements[1][1] / det;
    result.elements[0][1] = -elements[0][1] / det;
    result.elements[1][0] = -elements[1][0] / det;
    result.elements[1][1] = elements[0][0] / det;
    return result;
}

template <typename T>
Game::Math::Matrix2D<T> Game::Math::Matrix2D<T> :: Transpose() const
{
	Matrix2D<T> result;
    result.elements[0][0] = elements[0][0];
    result.elements[0][1] = elements[1][0];
    result.elements[1][0] = elements[0][1];
    result.elements[1][1] = elements[1][1];
    return result;
}

template <typename T>
bool Game::Math::Matrix2D<T> :: IsEmpty() const
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
T Game::Math::Matrix2D<T> :: GetElement(int row, int col) const
{
    return elements[row][col];
}

template <typename T>
void Game::Math::Matrix2D<T> :: SetElement(int row, int col, T value)
{
    elements[row][col] = value;
}

template <typename T>
Game::Math::Matrix2D<T> Game::Math :: Mat2D_Add(const Game::Math::Matrix2D<T>& mat1, const Game::Math::Matrix2D<T>& mat2)
{
    Game::Math::Matrix2D<T> result;
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
Game::Math::Matrix2D<T> Game::Math :: Mat2D_Subtract(const Game::Math::Matrix2D<T>& mat1, const Game::Math::Matrix2D<T>& mat2)
{
    Game::Math::Matrix2D<T> result;
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
Game::Math::Matrix2D<T> Game::Math :: Mat2D_Multiply(const Game::Math::Matrix2D<T>& mat1, const Game::Math::Matrix2D<T>& mat2)
{
    Game::Math::Matrix2D<T> result;
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
Game::Math::Matrix2D<T> Game::Math :: Mat2D_Multiply(const Game::Math::Matrix2D<T>& mat1, const T& scaler)
{
    Game::Math::Matrix2D<T> result;
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
Game::Math::Matrix2D<T> Game::Math :: Mat2D_Divide(const Game::Math::Matrix2D<T>& mat1, const T& scaler)
{
    if (scaler == 0)
      throw Game::Math::Exception::DivisionByZero("Can't be divided by zero.");
        
    Game::Math::Matrix2D<T> result;
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
double Game::Math :: Mat2D_Determinant(const Game::Math::Matrix2D<T>& mat)
{
    return mat.GetElement(0, 0) * mat.GetElement(1, 1) - mat.GetElement(0, 1) * mat.GetElement(1, 0);
}

template <typename T>
Game::Math::Matrix2D<T> Game::Math::Mat2D_Inverse(const Game::Math::Matrix2D<T>& mat)
{
    T det = mat.Determinant();
    if (det == 0.0)
    {
       throw Game::Math::Exception::MatrixIsSingular("Matrix is singular");
    }
    
    Matrix2D<T> result;
    T val1 = mat.GetElement(1, 1) / det;
    T val2 = 0 - (mat.GetElement(0, 1) / det);
    T val3 = 0 - (mat.GetElement(1, 0) / det);
    T val4 = mat.GetElement(0, 0) / det;
    
    result.SetElement(0, 0, val1);
    result.SetElement(0, 1, val2);
    result.SetElement(1, 0, val3);
    result.SetElement(1, 1, val4);
    return result;
}

template <typename T>
Game::Math::Matrix2D<T> Game::Math::Mat2D_Transpose(const Game::Math::Matrix2D<T>& mat)
{
    T det = mat.Determinant();
    if (det == 0.0)
    {
        throw Game::Math::Exception::MatrixIsSingular("Matrix is singular");
    }
    
    Matrix2D<T> result;
    T val1 = mat.GetElement(0, 0);
    T val2 = mat.GetElement(1, 0);
    T val3 = mat.GetElement(0, 1);
    T val4 = mat.GetElement(1, 1);
    
    result.SetElement(0, 0, val1);
    result.SetElement(0, 1, val2);
    result.SetElement(1, 0, val3);
    result.SetElement(1, 1, val4);
    return result;
}

template <typename T>
bool Game::Math :: Mat2D_IsEqual(const Game::Math::Matrix2D<T>& mat1, const Game::Math::Matrix2D<T>& mat2)
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
bool Game::Math :: Mat2D_IsNotEqual(const Game::Math::Matrix2D<T>& mat1, const Game::Math::Matrix2D<T>& mat2)
{
    return !(Game::Math::Mat2D_IsEqual(mat1, mat2));
}

template <typename T>
std::ostream& operator<<(std::ostream& str, Game::Math::Matrix2D<T>& mat)
{
    str << "[ " << mat.GetElement(0, 0) << ", " << mat.GetElement(0, 1) << "\n  " << mat.GetElement(1, 0) << ", " << mat.GetElement(1, 1) << " ] " << "\n";
    return str;
}
