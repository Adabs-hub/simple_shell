#include "main.h"

/**
 * isInt - check is string is an int
 * @str: string arg
 * Return: 0 if an INT 1 if otherwise
 */
int isInt(char *str)
{
	int str_len = _strlen(str), j = 0;

	if (str == NULL)
		return (1);
	while (j < str_len)
	{
		if (str[j] > 47 && str[j] < 58)
			j++;
		else
			return (0);
	}

	return (1);
}

/**
 * cmp_chars - compare strings
 * @str: input string.
 * @delim: delimiter.
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}


/**
 * _reallocdp - infor
 * @ptr: ptr
 * @size: ptr lenngth
 * @new_len: new length
 * Return: char array
 */

char **_reallocdp(char **ptr, unsigned int size, unsigned int new_len)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_len));

	if (new_len == size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_len);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		newptr[i] = ptr[i];

	free(ptr);

	return (newptr);
}

