/* Let us write a Version of squeeze(s1,s2) that deletes each character in the string 1 that matches any character in 
    the string s2 */

#include "stdio.h"
#define MAXLINE 1000

int mgetline(char s[], int maxline);
void squeeze(char s1[], char s2[]);

int main()
{
    char s1[MAXLINE];
    char s2[MAXLINE];

    mgetline(s1, MAXLINE);
    mgetline(s2, MAXLINE);

    printf("s1: %s", s1);
    printf("s2: %s", s2);

    squeeze(s1, s2);

    printf("%s\n", s1);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int in = 0;
    int k = 0;
    for (int i = 0; s1[i] != '\0'; i++)
    {
        for (int j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
                in = 1;
        }
        if (!in)
            s1[k++] = s1[i];
        in = 0;
    }
    s1[k] = '\0';
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
