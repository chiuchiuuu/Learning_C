/* Write a Program entab that replaces strings of blanks by the minimum
number of tabs and blanks to acheive the same spacing.
Use the same tab stops as for detab.
*/
#include<stdio.h>
#define TABSTOP 8

int main(void)
{
	int nb, nt, pos, c;

	nb = 0;
	nt = 0;

	for (pos = 1; (c = getchar()) != EOF; ++pos)
		if (c == ' ')
		{
			if ((pos % TABSTOP) != 0)
				++nb;
			else
			{
				nb = 0;
				++nt;
			}
		}
		else
		{
			while (nt--)
				putchar('\t');
			if (c == '\t')
				nb = 0;
			else
				while (nb--)
					putchar('#');

			putchar(c);

			if (c == '\n')
				pos = 0;
			else if (c == '\t')
				pos = pos + (TABSTOP - (pos - 1) % TABSTOP) - 1;
		}

	return 0;
}
