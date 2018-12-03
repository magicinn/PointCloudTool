#pragma once

#ifdef _PCTAPI
#define PCT_DLL __declspec (dllexport)
#else
#define PCT_DLL __declspec (dllimport)
#endif

#include<iostream>
#include<math.h>
#include<time.h>
#include <string>

#pragma warning (disable:4275)
#pragma warning (disable:4996)

namespace pct
{
	const float PI =(float)3.141592653589793238462643383279502884197169399375105820974944592308;
	float RadiansToDegrees(const float radians) { return radians*(180.f / (PI)); }
	float DegreesToRadians(const float degrees) { return degrees*(PI / 180.0f); }
}