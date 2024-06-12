#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/MathAbstractTypes.h"
#include "Core/public/Math/MathFwd.h"
#include "Core/public/Math/Vector3.hpp"

#ifndef MATRIX3_H
#define MATRIX3_H

namespace Phanes::Core::Math {


    // 3x3 Matrix defined in column-major order.
    // Accessed by M[Row][Col].

    template<RealType T, bool S>
    struct TMatrix3
    {
    public:

        union
        {
            struct
            {
                /// <summary>
                /// Column one.
                /// </summary>
                TVector3<T, S> c0;

                /// <summary>
                /// Column two.
                /// </summary>
                TVector3<T, S> c1;

                /// <summary>
                /// Column three.
                /// </summary>
                TVector3<T, S> c2;
            };
        };

        T data[3][3];


    public:

        TMatrix3() = default;

        /**
         * Copy constructor.
         */

        TMatrix3(const TMatrix3<T, S>& m1)
        {
            this->c0 = TVector3<T, S>(m1.c0);
            this->c1 = TVector3<T, S>(m1.c1);
            this->c2 = TVector3<T, S>(m1.c2);
        }

        /**
         * Construct Matrix from 2d array.
         *
         * @param(fields) 2D Array with row major order.
         */

        TMatrix3(T fields[3][3])
        {
            this->c0 = TVector3<T, S>(fields[0][0], fields[1][0], fields[2][0]);
            this->c1 = TVector3<T, S>(fields[0][1], fields[1][1], fields[2][1]);
            this->c2 = TVector3<T, S>(fields[0][2], fields[1][2], fields[2][2]);
        }

        /**
         * Construct Matrix from parameters.
         *
         * @param(n00) M[0][0]
         * @param(n10) M[1][0]
         * @param(n01) M[0][1]
         * @param(n11) M[1][1]
         * ...
         *
         * @note nXY = n[Row][Col]
         */

        TMatrix3(T n00, T n01, T n02,
                 T n10, T n11, T n12,
                 T n20, T n21, T n22)
        {
            this->c0 = TVector3<T, S>(n00,n10,n20);
            this->c1 = TVector3<T, S>(n01,n11,n21);
            this->c2 = TVector3<T, S>(n02,n12,n22);
        }

        /**
         * Construct Matrix from two 2d vector columns.
         *
         * @param(v1) Column zero
         * @param(v2) Column one
         */

        TMatrix3(const TVector3<T, S>& v1, const TVector3<T, S>& v2, const TVector3<T, S> v3)
        {
            this->c0 = v1;
            this->c1 = v2;
            this->c2 = v3;
        }

    public:

        FORCEINLINE T& operator() (int n, int m)
        {
            return this->m[m][n];
        }

        FORCEINLINE TVector3<T>& operator[] (int m)
        {
            return (*reinterpret_cast<TVector3<T>*>(this->m[m]));
        }

        FORCEINLINE const T& operator() (int n, int m) const
        {
            return this->m[m][n];
        }

        FORCEINLINE const TVector3<T, S>& operator[] (int m) const
        {
            return (*reinterpret_cast<TVector3<T, S>*>(this->m[m]));
        }

    };


    // ==================== //
    //   Matrix3 operator   //
    // ==================== //

    /**
     * Adds scalar to matrix componentwise
     * 
     * @param(m) Matrix
     * @param(s) Scalar
     */

    template<RealType T, bool S>
    TMatrix3<T, S> operator+= (TMatrix3<T, S>& m1, T s)
    {
        m1.c0 += s;
        m1.c1 += s;
        m1.c2 += s;

        return m1;
    }

    /**
     * Adds matrix to matrix componentwise
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T, bool S>
    TMatrix3<T, S> operator+= (TMatrix3<T, S>& m1, const TMatrix3<T, S>& m2)
    {
        m1.c0 += m2.c0;
        m1.c1 += m2.c1;
        m1.c2 += m2.c2;

        return m1;
    }

    /**
     * Substract scalar from matrix componentwise
     *
     * @param(m) Matrix
     * @param(s) Scalar
     */

    template<RealType T, bool S>
    TMatrix3<T, S> operator-= (TMatrix3<T, S>& m1, T s)
    {
        m1.c0 -= s;
        m1.c1 -= s;
        m1.c2 -= s;

        return m1;
    }

