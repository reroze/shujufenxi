#include <stdio.h>
#include <stdlib.h>
#include "quhuanhang.h"
void getcities(char cities[363][50])
{
	FILE *fp = fopen("F:\\bigdata\\cities.txt", "r");
	for (int i = 0; i < 363; i++)
	{
		fgets(cities[i], 50, fp);
		quhuanhang(cities[i]);
		puts(cities[i]);
		printf("%dhah\n", i);
	}
	fclose(fp);
}