#include "stdio.h"
#include "01_mgetline.c"
#define MAXLENGTH 100

/* expand: expand short hand notation in s1 into string s2. */
void escape(char s1[], char s2[]);

int main()
{
    char s1[MAXLENGTH];
    char s2[MAXLENGTH];
    mgetline(s2, MAXLENGTH);

    return 0;
}

void escape(char s1[], char s2[])
{
    int i = 0, j = 0;

    char c;
    while ((c = s1[i++]) != '\0')
    {
        if (s[i] == '-' && s[i+1] >= c)
        {
            for (; s[i] <= c)
        }
    }
}