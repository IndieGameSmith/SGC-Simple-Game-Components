/** 
 *  \file Matrix3D of Numbers.
 *
 *  \brief This supports Vector on 3 dimesionsal related  functions.
 *
 *  \author IndieGameSmith
 *  \date 2024-10-05
 */

#ifndef MATRIX3D_HPP_
#define MATRIX3D_HPP_

#include <iostream>

namespace Game
{
    namespace Math
    {
        template <typename T>
        struct Matrix3D
        {
            // Constructors
            Matrix3D();
            Matrix3D(T a, T b, T c, T d, T e, T f, T g, T h, T i);

            // Arithmetic operations
            Matrix3D<T> operator+(const Matrix3D<T>& other) const;
            Matrix3D<T> operator-(const Matrix3D<T>& other) const;
            Matrix3D<T> operator*(const T& scalar) const;
            Matrix3D<T> operator*(const Matrix3D<T>& other) const;
            Matrix3D<T> operator/(const T& scalar) const;

            // Comparison operators
            bool operator==(const Matrix3D<T>& other) const;
            bool operator!=(const Matrix3D<T>& other) const;

            // Additional matrix operations
            Matrix3D<T> Add(const Matrix3D<T>& other) const;
            Matrix3D<T> Sub(const Matrix3D<T>& other) const;
            Matrix3D<T> Multiply(const T& scalar) const;
            Matrix3D<T> Multiply(const Matrix3D<T>& other) const;
            Matrix3D<T> Divide(const T& scalar) const;
            T Determinant() const;
            Matrix3D<T> Inverse() const;
            Matrix3D<T> Transpose() const;
            bool IsEmpty() const;

            // Element access
            T GetElement(int row, int col) const;
            void SetElement(int row, int col, T value);

        private:
            T elements[3][3];
        };

        // Free functions for mathematical operations
        template <typename T>
        Matrix3D<T> Mat3D_Add(const Matrix3D<T>& mat1, const Matrix3D<T>& mat2);

        template <typename T>
        Matrix3D<T> Mat3D_Subtract(const Matrix3D<T>& mat1, const Matrix3D<T>& mat2);

        template <typename T>
        Matrix3D<T> Mat3D_Multiply(const Matrix3D<T>& mat, const T& scalar);

        template <typename T>
        Matrix3D<T> Mat3D_Multiply(const Matrix3D<T>& mat1, const Matrix3D<T>& mat2);

        template <typename T>
        Matrix3D<T> Mat3D_Divide(const Matrix3D<T>& mat, const T& scalar);

        template <typename T>
        T Mat3D_Determinant(const Matrix3D<T>& mat);

        template <typename T>
        Matrix3D<T> Mat3D_Inverse(const Matrix3D<T>& mat);

        template <typename T>
        Matrix3D<T> Mat3D_Transpose(const Matrix3D<T>& mat);

        // Free functions for logical operations
        template <typename T>
        bool Mat3D_IsEqual(const Matrix3D<T>& mat1, const Matrix3D<T>& mat2);

        template <typename T>
        bool Mat3D_IsNotEqual(const Matrix3D<T>& mat1, const Matrix3D<T>& mat2);

        // Stream operator for printing
        template <typename T>
        std::ostream& operator<<(std::ostream& str, const Matrix3D<T>& mat);
    } // namespace Math
} // namespace Game

#endif // MATRIX3D_HPP_

