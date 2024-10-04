/** 
 *  \file Matrix2D of Numbers.
 *
 *  \brief This supports Vector on 2 dimesionsal related  functions.
 *
 *  \author IndieGameSmith
 *  \date 2024-10-01
 */

#ifndef MATRIX2D_HPP_
#define MATRIX2D_HPP_

#include <iostream>

namespace Game
{
    namespace Math
    {
        template <typename T>
        struct Matrix2D
        {
            Matrix2D()
            {
                elements[0][0] = 0.0;
                elements[0][1] = 0.0;
                elements[1][0] = 0.0;
                elements[1][1] = 0.0;
            }

            Matrix2D(T a, T b, T c, T d)
            {
                elements[0][0] = a;
                elements[0][1] = b;
                elements[1][0] = c;
                elements[1][1] = d;
            }

            // Arithmetic operations
            Matrix2D<T> operator+(const Matrix2D<T>& other) const;
            Matrix2D<T> operator-(const Matrix2D<T>& other) const;
            Matrix2D<T> operator*(const T& scalar) const;
            Matrix2D<T> operator*(const Matrix2D<T>& other) const;
            Matrix2D<T> operator/(const T& scalar) const;

            // Comparison operators
            bool operator==(const Matrix2D<T>& other) const;
            bool operator!=(const Matrix2D<T>& other) const;

            // Additional matrix operations
            Matrix2D<T> Add(const Matrix2D<T>& other) const;
            Matrix2D<T> Sub(const Matrix2D<T>& other) const;
            Matrix2D<T> Multiply(const T& scalar) const;
            Matrix2D<T> Multiply(const Matrix2D<T>& other) const;
            Matrix2D<T> Divide(const T& scalar) const;
            T Determinant() const;
            Matrix2D<T> Inverse() const;
            Matrix2D<T> Transpose() const;

            // Element access
            T GetElement(int row, int col) const;
            void SetElement(int row, int col, T value);

        private:
            T elements[2][2];
        };

        // Free functions for mathematical operations
        template <typename T>
        Matrix2D<T> Mat2D_Add(const Matrix2D<T>& mat1, const Matrix2D<T>& mat2);

        template <typename T>
        Matrix2D<T> Mat2D_Subtract(const Matrix2D<T>& mat1, const Matrix2D<T>& mat2);

        template <typename T>
        Matrix2D<T> Mat2D_Multiply(const Matrix2D<T>& mat, const T& scalar);

        template <typename T>
        Matrix2D<T> Mat2D_Multiply(const Matrix2D<T>& mat1, const Matrix2D<T>& mat2);

        template <typename T>
        Matrix2D<T> Mat2D_Divide(const Matrix2D<T>& mat, const T& scalar);

        template <typename T>
        T Mat2D_Determinant(const Matrix2D<T>& mat);

        template <typename T>
        Matrix2D<T> Mat2D_Inverse(const Matrix2D<T>& mat);

        template <typename T>
        Matrix2D<T> Mat2D_Transpose(const Matrix2D<T>& mat);

        // Free functions for logical operations
        template <typename T>
        bool Mat2D_IsEqual(const Matrix2D<T>& mat1, const Matrix2D<T>& mat2);

        template <typename T>
        bool Mat2D_IsNotEqual(const Matrix2D<T>& mat1, const Matrix2D<T>& mat2);

        // Stream operator for printing
        template <typename T>
        std::ostream& operator<<(std::ostream& str, const Matrix2D<T>& mat);
    } // namespace Math
} // namespace Game

#endif // MATRIX2D_HPP_

