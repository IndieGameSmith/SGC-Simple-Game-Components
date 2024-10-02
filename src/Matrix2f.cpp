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

Game::Math::Matrix2f Game::Math::Matrix2f :: operator+(const Game::Math::Matrix2f& other)
{
    Game::Math::Matrix2f result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] + other.elements[i][j];
        }
    }
    return result;
}

Game::Math::Matrix2f Game::Math::Matrix2f :: operator-(const Game::Math::Matrix2f& other)
{
    Game::Math::Matrix2f result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] - other.elements[i][j];
        }
    }
    return result;
}

Game::Math::Matrix2f Game::Math::Matrix2f :: operator*(double scaler)
{
    Game::Math::Matrix2f result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] * scaler;
        }
    }
    return result;
}

Game::Math::Matrix2f Game::Math::Matrix2f :: operator*(const Game::Math::Matrix2f& other)
{
    Game::Math::Matrix2f result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] * other.elements[i][j];
        }
    }
    return result;
}

Game::Math::Matrix2f Game::Math::Matrix2f :: operator/(double scaler)
{
    if (scaler == 0)
        throw Exception::DivisionByZero("Can't be divided 0");
    
    Game::Math::Matrix2f result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] / scaler;
        }
    }
    return result;
}

bool Game::Math::Matrix2f :: operator==(const Game::Math::Matrix2f& other) const
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

bool Game::Math::Matrix2f :: operator!=(const Game::Math::Matrix2f& other) const
{
    return !(*this == other);
}

Game::Math::Matrix2f Game::Math::Matrix2f :: Add(const Game::Math::Matrix2f& other)
{
    Game::Math::Matrix2f result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] + other.elements[i][j];
        }
    }
    return result;
}

Game::Math::Matrix2f Game::Math::Matrix2f :: Sub(const Game::Math::Matrix2f& other)
{
    Game::Math::Matrix2f result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] - other.elements[i][j];
        }
    }
    return result;
}

Game::Math::Matrix2f Game::Math::Matrix2f :: Multiply(const double scaler)
{
    Game::Math::Matrix2f result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] * scaler;
        }
    }
    return result;
}

Game::Math::Matrix2f Game::Math::Matrix2f :: Multiply(Game::Math::Matrix2f& other)
{
    Game::Math::Matrix2f result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] * other.elements[i][j];
        }
    }
    return result;
}

Game::Math::Matrix2f Game::Math::Matrix2f :: Divide(const double scaler)
{
    if (scaler == 0)
        throw Game::Math::Exception::DivisionByZero("Can't be divided 0");
    
    Game::Math::Matrix2f result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            result.elements[i][j] = elements[i][j] / scaler;
        }
    }
    return result;
}

double Game::Math::Matrix2f :: Determinant()
{
    return elements[0][0] * elements[1][1] - elements[0][1] * elements[1][0];
}

Game::Math::Matrix2f Game::Math::Matrix2f :: Inverse()
{
    double det = Determinant();
    if (det == 0.0)
    {
        throw Game::Math::Exception::MatrixIsSingular("Matrix is singular");
    }
    
    Matrix2f result;
    result.elements[0][0] = elements[1][1] / det;
    result.elements[0][1] = -elements[0][1] / det;
    result.elements[1][0] = -elements[1][0] / det;
    result.elements[1][1] = elements[0][0] / det;
    return result;
}

Game::Math::Matrix2f Game::Math::Matrix2f :: Transpose()
{
	Matrix2f result;
    result.elements[0][0] = elements[0][0];
    result.elements[0][1] = elements[1][0];
    result.elements[1][0] = elements[0][1];
    result.elements[1][1] = elements[1][1];
    return result;
}
	
double Game::Math::Matrix2f :: GetElement(int row, int col) const
{
    return elements[row][col];
}

void Game::Math::Matrix2f :: SetElement(int row, int col, double value)
{
    elements[row][col] = value;
}

