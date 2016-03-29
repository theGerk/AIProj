#include "RubixCube.h"

RubixCube::RubixCube(unsigned int dimensions, unsigned int length) :
	_dimensions(dimensions),
	_length(length),
	_cubeLength(ExtraMath::uintPow(length, dimensions))
{
	_cube = new unsigned int[_cubeLength];
	//dont need to go through inside of cube, will skip over it when able
	for (unsigned int i = 0; i < _cubeLength; i++)
		_cube[i] = i;
}

RubixCube::~RubixCube()
{
	delete[] _cube;
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