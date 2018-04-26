#include "stdio.h"
#include "03_reverse.c"

/* itoa: conver integer to string in s */
void itoa(int n, char s[])
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
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char s[3][100];
    itoa(-135, s[0]);
    itoa(124, s[1]);
    itoa(0, s[2]);
    for (int i = 0; i < 4; i++)
        printf("%s\n", s[i]);
    return 0;
}