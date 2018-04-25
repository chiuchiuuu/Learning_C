/* Write the function any(s1,s2) which returns the first location in the string
 * s1 where any character from the string s2
   occurs, or -1 if s1 contains no characters from s2. ( The standard library
   function strpbrk does the same job but retuns a pointer to the location */

#include "stdio.h"

#define MAXLINE 1000

int mgetline(char s[], int maxline);
int any(char s1[], char s2[]);

int main()
{
    char s1[MAXLINE];
    char s2[MAXLINE];

    mgetline(s1, MAXLINE);
    mgetline(s2, MAXLINE);

    printf("s1: %s", s1);
    printf("s2: %s", s2);

    printf("%d\n", any(s1, s2));

    return 0;
}

int any(char s1[], char s2[])
{
    int i, j;
    for (i = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] != '\n' && s1[i] == s2[j])
                return i;
        }
    }
    return -1;
}

int mgetline(char s[], int maxline)
{
    int c,i;

    for(i=0;i<maxline-1 &&(c=getchar())!=EOF && c!='\n';++i)
        s[i] =c;
    if(c=='\n')
    {
        s[i] =c;
        ++i;
    }
    s[i] = '\0';

    return i;
}
