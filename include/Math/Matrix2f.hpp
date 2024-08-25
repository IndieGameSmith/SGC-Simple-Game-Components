/** 
 *  \file Matrix2f.hpp
 *  
 *  \brief Header file for Matrix2f of 4 double point integers.
 *
 *  This supports Matrix2x2 related functions.
 *
 *  \author IndieGameSmith
 *  \date 2024-08-24
 */
 
#ifndef MATRIX2F_HPP_
#define MATRIX2F_HPP_

#include <iostream>

namespace Game
{

namespace Math
{

struct Matrix2f
{
    Matrix2f()
    {
        elements[0][0] = 0.0f;
        elements[0][1] = 0.0f;
        elements[1][0] = 0.0f;
        elements[1][1] = 0.0f;
    }
    
    Matrix2f(double a, double b, double c, double d)
    {
        elements[0][0] = a;
        elements[0][1] = b;
        elements[1][0] = c;
        elements[1][1] = d;
    }

	Matrix2f operator+(const Matrix2f& other);
	Matrix2f operator-(const Matrix2f& other);
	Matrix2f operator*(double scaler);
	Matrix2f operator*(const Matrix2f& other);
	Matrix2f operator/(double scaler);
	bool operator==(const Matrix2f& other) const;
	bool operator!=(const Matrix2f& other) const;
	
	Matrix2f Add(const Matrix2f& other);
	Matrix2f Sub(const Matrix2f& other);
	Matrix2f Multiply(const double scaler);
	Matrix2f Multiply(Matrix2f& other);
	Matrix2f Divide(const double scaler);
	double Determinant();
	Matrix2f Inverse();
	Matrix2f Transpose(); 
	
	double GetElement(int row, int col) const;
	void SetElement(int row, int col, double value);
	
private:  
    double elements[2][2];
};

/** Mathematical Opreations */

Matrix2f Mat2f_Add(Matrix2f& mat1, Matrix2f& mat2);
/**
 *  \param mat1 First Matrix2f.
 *  \param mat2 Second Matrix2f.
 *
 *  \brief Add two Matrix2f quantities.
 *
 *  \return Returns a Resultant Matrix2f quantity.
 *
 *  \sa Mat2f_Substract()
 *  \sa Mat2f_Multiply()
 *  \sa Mat2f_Dimatide()
 *
 */

Matrix2f Mat2f_Substract(Matrix2f& mat1, Matrix2f& mat2);
/**
 *  \param mat1 First Matrix2f.
 *  \param mat2 Second Matrix2f.
 *
 *  \brief Substract two Matrix2f quantities.
 *
 *  \return Returns a Resultant Matrix2f quantity.
 *
 *  \sa Mat2f_Add()
 *  \sa Mat2f_Multiply()
 *  \sa Mat2f_Dimatide()
 *
 */
 
Matrix2f Mat2f_Multiply(Matrix2f& mat, const double scaler);
/**
 *  \param mat Matrix2f quantity.
 *  \param scaler Scaler quantity to be mutilplied.
 *
 *  \brief Multipy a Matrix2f quantity with a scaler.
 *
 *  \return Returns a Resultant Matrix2f quantity.
 *
 *  \sa Mat2f_Add()
 *  \sa Mat2f_Substract()
 *  \sa Mat2f_Dimatide()
 *
 */
 
Matrix2f Mat2f_Multiply(Matrix2f& mat1, Matrix2f& mat2);
/**
 *  \param mat1 Matrix2f quantity.
 *  \param mat2 Matrix2f quantity.
 *
 *  \brief Multipy a Matrix2f quantity with other Matrix2f quantity.
 *
 *  \return Returns a Resultant Matrix2f quantity.
 *
 *  \sa Mat2f_Add()
 *  \sa Mat2f_Substract()
 *  \sa Mat2f_Dimatide()
 *
 */
 
Matrix2f Mat2f_Divide(Matrix2f& mat, const double scaler);
/**
 *  \param mat Matrix2f quantity.
 *  \param scaler Scaler quantity to be dimatided.
 *
 *  \brief Multipy a Matrix2f quantity with a scaler.
 *
 *  \throw DimatisionByZero Error if dimatision by zero '0' occurs.
 *
 *  \return Returns a Resultant Matrix2f quantity.
 *
 *
 *  \sa Mat2f_Add()
 *  \sa Mat2f_Substract()
 *  \sa Mat2f_Multiply()
 *
 */
 
double Mat2f_Determinant(Matrix2f& mat);
/**
 *  \param mat Matrix2f quantity.
 *
 *  \brief Calvulates Determinant of Mat.
 *
 *  \return Returns a determinant.
 */
 
Matrix2f Mat2f_Inverse(Matrix2f& mat);
/**
 *  \param mat Matrix2f quantity.
 *
 *  \brief Inverse mat.
 *
 *  \return Returns Inversed Matrix2f.
 */
 
Matrix2f Mat2f_Transpose(Matrix2f& mat);
/**
 *  \param mat Matrix2f quantity.
 *
 *  \brief Transpose mat.
 *
 *  \return Returns Transposed Matrix2f.
 */
 
/** Logical Operations */

bool Mat2f_IsEqual(Matrix2f& mat1, Matrix2f& mat2);
/**
 *  \param mat1 First Matrix2f.
 *  \param mat2 Second Matrix2f.
 *
 *  \brief Logically compare two Matrix2f quantities.
 *
 *  \return Returns true or false.
 *
 *  \sa Mat2f_IsNotEqual()
 *
 */
 
bool Mat2f_IsNotEqual(Matrix2f& mat1, Matrix2f& mat2);
/**
 *  \param mat1 First Matrix2f.
 *  \param mat2 Second Matrix2f.
 *
 *  \brief Logically compare two Matrix2f quantities.
 *
 *  \return Returns true or false.
 *
 *  \sa Mat2f_IsEqual()
 *
 */
 
/** For printing Matrix2f on console, For debugging Purposes */
 
std::ostream& operator<<(std::ostream str, Matrix2f& mat);

} // namespace Math

} // namespace Game

#endif // MATRIX2F_HPP_
