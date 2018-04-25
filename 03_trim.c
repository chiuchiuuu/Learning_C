#include "stdio.h"
#include "string.h"
/* #include "03_02_escape.c" */

/* trim: remove trailing blanks, newlines, tabs */
int trim(char s[])
{
    int i;
    for (i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
            break;
    }
    s[i + 1] = '\0';
    return i;
}

/*
int main()
{
    char s[] = "abc \t \n";
    char t[100];
    escape(t, s);
    printf("%s\n", t);
    trim(s);
    escape(t, s);
    printf("%s\n", t);
    return 0;
}
*/