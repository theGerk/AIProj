#pragma once
namespace testingStuff
{
#ifdef __extra__
	namespace extra_T
	{
		namespace math_T
		{
			bool uintPow()
			{
				return
					(extra::math::uintPow(2, 2) == 4) &&
					(extra::math::uintPow(10, 3) == 1000) &&
					(extra::math::uintPow(2, 7) == 1 << 7) &&
					(extra::math::uintPow(2, 23) == 1 << 23) &&
					(extra::math::uintPow(432, 3) == 432 * 432 * 432);
			}
		}
		namespace standard_T
		{
			bool random()
			{
				size_t i, j;
				for (i = 0; i < RAND_MAX; i += i % 61)
				{
					for (j = 0; j < i; j++)
						if (extra::standard::random(i) >= i)
							break;
					if (j < i)
						break;
				}
				return i < RAND_MAX;
			}
		}
	}
#endif

	bool testAll()
	{
		return
#ifdef __extra__
			extra_T::math_T::uintPow() &&
			extra_T::standard_T::random() &&
#endif
			true;
	}
}