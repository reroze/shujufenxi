#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "findxiabiao.h"

void getairshuzu(char *date, int cities_air[363], char cities[363][50], char wenjian[200000000])
{

	for (int i = 0; i < 363; i++)
	{
		cities_air[i] = getxiabiao(wenjian, date, cities[i]);
		printf("\n$%d/363n", i);
	}

}