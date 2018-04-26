#include "stdio.h"
#define MAXLINE 1000

/* mgetline: get line into s, return length */
int mgetline(char s[],int max)
{
    char c;
    int i = 0;

    while (i < max - 1 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

