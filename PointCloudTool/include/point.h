#pragma once

#ifdef _WINDLL
#define PCT_DLL __declspec (dllexport)
#else
#define PCT_DLL __declspec (dllimport)
#endif

namespace pct
{
	namespace core
	{

	}
}
