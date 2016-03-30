#ifndef __extra__
#define __extra__
#include <cstdlib>

namespace extra
{
	namespace math
	{
		///Tested - Benji, does not throw errors
		///Benji: O(log(exponent))
		//optimized power function, takes in 2 positive integers and allways returns an integer
		unsigned int uintPow(unsigned int base, unsigned int exponent);


		///Not started
		//gets the n'th digit in any base
		inline unsigned int getDigitInBase(unsigned int number, unsigned int base, unsigned int digit);
	}


	namespace standard
	{

		///Tested - Benji
		//currently assumes max <= RAND_MAX, may want to leave this way for speed
		//returns random integer in the range [0, max)
		inline unsigned int random(unsigned int max)
		{
			return rand() % max;
		}
	}

}

#endif