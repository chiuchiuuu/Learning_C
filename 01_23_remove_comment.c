#include "stdio.h"

void rmcomment(char c);
void incomment();
void inquote(char c);

int main()
{
	char c;
	
	printf("Remove Comments...\n");

	while ((c = getchar()) != EOF)
		rmcomment(c);

	return 0;
}

void rmcomment(char c)
{
	char tmp;
	if (c == '/')
	{
		if ((tmp = getchar()) == '*')
			incomment();
		else if (tmp == '/')
		{
			putchar(c);
			rmcomment(tmp);
		}
		else
		{
			putchar(c);
			putchar(tmp);
		}
	}
	else if (c == '\"' || c == '\'')
	{
		inquote(c);
	}
	else
		putchar(c);
}

void incomment()
{
	char c1 = getchar();
	char c2 = getchar();

	while (c1 != '*' || c2 != '/')
	{
		c1 = c2;
		c2 = getchar();
	}
}

void inquote(char c)
{
	putchar(c);

	char tmp;
	while ((tmp = getchar()) != c)
	{
		putchar(tmp);

		if (tmp == '//') /* escape char */
		{
			putchar(getchar());
		}
	}
	putchar(tmp);
}