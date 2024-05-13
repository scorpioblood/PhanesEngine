#pragma once

#include "Core/Core.h"
#include "Core/public/Misc/Boilerplate.h"

#include "Core/public/Math/MathCommon.h"
#include "Core/public/Math/MathAbstractTypes.h"
#include "Core/public/Math/MathFwd.h"

#ifndef P_DEBUG
#pragma warning(disable : 4244)
#endif

#ifndef VECTOR2_H
#define VECTOR2_H

#define PZeroVector2(type)		TVector2<##type>(0,0)
#define PVectorSouth2(type)		TVector2<##type>(0,-1)
#define PVectorNorth2(type)		TVector2<##type>(0,1)
#define PVectorEast2(type)		TVector2<##type>(1,0)
#define PVectorWest2(type)		TVector2<##type>(-1,0)


namespace Phanes::Core::Math {

  /** 
   * A 2D Vector with components x and y with floating point precision.
   */
  
  
  template<RealType T>
  struct TVector2 {

  public:

    using Real = T;

    // Using in combination with a struct and an array allows us the reflect changes of the x and y variables in the comp array and vise versa.

    union 
    {
    
      struct
      {
        /** X component of Vector
         *
         * @see [FIELD]components
         * @note x does not hold the component, but is a reference two the second item in the components array. The varibale exists wholly for convenience.
         */
        Real x;
          
        /** Y component of Vector 
         * 
         * @see [FIELD]components
         * 
         * @note y does not hold the component, but is a reference two the second item in the components array. The varibale exists wholly for convenience.
         */
        Real y;
      };

      /** Components array holding the data 
       * 
       * @see [FIELD]x
       * @see [FIELD]y
       * 
       * @note Components are split into x and y. Access and manipulation is possible by these variables. 
       */

      Real comp[2];

    };




  public:

    /**
     * Default constructor without initialization
     */

    TVector2() = default;
    
    /**
     * Copy constructor
     */

    TVector2(const TVector2<Real>& v);

    /**
     * Move constructor
     */

    TVector2(TVector2<Real>&& v);

    /**
     * Convert other type of vector
     */

    template<RealType FloatType>
    explicit TVector2(const TVector2<FloatType>& v) : x((T)v.x), y((T)v.y) {};


    template<IntType OtherIntType>
    explicit TVector2(const TIntVector2<OtherIntType>& v) : x((T)v.x), y((T)v.y) {};

    /**
     * Construct Vector from xy components.
     * 
     * @param(x) X component
     * @param(y) Y component
     */

    TVector2(const Real x, const Real y);

    /**
     * Construct Vector from two component array.
     *
     * @param(comp) Array of components
     */

    explicit TVector2(const Real* comp);


    /**
     * Constructs a vector pointing from start to end.
     *
     * @param(start) Startingpoint
     * @param(end) Endpoint
     */

    TVector2(const TPoint2<Real>& start, const TPoint2<Real>& end);

    /**
     * Construct Vector from 3D Vector's xy.
     *
     * @param(v) 3D Vector to copy from
     */

    explicit TVector2(const TVector3<Real>& v);

    /**
     * Construct Vector from 4D Vector's xy.
     *
     * @param(v) 4D Vector to copy from
     */

    //TVector2(const TVector4<Real>& v);

    /**
     * Construct Vector from 2D integer Vector's xy.
     *
     * @param(v) 2D IntVector to copy from
     */ 

    //TVector2(const TIntVector2<Real>& v);

    /**
     * Construct Vector from 3D integer Vector's xy.
     *
     * @param(v) 3D IntVector to copy from
     */

    //TVector2(const TIntVector3<Real>& v);

    /**
     * Construct Vector from 4D integer Vector's xy.
     *
     * @param(v) 4D IntVector to copy from
     */

    //TVector2(const TIntVector4<Real>& v);

    /**
     * Construct Vector from 2D Point's xy.
     *
     * @param(v) 2D Point to copy from
     */

    //TVector2(const TPoint2<Real>& v);


  }; 

  // ====================== //
  //   TVector2 operators   //
  // ====================== //
  
  /**
   * Addition operation on same TVector2<T> (this) by a floating point value.
   * 
   * @param(v1) Vector to add to
   * @param(s) Floating point to add
   */

  template<RealType T>
  TVector2<T> operator+= (TVector2<T>& v1, T s);

  /**
   * Addition operation on same TVector2<T> (this) by a another TVector2<T>.
   *
   * @param(v1) Vector to add to
   * @param(v2) Vector to add
   */

