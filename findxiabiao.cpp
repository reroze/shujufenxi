#include <stdio.h>
#include <stdlib.h>
#include "qingxi1.h"
int getxiabiao(char wenjian[200000000], char *date, char *city)
{
	int panduan = 0;
	int weizhi = 0;
	int times = 0;
	int zuobiao = 1;
	int jude1 = 0;
	char str[8][50] = { "0" };
	char s1 = '!';
	char s2 = '@';
	char s3 = '#';
	char s4 = '$';
	char s5 = '%';
	char s6 = '^';
	char s7 = '&';
	char s8 = '*';
	int xia_biao = 0;
	while (1)
	{
		panduan = qingxi(wenjian, str[0], s1, &xia_biao);
		jude1 = 0;
		if (strstr(str[0], city) != NULL)
			jude1 = 1;
		if (panduan == 1)
		{
			panduan = qingxi(wenjian, str[1], s2, &xia_biao);
			if (jude1 == 1 && strstr(str[1], date) != NULL)
			{
				weizhi = zuobiao;
				printf("%d\t", zuobiao);
				jude1 = 0;
				return weizhi;
			}
			panduan = qingxi(wenjian, str[2], s3, &xia_biao);
			panduan = qingxi(wenjian, str[3], s4, &xia_biao);
			panduan = qingxi(wenjian, str[4], s5, &xia_biao);
			panduan = qingxi(wenjian, str[5], s6, &xia_biao);
			panduan = qingxi(wenjian, str[6], s7, &xia_biao);
			panduan = qingxi(wenjian, str[7], s8, &xia_biao);
			times++;
			zuobiao++;
			if (times == 5000)
			{
				printf("*");
				times = 0;
			}
		}

		if (panduan == 0)
			break;
	}
	return 0;
}