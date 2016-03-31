#ifndef __RubixCube__
#define __RubixCube__
#include "extra.h"
#include <cstdlib>

class RubixCube
{
private:
	const unsigned int _dimensions;		//number of dimensions on cube
	const unsigned int _length;			//length of any side of the cube

	unsigned int* _cube;			//flat array containing data about entire cube
	const unsigned int _cubeLength;	//length of cube, allways equivelent to _length ^ _dimensions


	///Untested - Benji O(1)
	///failed test
	//rotates a set of 4 points 
	//d1 and d2 are passed in longer form
	inline void rotatePoint(unsigned int d2, unsigned int d1,
		unsigned int d2Value,
		unsigned int d1Value,
		unsigned int modifiedD2Value,						//length side - 1 - d1Value
		unsigned int strippedPoint,
		unsigned int point)
	{
#define a d1Value
#define b d2Value
#define s strippedPoint
#define c modifiedD2Value
		unsigned int t = _cube[point];

		//test this code
		//first
 		unsigned int n = s + d1Value * d2 + c * d1;
		_cube[point] = _cube[n];

		//second
		point = n;
		b = a;
		a = c;
		c = _length - 1 - b;
		n = s + a * d2 + c * d1;
		_cube[point] = _cube[n];

		//third
		point = n;
		b = a;
		a = c;
		c = _length - 1 - b;
		n = s + a * d2 + c * d1;
		_cube[point] = _cube[n];

		//fourth
		_cube[n] = t;
#undef a
#undef b
#undef s
#undef c
	}


	///Untested - Benji O(log(d))
	//converts dimension to long form
	inline unsigned int convertToLongForm(unsigned int d)
	{
		return extra::math::uintPow(_length, d);
	}

public:
	///Tested - Benji O(length^dimensions)
	///Benji: O(MIN(length^(dimensions - 1) * dimensions), length^dimensions)
	//makes cube with specified paramaters
	//dimensions must be greater then or equal to 3
	//length must be greater then or equal to 1
	RubixCube(unsigned int dimensions, unsigned int length);

	///Untested - Benji O(1)
	~RubixCube();

	///Tested - Benji O(_length ^ (_dimensions - 3)) ?
	//movement function which prefomes a standard movement for a rubix cube
	void movement(
		unsigned int rotationDimension,	//the dimension in which we are removing in order to make a cube of order n-1 to turn
		unsigned int depth,				//the depth for which we are going when we look down the cube
		unsigned int pDimension1,		//the first dimension which we use to define the plane we are turning upon
		unsigned int pDimension2);		//second dimension to use to define plane we are turning upon, switching 1 and 2 results in turn in opposite direction


	///Tested - Benji O(_length ^ _dimensions * movement)
	//mixes up cube sufficently
	void randomize();

	///Not started
	//prints to console in human readable maner
	void print();


	///Not started
	//checks to see if it is solved
	bool solved();


	//trivial accessors
	unsigned int getDimensions();				//returns _dimensions
	unsigned int getLength();					//returns _length
	const unsigned int* getCube();				//returns _cube
	unsigned int getCubeLength();				//returns _cubeLength


	//overloads
#ifdef _OSTREAM_
	friend std::ostream& operator<<(std::ostream& o, const RubixCube& r)
	{
		o << "Cube: " << r._length << " ^ " << r._dimensions << '\n';
		extra::standard::printArray(r._cube, r._cubeLength, o);
		return o;
	}
#endif

};

#endif