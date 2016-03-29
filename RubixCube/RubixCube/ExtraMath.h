#ifndef __ExtraMath__
#define __ExtraMath__

namespace ExtraMath
{
	///Tested - Benji, does not throw errors
	///Benji: O(log(exponent))
	//optimized power function, takes in 2 positive integers and allways returns an integer
	unsigned int uintPow(unsigned int base, unsigned int exponent);


	///Not started
	//gets the n'th digit in any base
	inline unsigned int getDigitInBase(unsigned int number, unsigned int base, unsigned int digit);
}

#endif