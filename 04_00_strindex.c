#include "stdio.h"
/*
#include "01_mgetline.c"
*/

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        int k = 0;
        for (int j = i; s[j] != '\0' && t[k] != '\0' && s[j] == t[k]; j++, k++)
            continue;
        if (k > 0 && t[k] == '\0')
            return i;
        
    }
    return -1;
}

/*
char pattern[] = "ould";

int main()
{
    char line[MAXLINE];
    while (mgetline(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0)
            printf("%s", line);
    return 0;
}
*/