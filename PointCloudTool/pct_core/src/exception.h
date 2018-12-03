#include "common.h"
#include <stdexcept>

namespace pct
{
	namespace core
	{
		class PCT_DLL Exception:public std::runtime_error
		{
		public:
			Exception(char const * in_info) : std::runtime_error(in_info) { }
		};
		class PCT_DLL DivideByZeroException:public Exception
		{
		public:
			DivideByZeroException(char const * in_info = "Attempted to divide a number by zero.") :
				Exception(in_info) {}
		};
		class PCT_DLL IndexOutofRange :public Exception
		{
		public:
			IndexOutofRange(char const * in_info = "The input index is out of range"):
				Exception(in_info){}
		};
	}
}