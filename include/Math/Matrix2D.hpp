/** 
 *  \file Vector2D.hpp
 *  
 *  \brief Header file for Vector2D of Numbers.
 *
 *  This supports Vector on 2 dimesionsal related functions.
 *
 *  \author IndieGameSmith
 *  \date 2024-10-01
 */

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

namespace Game
{
    namespace Math
    {
        template <typename T>
        struct Matrix2x2
        {
            Matrix2x2()
            {
                elements[0][0] = 0.0;
                elements[0][1] = 0.0;
                elements[1][0] = 0.0;
                elements[1][1] = 0.0;
            }

            Matrix2x2(T a, T b, T c, T d)
            {
                elements[0][0] = a;
                elements[0][1] = b;
                elements[1][0] = c;
                elements[1][1] = d;
            }

            // Arithmetic operations
            Matrix2x2<T> operator+(const Matrix2x2<T>& other) const;
            Matrix2x2<T> operator-(const Matrix2x2<T>& other) const;
            Matrix2x2<T> operator*(const T& scalar) const;
            Matrix2x2<T> operator*(const Matrix2x2<T>& other) const;
            Matrix2x2<T> operator/(const T& scalar) const;

            // Comparison operators
            bool operator==(const Matrix2D<T>& other) const;
            bool operator!=(const Matrix2D<T>& other) const;

            // Additional matrix operations
            Matrix2x2<T> Add(const Matrix2x2<T>& other) const;
            Matrix2x2<T> Sub(const Matrix2x2<T>& other) const;
            Matrix2x2<T> Multiply(const T& scalar) const;
            Matrix2x2<T> Multiply(const Matrix2x2<T>& other) const;
            Matrix2x2<T> Divide(const T& scalar) const;
            T Determinant() const;
            Matrix2x2<T> Inverse() const;
            Matrix2x2<T> Transpose() const;

            // Element access
            T GetElement(int row, int col) const;
            void SetElement(int row, int col, T value);

        private:
            T elements[2][2];
        };

        // Free functions for mathematical operations
        template <typename T>
        Matrix2x2<T> Mat2x2_Add(const Matrix2x2<T>& mat1, const Matrix2x2<T>& mat2);

        template <typename T>
        Matrix2x2<T> Mat2x2_Subtract(const Matrix2x2<T>& mat1, const Matrix2x2<T>& mat2);

        template <typename T>
        Matrix2x2<T> Mat2x2_Multiply(const Matrix2x2<T>& mat, const T& scalar);

        template <typename T>
        Matrix2x2<T> Mat2x2_Multiply(const Matrix2x2<T>& mat1, const Matrix2x2<T>& mat2);

        template <typename T>
        Matrix2x2<T> Mat2x2_Divide(const Matrix2x2<T>& mat, const T& scalar);

        template <typename T>
        T Mat2x2_Determinant(const Matrix2x2<T>& mat);

        template <typename T>
        Matrix2x2<T> Mat2x2_Inverse(const Matrix2x2<T>& mat);

        template <typename T>
        Matrix2x2<T> Mat2x2_Transpose(const Matrix2x2<T>& mat);

        // Free functions for logical operations
        template <typename T>
        bool Mat2x2_IsEqual(const Matrix2x2<T>& mat1, const Matrix2x2<T>& mat2);

        template <typename T>
        bool Mat2x2_IsNotEqual(const Matrix2x2<T>& mat1, const Matrix2x2<T>& mat2);

        // Stream operator for printing
        template <typename T>
        std::ostream& operator<<(std::ostream& str, const Matrix2x2<T>& mat);
    } // namespace Math
} // namespace Game

#endif // MATRIX_HPP
