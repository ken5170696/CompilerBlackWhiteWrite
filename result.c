#include <stdio.h>
#include "customVector.h"

void GG() 
{
	printf("\n");
}
int main() 
{
	float vi1[5] = {5.000000, 3.000000, 4.000000, 1.000000, 2.000000};
	float vi2[5] = {2.000000, -2.000000, 4.000000, 0.000000, 0.000000};
	printf("%f",dotArray( vi1 , vi2 , 5 , 5 ));
	printf("\n");
	printArray(addArray( vi1 , vi2 , 5 , 5 ), 5);
	printf("\n");
	GG();
}

