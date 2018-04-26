#include "stdio.h"
#include "ctype.h"
#include "01_mgetline.c"

/* atof: convert string s to double */
double atof(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++)
		continue;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + s[i] - '0';
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + s[i] - '0';
		power *= 10;
	}
	return sign * val / power;
}

int main()
{
	double sum = 0, atof(char []);
	char line[MAXLINE];
	
	while (mgetline(line, MAXLINE))
		printf("\t%g\n", sum += atof(line));
	return 0;
}

