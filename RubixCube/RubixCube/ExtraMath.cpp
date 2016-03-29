#include "ExtraMath.h"
namespace ExtraMath
{
	unsigned int uintPow(unsigned int base, unsigned int exponent)
	{
		unsigned int output;
		
		for (unsigned int i = 1; i <= exponent; i <<= 1)
		{
			if (i & exponent)
				output += base;
			base *= base;
		}

		return output;
	}
}