#include "vector3f.h"
#include "exception.h"

pct::core::Vector3f::Vector3f()
{
	x = 0; y = 0; z = 0;
}

pct::core::Vector3f::Vector3f(float _x, float _y, float _z)
{
	x = _x; y = _y; z = _z;
}

pct::core::Vector3f::Vector3f(const Vector3f& a)
{
	x = a.x; y = a.y; z = a.z;
}

pct::core::Vector3f::Vector3f(Vector3f&& a)
{
	x = a.x; y = a.y; z = a.z;
}

pct::core::Vector3f & pct::core::Vector3f::operator=(const Vector3f & a)
{
	x = a.x; y = a.y; z = a.z;
	return *this;
}

pct::core::Vector3f& pct::core::Vector3f::operator=(Vector3f&& a)
{
	x = a.x; y = a.y; z = a.z;
	return *this;
}

bool pct::core::Vector3f::operator ==(const Vector3f& a)const
{
	return x == a.x&&y == a.y&&z == a.z;
}
bool pct::core::Vector3f::operator !=(const Vector3f& a)const
{
	return x != a.x&&y != a.y&&z != a.z;
}
bool pct::core::Vector3f::operator<(const Vector3f &a)const
{
	if (x > a.x)
		return false;
	else if (x < a.x)
		return true;
	if (y > a.y)
		return false;
	else if (y < a.y)
		return true;
	if (z > a.z)
		return false;
	else if (z < a.z)
		return true;
}
bool pct::core::Vector3f::operator<=(const Vector3f &a)const
{
	if (x > a.x)
		return false;
	else if (x < a.x)
		return true;
	if (y > a.y)
		return false;
	else if (y < a.y)
		return true;
	if (z > a.z)
		return false;
	else
		return true;
}
bool pct::core::Vector3f::operator>(const Vector3f&a)const
{
	if (x < a.x)
		return false;
	else if (x > a.x)
		return true;
	if (y < a.y)
		return false;
	else if (y > a.y)
		return true;
	if (z < a.z)
		return false;
	else if (z > a.z)
		return true;
}
bool pct::core::Vector3f::operator>=(const Vector3f &a)const
{
	if (x < a.x)
		return false;
	else if (x > a.x)
		return true;
	if (y < a.y)
		return false;
	else if (y > a.y)
		return true;
	if (z < a.z)
		return false;
	else
		return true;
}

std::string pct::core::Vector3f::ToString() const
{
	char buff[128];
	sprintf(buff,"(%f,%f,%f)", x, y, z);
	return buff;
}

pct::core::Vector3f pct::core::Vector3f::operator -()const
{
	return Vector3f(-x, -y, -z);
}
float pct::core::Vector3f::operator[](int idx)const
{
	if (idx == 0) return x;
	if (idx == 1) return y;
	if (idx == 2) return z;
	throw IndexOutofRange();
}
pct::core::Vector3f pct::core::Vector3f::operator +(const Vector3f &a) const
{
	return Vector3f(x + a.x, y + a.y, z + a.z);
}
pct::core::Vector3f pct::core::Vector3f::operator -(const Vector3f &a) const
{
	return Vector3f(x - a.x, y - a.y, z - a.z);
}
pct::core::Vector3f pct::core::Vector3f::operator *(const float a) const
{
	return Vector3f(a*x, a*y, a*z);
}
float pct::core::Vector3f::operator*(const Vector3f &a)const
{
	return x*a.x + y*a.y + z*a.z;
}
pct::core::Vector3f pct::core::Vector3f::operator /(const float a) const
{
	if (a == 0.0)
		throw DivideByZeroException();
	return Vector3f(x / a, y / a, z / a);
}
pct::core::Vector3f& pct::core::Vector3f::operator +=(const Vector3f &a)
{
	x += a.x; y += a.y; z += a.z;
	return *this;
}
pct::core::Vector3f& pct::core::Vector3f::operator -=(const Vector3f &a)
{
	x -= a.x; y -= a.y; z -= a.z;
	return *this;
}
pct::core::Vector3f& pct::core::Vector3f::operator *=(const float a)
{
	x *= a; y *= a; z *= a;
	return *this;
}
pct::core::Vector3f& pct::core::Vector3f::operator /=(const float a)
{
	if (a == 0.0)
		throw DivideByZeroException();
	x /= a; y /= a; z /= a;
	return *this;
}

