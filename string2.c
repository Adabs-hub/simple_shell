#include "main.h"

/**
 * _puts - print string
 * @str: takes string
 * Desc: print strings to stdout
 * Return: nothing
 */

int _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}


/**
 * _putchar - writes the character c to stdout
 * @c: character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strstr - search string for any set of byte
 *
 * @haystack: source string
 *
 * @needle: prefix substring
 *
 * Return: pointer to the byte in haystack that
 * matches one of the bytes in needle
 */

char *_strstr(char *haystack, char *needle)
{
	unsigned int i = 0, j = 0;
	char *first_byte = 0;

	if (needle[0] == '\0')
		return (haystack);
	while (haystack[i] != '\0')
	{
		while (needle[j] == haystack[i + j])
		{
			if (first_byte == 0)
				first_byte = &haystack[i];
			if (needle[j + 1] == '\0')
				return (first_byte);
			j++;
		}
		first_byte = 0;
		i++;
		j = 0;

	}
	return (0);
}


/**
 * _strcat - concatenates two strings
 *
 * @dest: 1st arg - destination string
 *
 * @src: 2nd arg - source string
 *
 * Return: destination string
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, dest_sz = 0, src_sz = 0;

	dest_sz = _strlen(dest);
	src_sz = _strlen(src);
	while (i < src_sz)
	{
		dest[dest_sz] = src[i];
		i++;
		dest_sz++;
	}
	dest[dest_sz] = '\0';
	return (dest);
}
