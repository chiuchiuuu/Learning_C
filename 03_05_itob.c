#include "stdio.h"
#include "03_reverse.c"

/* itob: convert integer to string base b */
void itob(int n, char s[], int b)
{
    int i = 0, sign;

    if ((sign = n) < 0)
        n = -n;
    
    do
    {
        int digit = n % b;
        s[i++] = digit >= 10 ? digit - 10 + 'a' : digit + '0';
    }while (n /= b);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char s[18][100];
    printf("number from -1 to 16");
    for (int b = 2; b <= 16; b++)
    {
        printf("base %d: ", b);
        for (int i = 0, val = -1; i < 18; i++, val++)
            itob(val, s[i], b);
    
        for (int i = 0; i < 18; i++)
            printf("%s%s", s[i], i == 17 ? "\n" : ", ");
    }
    
    return 0;
}