  template<RealType T>
  TVector2<T> operator+= (TVector2<T>& v1, const TVector2<T>& v2);

  /**
   * Substraction operation on same TVector2<T> (this) by a floating point.
   *
   * @param(v1) Vector to substract from
   * @param(v2) Floating point to substract
   */

  template<RealType T>
  TVector2<T> operator-= (TVector2<T>& v1, T s);

  /**
   * Substraction operation on same TVector2<T> (this) by a another TVector2<T>.
   *
   * @param(v1) Vector to substract from
   * @param(v2) Vector to substract
   */

  template<RealType T>
  TVector2<T> operator-= (TVector2<T>& v1, const TVector2<T>& v2);

  /**
   * Multiplication of TVector2<T> (this) with a floating point. 
   *
   * @param(v1) Vector to multiply with
   * @param(s Floating point to multiply with
   */

  template<RealType T>
  TVector2<T> operator*= (TVector2<T>& v1, T s);

  /**
   * Devision of Vector (this) by floating point.
   *
   * @param(v1) Vector to divide with
   * @param(s Floating point to divide with
   */

  template<RealType T>
  TVector2<T> operator/= (TVector2<T>& v1, T s);

  /**
   * Scale of Vector by floating point. (> Creates a new TVector2<T>)
   *
   * @param(v1) Vector to multiply with
   * @param(s Floating point to multiply with
   * 
   * @return Result Vector
   */

  template<RealType T>
  TVector2<T> operator* (const TVector2<T>& v1, T s);

  /**
   * Division of Vector by floating point. (> Creates another TVector2<T>)
   *
   * @param(v1) Vector to multiply with
   * @param(s Floating point to divide with
   * 
   * @return Result Vector
   */

  template<RealType T>
  TVector2<T> operator/ (const TVector2<T>& v1, T s);

  /**
   * Scale of Vector by floating point. (> Creates a new TVector2<T>)
   *
   * @param(v1) Vector to multiply with
   * @param(s Floating point to multiply with
   * 
   * @return Result Vector
   */

  template<RealType T>
  inline TVector2<T> operator* (T s, const TVector2<T>& v1);

  /**
   * Division of Vector by floating point. (> For convenience not arithmethicaly correct. Works like overloaded counterpart.)
   *
   * @param(v1) Vector to multiply with
   * @param(s Floating point to divide with
   * 
   * @return Result Vector
   */

  template<RealType T>
  inline TVector2<T> operator/ (T s, const TVector2<T>& v1);

  /**
   * Dot product between two Vectors.
   *
   * @see [FUNC]DotP
   * 
   * @param(v1) Vector one
   * @param(v2) Vector two
   * 
   * @result Dot product 
   */

  template<RealType T>
  T operator* (const TVector2<T>& v1, const TVector2<T>& v2);

  /**
   * Componentwise addition of Vector with floating point. 
   *
   * @param(v1) Vector to add to
   * @param(s Floating point to add
   * 
   * @return Result Vector
   */

  template<RealType T>
  TVector2<T> operator+ (const TVector2<T>& v1, T s);
        
  /**
   * Componentwise addition of Vector with floating point. 
   *
   * @param(v1) Vector to add to
   * @param(s Floating point to add
   * 
   * @return Result Vector
   */

  template<RealType T>
  TVector2<T> operator+ (const TVector2<T>& v1, const TVector2<T>& v2);

  /**
   * Componentwise substraction of Vector with floating point.
   *
   * @param(v1) Vector to substract from
   * @param(s Floating point to substract
   * 
   * @return Result Vector
   */

  template<RealType T>
  TVector2<T> operator- (const TVector2<T>& v1, T s);

  /**
   * Componentwise substraction of Vector with Vector.
   *
   * @param(v1) Vector to substract from
   * @param(s Floating point to substract
   * 
   * @return Result Vector
   */

  template<RealType T>
  TVector2<T> operator- (const TVector2<T>& v1, const TVector2<T>& v2);

  /**
   * Negate Vector.
   *
   * @param(v1) Vector to negate
   */

  template<RealType T>
  void operator- (TVector2<T>& v1);


  /**
   * Compare Vector for equality. 
   * 
   * @see [FUNC]Equals
   *
   * @param(v1) Vector to negate
   * 
   * @return true if equal, false if inequal
   */

  template<RealType T>
  bool operator== (const TVector2<T>& v1, const TVector2<T>& v2);


