#include "RubixCube.h"


RubixCube::RubixCube(unsigned int dimensions, unsigned int length) :
	_dimensions(dimensions),
	_length(length),
	_cubeLength(extra::math::uintPow(length, dimensions))
{
	_cube = new unsigned int[_cubeLength];

	//could potetentially be distributed, although it's rather unessicary

	//dont need to go through inside of cube, will skip over it when able, although this is only done once and as such is irelivant
	for (unsigned int i = 0; i < _cubeLength; i++)
		_cube[i] = i;
}

RubixCube::~RubixCube()
{
	delete[] _cube;
}

void RubixCube::movement(unsigned int rotationDimension, unsigned int depth, unsigned int pDimension1, unsigned int pDimension2)
{
	rotationDimension = convertToLongForm(rotationDimension);
	pDimension1 = convertToLongForm(pDimension1);
	pDimension2 = convertToLongForm(pDimension2);

	//sort dimensions into variables a, b, and c, a < b < c
	unsigned int a, b, c;

	//this is confirmed to work for all combinations
	if (rotationDimension < pDimension1)
	{
		//a = r | p2
		//b = r | p1 | p2
		//c = p1 | p2
		if (pDimension2 > pDimension1)
		{
			//a = r
			//b = p1
			//c = p2
			a = rotationDimension;
			b = pDimension1;
			c = pDimension2;
		}
		else
		{
			//a = r | p2
			//b = r | p2
			//c = p1
			c = pDimension1;
			if (rotationDimension < pDimension2)
			{
				//a = r
				//b = p2
				a = rotationDimension;
				b = pDimension2;
			}
			else
			{
				//a = p2
				//b = r
				a = pDimension2;
				b = rotationDimension;
			}
		}
	}
	else
	{
		//a = p1 | p2
		//b = r | p1 | p2
		//c = r | p2
		if (pDimension2 > rotationDimension)
		{
			//a = p1
			//b = r
			//c = p2
			a = pDimension1;
			b = rotationDimension;
			c = pDimension2;
		}
		else
		{
			//a = p1 | p2
			//b = p1 | p2
			//c = r
			c = rotationDimension;
			if (pDimension1 > pDimension2)
			{
				//a = p2
				//b = p1
				a = pDimension2;
				b = pDimension1;
			}
			else
			{
				//a = p1
				//b = p2
				a = pDimension1;
				b = pDimension2;
			}
		}
	}

	//go through all values holding r, p1, and p2														(loop 1)
	//go through 1/4 values on plane with nested loops p1:[0, _length / 2), p2:[p1, _length - 1 - p2)	(loop 2)
	
	
	{
#define m1 _length
		unsigned int m2 = m1 * _length;
		unsigned int m3 = m2 * _length;

#define A a
		unsigned int B = b / m1;
		unsigned int C = c / m2;

		unsigned int loop1Max = _cubeLength / m3;
		unsigned int loop2Max = _length / 2;
		unsigned int loop3temp = _length - 1;
		
		//----------------------------------//
		//**********************************//
		//CAN PARALLELIZE THESE NESTED LOOPS//
		//**********************************//
		//----------------------------------//
		
		for (unsigned int i = 0; i < loop1Max; i++)
		{
			//i % A + (i - i % A) % B * m + (i - i % B) % C * m^2 + (i - i % C) * m^3

			unsigned int extendedI = i % A;	//gets last segment of number

			//full equation
			extendedI += (i - extendedI) % B * m1 + (i - i % B) % C * m2 + (i - i % C) * m3 + rotationDimension * depth;


			for (unsigned int j = 0; j < loop2Max; j++)
			{
				unsigned int includeJ = extendedI + j * pDimension1;
				unsigned int c = _length - 1 - j;

				unsigned int loop3Max = loop3temp - j;
				for (unsigned int k = j; k < loop3Max; k++)
				{
					rotatePoint(pDimension1, pDimension2, j, k, c, extendedI, includeJ + k * pDimension2);
				}
			}
		}
#undef A
#undef m1
	}
}


void RubixCube::randomize()
{
	unsigned int a, b, c;
	unsigned int A = _dimensions;
	unsigned int B = _dimensions - 1;
	unsigned int C = _dimensions - 2;
	for (unsigned int i = extra::standard::random(2); i < _cubeLength; i++)
	{
		a = extra::standard::random(A);
		b = extra::standard::random(B);
		c = extra::standard::random(C);

		//make sure no two dimensions overlap
		//this segment should be tested by inself
		if (b >= a)
		{
			if (c >= b)
			{
				c += 2;
			}
			else if (c >= a)
			{
				c++;
			}
			b++;
		}
		else if (c >= b)
		{
			if (c >= a - 1)
			{
				c += 2;
			}
			else
			{
				c++;
			}
		}

		movement(a, extra::standard::random(_length), b, c);
	}
}

void RubixCube::print()
{
}

bool RubixCube::solved()
{
	return false;
}

unsigned int RubixCube::getDimensions()
{
	return _dimensions;
}

unsigned int RubixCube::getLength()
{
	return _length;
}

const unsigned int* RubixCube::getCube()
{
	return _cube;
}

unsigned int RubixCube::getCubeLength()
{
	return _cubeLength;
}
