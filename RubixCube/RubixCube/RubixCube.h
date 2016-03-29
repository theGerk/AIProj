#pragma once
#include "ExtraMath.h"
class RubixCube
{
private:
	const unsigned int _dimensions;		//number of dimensions on cube
	const unsigned int _length;			//length of any side of the cube

	unsigned int* _cube;			//flat array containing data about entire cube
	const unsigned int _cubeLength;	//length of cube, allways equivelent to _length ^ _dimensions

public:
	///Untested - Benji O(length^dimensions)
	///Benji: O(length^(dimensions - 1) * dimensions)
	//makes cube with specified paramaters
	//dimensions must be greater then or equal to 3
	//length must be greater then or equal to 1
	RubixCube(unsigned int dimensions, unsigned int length);

	///Untested - Benji O(1)
	~RubixCube();

	///Not started
	//movement function which prefomes a standard movement for a rubix cube
	void movement(
		unsigned int rotationDimension,	//the dimension in which we are removing in order to make a cube of order n-1 to turn
		unsigned int depth,				//the depth for which we are going when we look down the cube
		unsigned int pDimension1,		//the first dimension which we use to define the plane we are turning upon
		unsigned int pDimension2);		//second dimension to use to define plane we are turning upon, switching 1 and 2 results in turn in opposite direction


	//trivial accessors
	unsigned int getDimensions();				//returns _dimensions
	unsigned int getLength();					//returns _length
	const unsigned int* getCube();				//returns _cube
	unsigned int getCubeLength();				//returns _cubeLength

};