  /**
    * Compare Vector for inequality.
    *
    * @see [FUNC]Equals
    *
    * @param(v1) Vector to negate
    * 
    * @return true if inequal, false if equal
    */

  template<RealType T>
  bool operator!= (const TVector2<T>& v1, const TVector2<T>& v2);


  // ============================================ //
  //    TVector2 static function implementation	//
  // ============================================ //

  /**
   * Magnitude of Vector
   *
   * @param(v1) Vector
   *
   * @return Size of Vector
   */

  template<RealType T>
  T Magnitude(const TVector2<T>& v1);

  /**
   * @see [FUNC]Magnitude
   */
  template<RealType T>
  FORCEINLINE T Length(const TVector2<T>& v1) { return Magnitude(v1); };

  /**
   * Square of magnitude of Vector
   *
   * @param(v1) Vector
   *
   * @return Magnitude without calculating square root
   */

  template<RealType T>
  T SqrMagnitude(const TVector2<T>& v1);

  /**
   * @see [FUNC]SqrMagnitude
   */
  template<RealType T>
  FORCEINLINE T SqrLength(const TVector2<T>& v1) { return SqrMagnitude(v1); };

  /**
   * Normalize Vector 
   *
   * @param(v1) Vector
   */

  template<RealType T>
  TVector2<T> NormalizeV(TVector2<T>& v1);

  /**
   * Normalize Vector
   *
   * @param(v1) Vector
   * 
   * @note Does not look for zero vector.
   */

  template<RealType T>
  TVector2<T> UnsafeNormalizeV(TVector2<T>& v1);

  /**
   * Angle between to Vectors
   *
   * @param(v1) Vector one
   * @param(v2) Vector two
   */

  template<RealType T>
  T Angle(const TVector2<T>& v1, const TVector2<T>& v2);

  /**
   * Cosine of angle between to Vectors
   *
   * @param(v1) Vector one
   * @param(v2) Vector two
   */

  template<RealType T>
  T CosineAngle(const TVector2<T>& v1, const TVector2<T>& v2);

  /**
   * Returns signs of components in vector: -1 / +1 / 0.
   *
   * @param(v1) Vector one
   */

  template<RealType T>
  TVector2<T> SignVectorV(TVector2<T>& v1);

  /**
   * Binds a vector to a square with a radius
   *
   * @param(v1) Vector one
   * @param(radius) Radius of square (=> Distance from middle to center of each site.)
   */

  template<RealType T>
  TVector2<T> BindToSquareV(TVector2<T>& v1, T radius);

  /**
   * Clamps a vector to a square with a radius
   *
   * @param(v1) Vector one
   * @param(radius) Radius of square (=> Distance from middle to center of each site.)
   */

  template<RealType T>
  TVector2<T> ClampToSquareV(TVector2<T>& v1, T radius);

  /**
   * Dot product of two Vectors
   * 
   * @param(v1) Vector one
   * @param(v2) Vector two
   */

  template<RealType T>
  T DotP(const TVector2<T>& v1, const TVector2<T>& v2);

  /**
   * Creates Vector, with component wise largest values. 
   *
   * @param(v1) Vector one
   * @param(v2) Vector two
   * 
   * @note Stores new Vector to v1
   */

  template<RealType T>
  TVector2<T> MaxV (TVector2<T>& v1, const TVector2<T>& v2);

  /**
   * Creates Vector, with component wise smallest values.
   *
   * @param(v1) Vector one
   * @param(v2) Vector two
   *
   * @note Stores new Vector to v1
   */

  template<RealType T>
  TVector2<T> MinV (TVector2<T>& v1, const TVector2<T>& v2);

  /**
   * Gets perpendicular Vector to v1.
   * 
   * @param(v1) Vector one
   *
   * @note Stores new Vector to v1
   */

  template<RealType T>
  TVector2<T> GetPerpendicularV (TVector2<T>& v1);

  /**
   * Gets perpendicular Vector to v1.
   *
   * @reg [FUNC]PerpendicularV
   *
   * @param(v1) Vector one
   *
   * @note Stores new Vector to v1
   */

  template<RealType T>
  TVector2<T> GetReversePerpendicularV (TVector2<T>& v1);

  /**
   * Component wise multiplication of Vector
   *
   * @param(v1) Vector one
   * @param(v2) Vector two
   *
   * @note Stores new Vector to v1
   */

  template<RealType T>
  TVector2<T> ScaleV(TVector2<T>& v1, const TVector2<T>& v2);