    /**
     * Substract matrix from matrix componentwise
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T, bool S>
    TMatrix3<T, S> operator-= (TMatrix3<T, S>& m1, const TMatrix3<T, S>& m2)
    {
        m1.c0 -= m2.c0;
        m1.c1 -= m2.c1;
        m1.c2 -= m2.c2;

        return m1;
    }

    /**
     * Multiply matrix with scalar
     *
     * @param(m1) Matrix
     * @param(s) Scalar
     */

    template<RealType T, bool S>
    TMatrix3<T, S> operator*= (TMatrix3<T, S>& m1, T s)
    {
        m1.c0 *= ss;
        m1.c1 *= ss;
        m1.c2 *= ss;

        return m1;
    }

    /**
     * Matrix on matrix (componentwise)
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T, bool S>
    TMatrix3<T, S> operator*= (TMatrix3<T, S>& m1, const TMatrix3<T, S>& m2)
    {
        m1.c0 *= m2.c0;
        m1.c1 *= m2.c1;
        m1.c2 *= m2.c2;

        return m1;
    }

    /**
     * Add scalar to matrix componentwise
     *
     * @param(m1) Matrix
     * @param(s) Scalar
     */

    template<RealType T, bool S>
    TMatrix3<T, S> operator+ (const TMatrix3<T, S>& m, T s)
    {
        return TMatrix3<T, S>(m.c0 + s,
                            m.c1 + s,
                            m.c2 + s);
    }

    /**
     * Add matrix to matrix componentwise
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T, bool S>
    TMatrix3<T, S> operator+ (const TMatrix3<T, S>& m1, const TMatrix3<T, S>& m2)
    {
        return TMatrix2<T>(m1.c0 + m2.c0,
                           m1.c1 + m2.c1,
                           m1.c2 + m2.c2);
    }

    /**
     * Add scalar to matrix componentwise
     *
     * @param(m) Matrix
     * @param(s) Scalar
     */

    template<RealType T, bool S>
    TMatrix3<T, S> operator- (const TMatrix3<T, S>& m, T s)
    {
        return TMatrix3<T, S>(m1.c0 - s,
                              m1.c1 - s,
                              m1.c2 - s);
    }

    /**
     * Add scalar to matrix componentwise
     *
     * @param(m) Matrix
     * @param(s) Scalar
     */

    template<RealType T, bool S>
    TMatrix3<T, S> operator- (const TMatrix3<T, S>& m1, const TMatrix3<T, S>& m2)
    {
        return TMatrix3<T, S>(m1.c0 - m2.c0,
                              m1.c1 - m2.c1,
                              m1.c2 - m2.c2);
    }

    /**
     * Multiply scalar with matrix
     *
     * @param(m) Matrix
     * @param(s) Scalar
     */

    template<RealType T, bool S>
    TMatrix3<T, S> operator* (const TMatrix3<T, S>& m, float s)
    {
        return TMatrix3<T, S>(m.c0 * s,
                              m.c1 * s,
                              m.c2 * s);
    }

    /**
     * Multiplay matrix by matrix (componentwise)
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T, bool S>
    TMatrix3<T, S> operator* (const TMatrix3<T, S>& m1, const TMatrix3<T, S>& m2)
    {
        return TMatrix3<T, S>(m1.c0 + m2.c0,
                              m1.c1 + m2.c1,
                              m1.c2 + m2.c2);
    }

    /**
     * Compare matrix with other matrix.
     * 
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T, bool S>
    bool operator== (const TMatrix3<T, S>& m1, const TMatrix3<T, S>& m2)
    {
        return (m1[0] == m2[0] && m1[1] == m2[1] && m1[2] == m2[2]);
    }

    /**
     * Compare matrix with other matrix.
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T, bool S>
    bool operator!= (const TMatrix3<T, S>& m1, const TMatrix3<T, S>& m2)
    {
        return (m1[0] != m2[0] || m1[1] != m2[1] || m1[2] != m2[2]);
    }


    // =============================== //
    //   Matrix function definition    //
    // =============================== //

    /**
     * Calculate determinant of 3x3 Matrix
     * 
     * @param(m1) Matrix
     */
    
