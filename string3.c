#include "main.h"

/**
 * _puts_err - print string
 * @str: takes string
 * Desc: print strings to stdout
 * Return: nothing
 */

int _puts_err(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}

	return (i);
}


/**
 * _strdup - copy and duplicate string
 *
 * @str: string to duplicate
 *
 * Return: NULL on failure and empty string string pointer on success
 */

char *_strdup(char *str)
{
	char *buffer = 0;
	int i = 0, len = 0;

	if (str == 0)
		return (0);
	len = _strlen(str);
	buffer = (char *)malloc(sizeof(char) *	(len + 1));
	if (buffer == 0)
		return (0);
	while (i < len)
	{
		buffer[i] = str[i];
		i++;
	}
	return (buffer);
}


/**
 * rev_string - reverses a string.
 * @s: input string.
 * Return: no return.
 */
void rev_string(char *s)
{
	int count = 0, i, j;
	char *str, temp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}

/**
 * _strtok - splits a string by some delimiter.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str; /*Store first address*/
		i = _strlen(str);
		str_end = &str[i]; /*Store last address*/
	}
	str_start = splitted;
	if (str_start == str_end) /*Reaching the end*/
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/*Breaking loop finding the next token*/
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}
