#include <stdio.h>
#include "customVector.h"

int main() 
{
	float i = 1.5;
	float j = 3.14;
	float k = 2.8;
	printf("%f",i + j * k);
	printf("\n");
	printf("%f",i * ( j + k ));
	printf("\n");
}

