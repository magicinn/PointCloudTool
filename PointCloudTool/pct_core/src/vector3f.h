#pragma once

#include "common.h"

namespace pct
{
	namespace core
	{
		class PCT_DLL Vector3f
		{
		public:
			float x, y, z;
			Vector3f();
			Vector3f(float _x, float _y, float _z);
			Vector3f(const Vector3f& a);
			Vector3f(Vector3f&& a);
			Vector3f& operator=(const Vector3f& a);
			Vector3f& operator=(Vector3f&& a);

			bool operator ==(const Vector3f& a)const;
			bool operator !=(const Vector3f& a)const;
			virtual bool operator<(const Vector3f &a)const;
			virtual bool operator<=(const Vector3f &a)const;
			virtual bool operator>(const Vector3f&a)const;
			virtual bool operator>=(const Vector3f &a)const;
			virtual std::string ToString()const;

			Vector3f operator-()const;
			float operator[](int idx)const;
			Vector3f operator +(const Vector3f &a) const;
			Vector3f operator -(const Vector3f &a) const;
			Vector3f operator *(const float a) const;
			float operator*(const Vector3f &a)const;
			Vector3f operator /(const float a) const;
			Vector3f& operator +=(const Vector3f &a);
			Vector3f& operator -=(const Vector3f &a);
			Vector3f& operator *=(const float a);
			Vector3f& operator /=(const float a);

			bool IsZero()const;
			float SquareLength()const;
			float Length()const;
			void Unitize();
			void ToPolarCoordinate(float& out_theta, float& out_phi, float& out_rho)const;

			static float Angle(const Vector3f& a, const Vector3f& b);
			static Vector3f Cross(const Vector3f& a, const Vector3f&b);
			static Vector3f FromPolarCoordinate(const float theta, const float phi, const float rho = 1.0f);

			bool Equal(const Vector3f& a, const float distanceTolerance = FLT_EPSILON)const;
			bool Parallel(const Vector3f& a, const float degreeTolerance = FLT_EPSILON)const;

			static const Vector3f Zero;
			static const Vector3f UnitX;
			static const Vector3f UnitY;
			static const Vector3f UnitZ;
			static const Vector3f One;
		};
	}
}
