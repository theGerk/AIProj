#include "extra.h"

namespace extra
{
	namespace math
	{
		unsigned int uintPow(unsigned int base, unsigned int exponent)
		{
			unsigned int output = 1;

			for (unsigned int i = 1; i <= exponent; i <<= 1)
			{
				if (i & exponent)
					output *= base;
				base *= base;
			}

			return output;
		}
	}

	namespace standard
	{

	}
}