#include "stdio.h"
#include "03_reverse.c"

/* itoa_min : convert integer to string with minimum field width */
void itoa(int n, char s[], int minw)
{
    int i = 0, sign;


    if ((sign = n) < 0)
        n = -n;
    
    do
    {
        s[i++] = n % 10 + '0';
    }while (n /= 10);
    if (sign < 0)
        s[i++] = '-';
    while (i < minw)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char s[3][100];
    itoa(-135, s[0], 5);
    itoa(123456, s[1], 5);
    itoa(0, s[2], 5);
    for (int i = 0; i < 4; i++)
        printf("%s\n", s[i]);
    return 0;
}