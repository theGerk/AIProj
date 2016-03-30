#ifndef __RubixCube__
#define __RubixCube__
#include "extra.h"
#include <cstdlib>
#include "ArrLen.h"

class RubixCube
{
private:
	const unsigned int _dimensions;		//number of dimensions on cube
	const unsigned int _length;			//length of any side of the cube

	unsigned int* _cube;			//flat array containing data about entire cube
	const unsigned int _cubeLength;	//length of cube, allways equivelent to _length ^ _dimensions


	///Untested - Benji O(1)
	//rotates a set of 4 points 
	//d1 and d2 are passed in longer form
	inline void rotatePoint(unsigned int d1, unsigned int d2, unsigned int point)
	{
		unsigned int t = _cube[point];

		//test this code
		//first
		unsigned int a = point / d1 % _length;
		unsigned int b = point / d2 % _length;
		unsigned int c = _length - 1 - a;
		unsigned int s = point - a * d1 - b * d2;
		unsigned int n = s + a * d2 + c * d1;
		_cube[point] = _cube[n];

		//second
		point = n;
		b = a;
		a = c;
		c = _length - 1 - a;
		n = s + a * d2 + c * d1;
		_cube[point] = _cube[n];

		//third
		point = n;
		b = a;
		a = c;
		c = _length - 1 - a;
		n = s + a * d2 + c * d1;
		_cube[point] = _cube[n];

		//fourth
		_cube[n] = t;
	}


	///Untested - Benji O(log(d))
	//converts dimension to long form
	inline unsigned int convertToLongForm(unsigned int d)
	{
		return extra::math::uintPow(_length, d);
	}

public:
	///Untested - Benji O(length^dimensions)
	///Benji: O(MIN(length^(dimensions - 1) * dimensions), length^dimensions)
	//makes cube with specified paramaters
	//dimensions must be greater then or equal to 3
	//length must be greater then or equal to 1
	RubixCube(unsigned int dimensions, unsigned int length);

	///Untested - Benji O(1)
	~RubixCube();

	///in progress
	//movement function which prefomes a standard movement for a rubix cube
	void movement(
		unsigned int rotationDimension,	//the dimension in which we are removing in order to make a cube of order n-1 to turn
		unsigned int depth,				//the depth for which we are going when we look down the cube
		unsigned int pDimension1,		//the first dimension which we use to define the plane we are turning upon
		unsigned int pDimension2);		//second dimension to use to define plane we are turning upon, switching 1 and 2 results in turn in opposite direction


	///Untested - Benji O(_length ^ _dimensions)
	//mixes up cube sufficently
	void randomize();


	//trivial accessors
	unsigned int getDimensions();				//returns _dimensions
	unsigned int getLength();					//returns _length
	const unsigned int* getCube();				//returns _cube
	unsigned int getCubeLength();				//returns _cubeLength

};

#endif