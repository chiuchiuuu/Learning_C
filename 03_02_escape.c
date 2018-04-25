#include "stdio.h"
/* 
#include "01_mgetline.c"
#define MAXLENGTH 100
*/

/* escape: convert escape character visible */
void escape(char s[], char t[]);


// int main()
// {
//     char s[2 * MAXLENGTH];
//     char t[MAXLENGTH];
//     mgetline(t, MAXLENGTH);

//     escape(s, t);
//     printf("escape: %s\n", s);
//     return 0;
// }

void escape(char s[], char t[])
{
    int i = 0, j = 0;
    
    while (t[j] != '\0')
    {
        switch (t[j])
        {
        case '\t':
            s[i++] = '\\';
            s[i++] = 't';
            break;
        case '\n':
            s[i++] = '\\';
            s[i++] = 'n';
            break;
        default:
            s[i++] = t[j];
        }
        j++;
    }
    s[i] = '\0';
}