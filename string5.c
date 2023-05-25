#include "main.h"


/**
 * _putchar_err - writes the character c to stdout
 * @c: character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar_err(char c)
{
	return (write(2, &c, 1));
}


/**
 * word_count - count words/tokens in a strings
 * @str: string arg
 * Return: number of words/tokens in the string arg
 */

int word_count(char *str)
{
	int i = 0, wc = 0;

	if (str != NULL)
	{
		if ((str[i] != ' ' || str[i] != '\t') && str[i] != '\n')
			wc++;
		for (i = 0; str[i] != '\n'; i++)
			if ((str[i] == ' ' || str[i] == '\t') && ((str[i + 1] != ' '
							|| str[i + 1] != '\t') && str[i + 1] != '\n'))
				wc++;
	}
	return (wc);
}