  /**
   * Componentwise inverse of Vector
   *
   * @param(v1) Vector one
   *
   * @note Stores new Vector to v1
   */

  template<RealType T>
  TVector2<T> CompInverseV(TVector2<T>& v1);

  /**
   * Reflect Vector by normal vector.
   *
   * @param(v1) Vector one
   * @param(normal) Normal of surface
   *
   * @note Stores new Vector to v1
   */

  template<RealType T>
  TVector2<T> ReflectV (TVector2<T>& v1, const TVector2<T>& normal);

  /**
   * Copies one Vector two another
   *
   * @param(v1) Vector to copy to
   * @param(v2) Vector to copy
   */

  template<RealType T>
  TVector2<T> Set(TVector2<T>& v1, const TVector2<T>& v2);

  /**
   * Sets components of a vector.
   *
   * @param(v1) Vector to copy to
   * @param(v2) Vector to copy
   */

  template<RealType T>
  TVector2<T> Set(TVector2<T>& v1, T x, T y);

  /**
   * Anti-clockwise vector rotation.
   *
   * @param(v1) Vector to rotate
   *
   * @note Angle is not clamped
   */

  template<RealType T>
  TVector2<T> RotateV(TVector2<T>& v1, T angle);


  /**
   * Clockwise vector rotation.
   *
   * @param(v1) Vector to rotate
   *
   * @note Angle is not clamped
   */

  template<RealType T>
  FORCEINLINE TVector2<T> ClockwiseRotateV(TVector2<T>& v1, T angle);

  /**
   * Negates Vector
   *
   * @param(v1) Vector one
   */

  template<RealType T>
  TVector2<T> NegateV(TVector2<T>& v1);

  /**
   * Tests if vector is a unity vector.
   *
   * @param(v1) Vector one
   * @param(threshold) Threshold to zero
   * 
   * @return true if unit vector, false if not
   */

  template<RealType T>
  inline bool IsNormalized(const TVector2<T>& v1, T threshold = P_FLT_INAC);

  /**
   * Tests if 2 vectors are perpendicular to each other.
   *
   * @param(v1) Vector one
   * @param(v2) Vector two
   * @param(threshold) Threshold to zero
   * 
   * @return true if perpendicular, false if not
   * 
   * @note Requires v1 and v2 to be normal vectors.
   */

  template<RealType T>
  inline bool IsPerpendicular(const TVector2<T>& v1, const TVector2<T>& v2, T threshold = P_FLT_INAC);

  /**
   * Tests if 2 vectors are parallel to each other. (Angle is close to zero.)
   *
   * @param(v1) Vector one
   * @param(v2) Vector two
   * @param(t) threshold Threshold from one (e.g. 0.98f)
   * 
   * @return true if parallel, false if not
   *
   * @note Requires v1 and v2 to be normal vectors.
   */

  template<RealType T>
  inline bool IsParallel(const TVector2<T>& v1, const TVector2<T>& v2, T threshold = 1.0f - P_FLT_INAC);

  /**
   * Tests if 2 vectors are coincident. (Are parallel and point in the same direction.)
   *
   * @param(v1) Vector one
   * @param(v2) Vector two
   * @param(threshold) from one (e.g. 0.98f)
   *
   * @return true if coincident, false if not
   * 
   * @note Requires v1 and v2 to be normal vectors.
   */

  template<RealType T>
  inline bool IsCoincident(const TVector2<T>& v1, const TVector2<T>& v2, T threshold = 1.0f - P_FLT_INAC);

  /**
   * Gets outer product of to vectors.
   *
   * @param(v1) Vector one
   * @param(v2) Vector two
   * 
   * @return Resulting matrix
   */

  //
  //Matrix2 OuterProduct(const TVector2<T>& v1, const TVector2<T>& v2);


  // ============================================================== //
  //   TVector2 static function implementation with return values   // 
  // ============================================================== //


  /**
   * Reflects a vector on a normal
   *
   * @param(v1) Vector one
   * @param(normal) Normal of surface
   *
   * @return Reflected vector
   */

  template<RealType T>
  TVector2<T> Reflect(const TVector2<T>& v1, const TVector2<T>& normal);

  /**
   * Scales a vector component wise
   * 
   * @param(v1) Vector one
   * @param(v2) Vector two
   *
   * @return Reflected vector
   */

  template<RealType T>
  TVector2<T> Scale(const TVector2<T>& v1, const TVector2<T>& v2);

  /**
   * Componentwise inverse of a vector
   *
   * @param(v1) Vector one
   *
   * @return Componentwise inverted vector
   */

