#include "extra.h"


unsigned int extra::math::uintPow(unsigned int base, unsigned int exponent)
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

unsigned int extra::standard::random(unsigned int max)
{
	return rand() % max;
}
