#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum { no, start, con, end };
void copy(char*a, char s);
int qingxi(char *wen, char *s, char lei, int *xia_biao)
{
	int state = 0;
	int conw = 1;
	char str[50] = "0";
	int r = 0;
	while (wen[*xia_biao] != '\0' && conw == 1)
	{

		if (wen[*xia_biao] == lei)
		{
			*xia_biao = (*xia_biao) + 1;
			state = start;
		}
		if (wen[*xia_biao] == '\n' && state == start)
			state = end;
		switch (state)
		{
		case no:
			break;
		case start:
			copy(str, wen[*xia_biao]);
			break;
		case end:
			copy(str, '\0');
			conw = 0;
			break;
		}
		*xia_biao = (*xia_biao) + 1;

	}

	if (wen[*xia_biao] == '\0')
	{
		if (state = start)
		{
			copy(str, '\0');
			strcpy(s, str);
		}
		//copy(str, '\0');
		return 0;
	}

	strcpy(s, str);
	return 1;
}

void copy(char*a, char s)
{
	static int i = 0;
	*(a + i) = s;
	i++;
	if (s == '\0')
		i = 0;
}

