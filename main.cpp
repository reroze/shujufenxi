#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cities.h"
#include "dates.h"
#include "getairshuzu.h"
#include "duquresult.h"
char wenjian[200000000];
void main()
{
	int error = 0;
	char cities[363][50] = { "0" };
	int cities_air_xiabiao[363] = { 0 };
	int cities_air[363] = { 0 };
	char dates[3056][10] = { "0" };
	getdates(dates);
	printf("pause");
	getchar();
	getcities(cities);
	FILE *fp1 = fopen("D:\\bigdata\\Weather.txt", "r");
	char ch = 'a';
	int r = 0;
	while ((ch = fgetc(fp1)) != EOF)
	{
		wenjian[r] = ch;
		r++;

	}
	printf("all is %d", r);
	wenjian[r] = '\0';
	fclose(fp1);
	int count = 0;
	for (int datetime = 100; datetime < 200; datetime++)
	{
		FILE*fp = fopen("D:\\bigdata\\fenxi1.txt", "a+");
		getairshuzu(dates[datetime], cities_air_xiabiao, cities, wenjian);
		printf("\n\n\n\n\n\n\n\n\n\n");
		for (int i = 0; i < 363; i++)
		{
			printf(" |%d| ", cities_air_xiabiao[i]);
			if (i % 60 == 0 && i != 0)
				printf("\n");
		}
		result(cities_air, cities_air_xiabiao);
		fputc('*', fp);
		fputc('\n', fp);
		fprintf(fp, "%s", dates[datetime]);
		fputc('\n', fp);
		for (int i = 0; i < 363; i++)
		{
			
			if (cities_air[i] != -1)
				fprintf(fp, " |%d| ", cities_air[i]);
			if (cities_air[i] == -1)
			{
				fputc(' ', fp);
				fputc('|', fp);
				fputc(' ', fp);
				fputc(' ', fp);
				fputc('|', fp);
				fputc(' ', fp);
				error++;
			}
			if (i % 20 == 0 && i != 0)
				fputc('\n', fp);
			
		}
		fputc('\n', fp);
		fputc('*', fp);
		fputc('\n', fp);
		fclose(fp);
		printf("\nsuccessfully finish %d of 3065\n", count);
		count++;
	}
	printf("\n\n\n\nthe error is %d", error);
	system("pause");
}