  template<RealType T>
  TVector2<T> CompInverse(const TVector2<T>& v1);


  /**
   * Negates Vector
   * 
   * @param(v1) Vector one
   *
   * @return Componentwise inverted vector
   */

  template<RealType T>
  TVector2<T> Negate(const TVector2<T>& v1);

  /**
   * Gets the perpendicular vector of v1
   *
   * @param(v1) Vector one
   *
   * @return Perpendicular vector
   */

  template<RealType T>
  TVector2<T> GetPerpendicular(const TVector2<T>& v1);

  /**
   * Gets reverse of the perpendicular vector of v1
   *
   * @param(v1) Vector one
   *
   * @return Reversed perpendicular vector
   */

  template<RealType T>
  TVector2<T> GetReversePerpendicular(const TVector2<T>& v1);

  /**
   * Creates a new Vector by the component wise minimals of both vectors
   *
   * @param(v1) Vector one
   * @param(v2) Vector two
   *
   * @return Minimal vector
   */

  template<RealType T>
  TVector2<T> Min(const TVector2<T>& v1, const TVector2<T>& v2);

  /**
   * Creates a new Vector by the component wise maxima of both vectors
   *
   * @param(v1) Vector one
   * @param(v2) Vector two
   *
   * @return Maximal vector
   */

  template<RealType T>
  TVector2<T> Max(const TVector2<T>& v1, const TVector2<T>& v2);

  /**
   * Creates a normalized instance of the vector
   *
   * @param(v1) Vector to normalize
   * 
   * @return Unit vector
   */

  template<RealType T>
  TVector2<T> Normalize(const TVector2<T>& v1);

  /**
   * Creates a normalized instance of the vector
   *
   * @param(v1) Vector to normalize
   *
   * @return Unit vector
   * @note Does not test for zero vector
   */

  template<RealType T>
  TVector2<T> UnsafeNormalize(const TVector2<T>& v1);

  /**
   * Returns signs of components in vector: -1 / +1 / 0.
   *
   * @param(v1) Vector one
   * 
   * @return Vector with signs as components
   */

  template<RealType T>
  TVector2<T> SignVector(const TVector2<T>& v1);

  /**
   * Binds a vector to a square with a radius
   *
   * @param(v1) Vector one
   * @param(radius) Radius of square (=> Distance from middle to center of each site.)
   * 
   * @return Bound vector
   */

  template<RealType T>
  TVector2<T> BindToSquare(const TVector2<T>& v1, T radius);

  /**
   * Clamps a vector to a square with a radius
   *
   * @param(v1) Vector one
   * @param(radius) Radius of square (=> Distance from middle to center of each site.)
   *
   * @return Clamped vector. If the length of the vector fits the square, then the vector is returned.
   */

  template<RealType T>
  TVector2<T> ClampToSquare(const TVector2<T>& v1, T radius);

  /**
   * Interpolates between to vectors.
   *
   * @param(startVec) Start vector (t = 0)
   * @param(destVec) Destination vector (t = 1)
   * @param(t) Interpolation value
   *
   * @return Interpolated vector
   * 
   * @note Interpolation is clamped between 0 - 1.
   */

  template<RealType T>
  TVector2<T> Lerp(const TVector2<T>& startVec, const TVector2<T>& destVec, T t);

  /**
   * Interpolates between to vectors. 
   *
   * @param(startVec) Start vector (t = 0)
   * @param(destVec) Destination vector (t = 1)
   * @param(t) Interpolation value
   *
   * @return Interpolated vector
   * 
   * @note Interpolation is not clamped. Make shure t is between 0.0f and 1.0f
   */

  template<RealType T>
  TVector2<T> LerpUnclamped(const TVector2<T>& startVec, const TVector2<T>& destVec, T t);

  /**
   * Anti-clockwise vector rotation.
   *
   * @param(v1) Vector to rotate
   * @param(angle) Angle to rotate
   *
   * @return Rotated vector
   * 
   * @note Angle is not clamped
   */

  template<RealType T>
  TVector2<T> Rotate(const TVector2<T>& v1, T angle);

  /**
   * Clockwise vector rotation.
   *
   * @param(v1) Vector to rotate
   *
   * @return Rotated vector
   *
   * @note Angle is not clamped
   */

  template<RealType T>
  TVector2<T> ClockwiseRotate(const TVector2<T>& v1, T angle);

} // phanes::core::math::coretypes

#endif // !VECTOR2_H