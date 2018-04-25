/*
Write a Program detab,which replaces tabs in the input with a proper
number of blanks to spaces

for example:
hello	world	is	great
hello####world###is######great ('#' for visualization)
*/

#include <stdio.h>
#define TABSTOP 8

int main()
{
	int c; // input
	int nb = 0; // number of blanks
	int pos = 0; // current position

	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			nb = TABSTOP - pos % TABSTOP;
			for (; nb > 0; nb--)
				/* putchar('#'); for testing */
				putchar(' ');
			pos = 0;
		}
		else if (c == '\n')
		{
			putchar(c);
			pos = 0;
		}
		else
		{
			putchar(c);
			pos++;
		}
	}
	return 0;
}