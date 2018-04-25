#include "stdio.h"

#define MAXLINE 80

int htoi(char s[]);
int mgetline(char s[], int maxline);

int main()
{
    char string[MAXLINE];
    mgetline(string, MAXLINE);
    printf("%d\n", htoi(string));
    return 0;
}

int htoi(char s[])
{
    int inhex = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        inhex = 1;
    
    int n = 0; 
    int res = 0;
    for (int i = 2; inhex == 1; i++)
    {
        int tmp;
        if (s[i] >= '0' && s[i] <= '9')
            tmp = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            tmp = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            tmp = s[i] - 'A' + 10;
        else
            inhex = 0;

        if (inhex)
            n = 16 * n + tmp;
    }
    return n;
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