Game::Math::Matrix2f Game::Math :: Mat2f_Add(Game::Math::Matrix2f& mat1, Game::Math::Matrix2f& mat2)
{
    Game::Math::Matrix2f result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            double val = mat1.GetElement(i, j) + mat2.GetElement(i, j);
            result.SetElement(i, j, val);
        }
    }
    return result;
}

Game::Math::Matrix2f Game::Math :: Mat2f_Substract(Game::Math::Matrix2f& mat1, Game::Math::Matrix2f& mat2)
{
    Game::Math::Matrix2f result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            double val = mat1.GetElement(i, j) - mat2.GetElement(i, j);
            result.SetElement(i, j, val);
        }
    }
    return result;
}

Game::Math::Matrix2f Game::Math :: Mat2f_Multiply(Game::Math::Matrix2f& mat1, Game::Math::Matrix2f& mat2)
{
    Game::Math::Matrix2f result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            double val = mat1.GetElement(i, j) * mat2.GetElement(i, j);
            result.SetElement(i, j, val);
        }
    }
    return result;
}

Game::Math::Matrix2f Game::Math :: Mat2f_Multiply(Game::Math::Matrix2f& mat1, const double scaler)
{
    Game::Math::Matrix2f result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            double val = mat1.GetElement(i, j) * scaler;
            result.SetElement(i, j, val);
        }
    }
    return result;
}

Game::Math::Matrix2f Game::Math :: Mat2f_Divide(Game::Math::Matrix2f& mat1, const double scaler)
{
    if (scaler == 0)
        throw Game::Math::Exception::DivisionByZero("Can't be divided by zero.");
        
    Game::Math::Matrix2f result;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            double val = mat1.GetElement(i, j) / scaler;
            result.SetElement(i, j, val);
        }
    }
    return result;
}

double Game::Math :: Mat2f_Determinant(Game::Math::Matrix2f& mat)
{
    return mat.GetElement(0, 0) * mat.GetElement(1, 1) - mat.GetElement(0, 1) * mat.GetElement(1, 0);
}

Game::Math::Matrix2f Game::Math::Mat2f_Inverse(Game::Math::Matrix2f& mat)
{
    double det = mat.Determinant();
    if (det == 0.0)
    {
        throw Game::Math::Exception::MatrixIsSingular("Matrix is singular");
    }
    
    Matrix2f result;
    double val1 = mat.GetElement(1, 1) / det;
    double val2 = 0 - (mat.GetElement(0, 1) / det);
    double val3 = 0 - (mat.GetElement(1, 0) / det);
    double val4 = mat.GetElement(0, 0) / det;
    
    result.SetElement(0, 0, val1);
    result.SetElement(0, 1, val2);
    result.SetElement(1, 0, val3);
    result.SetElement(1, 1, val4);
    return result;
}

Game::Math::Matrix2f Game::Math::Mat2f_Transpose(Game::Math::Matrix2f& mat)
{
    double det = mat.Determinant();
    if (det == 0.0)
    {
        throw Game::Math::Exception::MatrixIsSingular("Matrix is singular");
    }
    
    Matrix2f result;
    double val1 = mat.GetElement(0, 0);
    double val2 = mat.GetElement(1, 0);
    double val3 = mat.GetElement(0, 1);
    double val4 = mat.GetElement(1, 1);
    
    result.SetElement(0, 0, val1);
    result.SetElement(0, 1, val2);
    result.SetElement(1, 0, val3);
    result.SetElement(1, 1, val4);
    return result;
}

bool Game::Math :: Mat2f_IsEqual(Game::Math::Matrix2f& mat1, Game::Math::Matrix2f& mat2)
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

bool Game::Math :: Mat2f_IsNotEqual(Game::Math::Matrix2f& mat1, Game::Math::Matrix2f& mat2)
{
    return !(Game::Math::Mat2f_IsEqual(mat1, mat2));
}

std::ostream& operator<<(std::ostream& str, Game::Math::Matrix2f& mat)
{
    str << "[ " << mat.GetElement(0, 0) << ", " << mat.GetElement(0, 1) << "\n  " << mat.GetElement(1, 0) << ", " << mat.GetElement(1, 1) << " ] " << "\n";
    return str;
}