    template<RealType T, bool S>
    T Determinant(const TMatrix3<T, S>& m1)
    {
        return   m1(0, 0) * (m1(1, 1) * m1(2, 2) - m1(1, 2) * m1(2, 1))
               - m1(0, 1) * (m1(1, 0) * m1(2, 2) - m1(1, 2) * m1(2, 0))
               + m1(0, 2) * (m1(1, 0) * m1(2, 1) - m1(1, 1) * m1(2, 0));
    }

    /**
     * Calculate inverse of 3x3 Matrix
     *
     * @see [FUNC]Inverse
     * 
     * @param(m1) Matrix
     * 
     * @note Stores result in m1.
     */

    template<RealType T, bool S>
    TMatrix3<T, S> InverseV(TMatrix3<T, S>& m1)
    {
        const TVector3<T, S>& v0 = m1[0];
        const TVector3<T, S>& v1 = m1[1];
        const TVector3<T, S>& v2 = m1[2];

        TVector3<T, S> r0 = CrossP(v1, v2);
        TVector3<T, S> r1 = CrossP(v2, v0);
        TVector3<T, S> r2 = CrossP(v0, v1);

        T _1_det = (T)1.0 / Determinant(m1);

        m1 = TMatrix3<T, S>(r0.x, r0.y, r0.z,
                            r1.x, r1.y, r1.z,
                            r2.x, r2.y, r2.z);

        m1 *= _1_det;

        return m1;
    }

    /**
     * Get transpose of matrix.
     * 
     * @param(m1) Matrix
     * 
     * @note Result is stored in m1;
     */

    template<RealType T, bool S>
    TMatrix3<T, S> TransposeV(TMatrix3<T, S>& m1)
    {
        Swap(m1(0, 1), m1(1, 0));
        Swap(m1(0, 2), m1(2, 0));
        Swap(m1(1, 2), m1(2, 1));

        return m1;
    }


    // =============== //
    //   WITH RETURN   //
    // =============== //

    /**
     * Calculate inverse of 3x3 Matrix
     *
     * @param(m1) Matrix
     */

    template<RealType T, bool S>
    TMatrix3<T, S> Inverse(TMatrix3<T, S>& m1)
    {
        const TVector3<T>& v0 = m1[0];
        const TVector3<T>& v1 = m1[1];
        const TVector3<T>& v2 = m1[2];

        TVector3<T> r0 = CrossP(v1, v2);
        TVector3<T> r1 = CrossP(v2, v0);
        TVector3<T> r2 = CrossP(v0, v1);

        T _1_det = (T)1.0 / Determinant(m1);

        TMatrix3<T, S> inverse(r0.x, r0.y, r0.z,
            r1.x, r1.y, r1.z,
            r2.x, r2.y, r2.z);

        inverse *= _1_det;

        return inverse;
    }

    /**
     * Get transpose of matrix.
     *
     * @param(m1) Matrix
     *
     * @note Result is stored in m1;
     */

    template<RealType T, bool S>
    TMatrix3<T, S> Transpose(const TMatrix3<T, S>& m1)
    {
        return TMatrix3<T, S>(m1(0, 0), m1(1, 0), m1(2, 0),
                           m1(0, 1), m1(1, 1), m1(2, 1),
                           m1(0, 2), m1(1, 2), m1(2, 2));
    }
    
    /**
     * Checks if matrix is an identity matrix.
     */

    template<RealType T, bool S>
    bool IsIdentityMatrix(const TMatrix3<T, S>& m1)
    {
        return (abs(m1(0, 0) - (T)1.0) < P_FLT_INAC && abs(m1(0, 1) - (T)0.0) < P_FLT_INAC && abs(m1(0, 2) - (T)0.0) < P_FLT_INAC &&
                abs(m1(1, 0) - (T)0.0) < P_FLT_INAC && abs(m1(1, 1) - (T)1.0) < P_FLT_INAC && abs(m1(1, 2) - (T)0.0) < P_FLT_INAC &&
                abs(m1(2, 0) - (T)0.0) < P_FLT_INAC && abs(m1(2, 1) - (T)0.0) < P_FLT_INAC && abs(m1(2, 2) - (T)1.0) < P_FLT_INAC);
    }

} // Phanes::Core::Math


#endif // !MATRIX3_H
