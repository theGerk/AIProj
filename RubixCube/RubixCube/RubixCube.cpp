#include "RubixCube.h"


void RubixCube::rotatePoint(unsigned int d1, unsigned int d2, unsigned int point)
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