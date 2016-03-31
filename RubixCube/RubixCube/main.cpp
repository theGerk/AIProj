#include <iostream>
#include "RubixCube.h"
#include "extra.h"

int main()
{
	unsigned int m, n;
	do {
		std::cout << "Side length: ";
		std::cin >> m;
	} while (m < 2);
	do {
		std::cout << "Number of dimensions: ";
		std::cin >> n;
	} while (m < 3);
	RubixCube cube(n, m);
	cube.randomize();
	unsigned int r, d, p, q;
	while (true)
	{
		std::cout << cube << '\n';
		std::cout << std::endl;

		do {
			std::cout << "Rotation Dimension: ";
			std::cin >> r;
		} while (r >= n);
		do {
			std::cout << "Depth: ";
			std::cin >> d;
		} while (d >= m);
		do {
			std::cout << "Plane of rotation dimension 1: ";
			std::cin >> p;
		} while (p >= n || p == r);
		do {
			std::cout << "Plane of rotation dimension 2: ";
			std::cin >> q;
		} while (p >= n || q == r || q == p);
		cube.movement(r, d, p, q);
	}

	return 0;
}