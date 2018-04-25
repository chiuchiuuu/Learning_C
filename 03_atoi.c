#include "stdio.h"
#include "ctype.h"

/* atoi: convert s to integer */
int atoi(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)  /* skip white space */
        continue;
    sign = s[i] == '-' ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')  /* skip sign */
        i++;
    
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + s[i] - '0';

    return n * sign;    
}

int main()
{
    char s[] = "-123";
    printf("%d\n", atoi(s));
    return 0;
}

