#include <iostream>
#include "util.h"

int sum(int x, int y)
{
	return x + y;
}

int main(void)
{
	int a = 8;
	auto func = cq::bind(&sum, a, 9);
	a = 10;
	std::cout << func() << std::endl;
}