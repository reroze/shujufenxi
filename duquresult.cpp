#include <stdio.h>
#include<stdlib.h>

void result(int cities_air[363], int cities_air_xiabiao[363])
{
	for (int x = 0; x < 363; x++)
	{
		if (cities_air_xiabiao[x] == 0)
		{
			cities_air[x] = -1;
		}
		if (cities_air_xiabiao[x] != 0)
		{
			FILE *fp = fopen("F:\\bigdata\\result.txt", "r");
			char ch = fgetc(fp);
			int p = 0;
			int zuobiao = 1;
			for (int i = 1; i < cities_air_xiabiao[x]; i++)
			{
				fscanf(fp, "%d", &p);
			}
			fscanf(fp, "%d", &p);
			cities_air[x] = p;
			fclose(fp);
		}
	}
}