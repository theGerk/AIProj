#pragma once
namespace testingStuff
{
#ifdef __ExtraMath__
	namespace ExtraMath_t
	{
		bool uintPow()
		{
			return 
				(ExtraMath::uintPow(2, 2) == 4) &&
				(ExtraMath::uintPow(10, 3) == 1000) &&
				(ExtraMath::uintPow(2, 7) == 1 << 7) &&
				(ExtraMath::uintPow(2, 23) == 1 << 23) &&
				(ExtraMath::uintPow(432, 3) == 432 * 432 * 432);
		}
	}
#endif

	bool testAll()
	{
		return
#ifdef __ExtraMath__
			ExtraMath_t::uintPow() &&
#endif
			true;
	}
}