#include <iostream>
#include "extra.h"
#include "RubixCube.h"

#include "test.h"

int main()
{
	unsigned int p1, p2, r;
	/*
	012
	021
	102
	120
	201
	210
	*/
	r = 2;
	p1 = 0;
	p2 = 1;
	unsigned int a, b, c;
	if (r < p1)
	{
		//a = r | p2
		//b = r | p1 | p2
		//c = p1 | p2
		if (p2 > p1)
		{
			//a = r
			//b = p1
			//c = p2
			a = r;
			b = p1;
			c = p2;
		}
		else
		{
			//a = r | p2
			//b = r | p2
			//c = p1
			c = p1;
			if (r < p2)
			{
				//a = r
				//b = p2
				a = r;
				b = p2;
			}
			else
			{
				//a = p2
				//b = r
				a = p2;
				b = r;
			}
		}
	}
	else
	{
		//a = p1 | p2
		//b = r | p1 | p2
		//c = r | p2
		if (p2 > r)
		{
			//a = p1
			//b = r
			//c = p2
			a = p1;
			b = r;
			c = p2;
		}
		else
		{
			//a = p1 | p2
			//b = p1 | p2
			//c = r
			c = r;
			if (p1 > p2)
			{
				//a = p2
				//b = p1
				a = p2;
				b = p1;
			}
			else
			{
				//a = p1
				//b = p2
				a = p1;
				b = p2;
			}
		}
	}
	std::cout << a << ", " << b << ", " << c << "\n";
	std::cout << testingStuff::testAll();

	return 0;
}