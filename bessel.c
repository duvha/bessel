#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
	int x;

	for (x=0; x<10; x++) {
		printf("%d, %f\n", x, jn(x, 1));
	}
}
