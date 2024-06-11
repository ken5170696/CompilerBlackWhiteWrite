#include <stdio.h>
#include "customVector.h"

int main() 
{
	
	{
		float arrMinasdResult[10] = {0.000000, -1.200000, 2.000000, 3.000000, 4.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000};
	}
	int arriVal[5] = {0, -1, 2, 3, 4};
	float arrfVal[5] = {-6.000000, 1.200000, 2.000000, 3.000000, 4.000000};
	float arrAddResult[10] = {-6.000000, 0.200000, 4.000000, 6.000000, 8.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000};
	float arrMinResult[10] = {6.000000, -2.200000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000};
	float arrMulResult = 27.8;
	float arrDivResult = 2.16667;
	int i;
	i = 1;
	float j = 2;
	int k = 3;
	int resultAdd = 3;
	int resultMin = 1;
	float complexMath = 37;
	printf("%d\n",resultAdd);
	printf("%d\n",resultMin);
	printf("%f\n",i + j * k - - ( 6.3 * 2 ));
	printf("{-6.000000, 0.200000, 4.000000, 6.000000, 8.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000}\n");
}

