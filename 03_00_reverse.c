#include "stdio.h"
#include "string.h"
#define MAXLENGTH 100

/* reverse: reverse string s in place */
void reverse(char s[])
{
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

/* test main() 
int main()
{
    char s[MAXLENGTH];
    printf("input a string: ");
    scanf("%s", s);

    reverse(s);
    printf("reverse: %s\n", s);
    return 0;
}
*/
