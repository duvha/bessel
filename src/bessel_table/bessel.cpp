#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
	for (int x=0; x<10; x++) {
		std::cout << x << ", " << jn(x, 1) << std::endl;
	}
}
