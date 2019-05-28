#include <stdio.h>
#include <stdlib.h>
#include "quhuanhang.h"
void getdates(char dates[3056][10])
{
	FILE *fp = fopen("F:\\bigdata\\date.txt", "r");
	for (int i = 0; i < 3056; i++)
	{
		fgets(dates[i], 50, fp);
		quhuanhang(dates[i]);
		puts(dates[i]);
		printf("%dhah\n", i);
	}
	fclose(fp);
}