bool pct::core::Vector3f::IsZero()const
{
	return x == 0 && y == 0 && z == 0;
}
float pct::core::Vector3f::SquareLength()const
{
	return x*x + y*y + z*z;
}
float pct::core::Vector3f::Length()const
{
	return std::sqrt(SquareLength());
}
void pct::core::Vector3f::Unitize()
{
	float length = Length();
	x /= length; y /= length; z /= length;
}
void pct::core::Vector3f::ToPolarCoordinate(float& out_theta, float& out_phi, float& out_rho)const
{
	out_rho = Length();
	if (out_rho == 0)
		throw Exception("The length of vector is 0");
	float pxyLength = sqrt(x*x + y*y);
	if (pxyLength == 0)
	{
		out_theta = 0;
		if (z == 0)
			out_phi = 0;
		else
			out_phi = z > 0 ? 90.0f : -90.0f;
	}
	else
	{
		float cosTheta = x / pxyLength;

		if (y > 0)
			out_theta = 360.0f - RadiansToDegrees(acos(cosTheta));
		else
			out_theta = RadiansToDegrees(acos(cosTheta));

		float tanPhi = z / pxyLength;
		out_phi = RadiansToDegrees(atan(tanPhi));
	}
}

float pct::core::Vector3f::Angle(const Vector3f & a, const Vector3f & b)
{
	float alen = a.Length();
	float blen = b.Length();
	if (alen == 0 || blen == 0)
		return 0;
	float dot = a*b;
	float cosa = dot / alen / blen;
	if (cosa > 1.0f)
		cosa = 1.0f;
	if (cosa < -1.0f)
		cosa = -1.0f;
	float rad = acos(cosa);
	return RadiansToDegrees(rad);
}

pct::core::Vector3f pct::core::Vector3f::Cross(const Vector3f & a, const Vector3f & b)
{
	return Vector3f(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

pct::core::Vector3f pct::core::Vector3f::FromPolarCoordinate(const float theta, const float phi, const float rho)
{
	float nx, ny, nz;
	if (rho == 0)
		nx = ny = nz = 0;
	else
	{
		if (phi == 90.0f || phi == -90.0f)
		{
			nx = ny = 0;
			nz = phi < 0 ? -rho : rho;
		}
		else
		{
			nx = cos(DegreesToRadians(theta))*cos(DegreesToRadians(phi))*rho;
			ny = -sin(DegreesToRadians(theta))*cos(DegreesToRadians(phi))*rho;
			nz = sin(DegreesToRadians(phi))*rho;
		}
	}
	return Vector3f(nx, ny, nz);
}

bool pct::core::Vector3f::Equal(const Vector3f & a, const float distanceTolerance) const
{
	Vector3f dv = a - *this;
	float sd = dv.SquareLength();
	return sd <= distanceTolerance*distanceTolerance;
}

bool pct::core::Vector3f::Parallel(const Vector3f & a, const float degreeTolerance) const
{
	float agl = Angle(*this, a);
	return agl<degreeTolerance || agl>180.0f - degreeTolerance;
}

const pct::core::Vector3f pct::core::Vector3f::Zero(0, 0, 0);
const pct::core::Vector3f pct::core::Vector3f::UnitX(1.0f, 0, 0);
const pct::core::Vector3f pct::core::Vector3f::UnitY(0, 1.0f, 0);
const pct::core::Vector3f pct::core::Vector3f::UnitZ(0, 0, 1.0f);
const pct::core::Vector3f pct::core::Vector3f::One(1.0f, 1.0f, 1.0f);





