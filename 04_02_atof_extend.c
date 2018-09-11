#include "stdio.h"
#include "ctype.h"
#include "math.h" /* for pow(base, exp) */
#include "01_00_mgetline.c"

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

    /* handle exponential part */
    int esign, exp = 0;
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    esign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    while (isdigit(s[i]))
        exp = exp*10 + s[i++] - '0';

    
	return sign * (val / power) * pow(10, esign * exp);
}

int main()
{
	char str[MAXLINE];
    mgetline(str, MAXLINE);

    double num = atof(str);
    printf("%.10f\n", num);
	
	return 0;
}

