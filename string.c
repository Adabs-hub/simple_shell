#include "main.h"

/**
 * _strlen - find string length
 * @str: string pointer
 * Return: length of string
 */

size_t _strlen(char *str)
{
	size_t size = 0;

	if (str != NULL)
		while (str[size] != '\0')
			size++;

	return (size);
}

/**
 * _strcmp - compares two strings
 *
 * @s1: 1st arg - destination string
 *
 * @s2: 2nd arg - source string
 *
 * Return: -15 if s1 is less, 0 if same and 15 is s1 is greaater s2
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, result = 0, len, s1_len = 0, s2_len = 0;

	s1_len = _strlen(s1);
	s2_len = _strlen(s2);
	if (s1_len <= s2_len)
		len = s1_len;
	else
		len = s2_len;
	while (i <= len)
	{
		result = s1[i] - s2[i];
		if (result != 0)
			return (result);
		i++;
	}
	return (result);
}

/**
 * _strcpy - copy string
 *
 * @dest: destination string arg
 *
 * @src: source string arg
 *
 * Return: destination string
 */


char *_strcpy(char *dest, char *src)
{
	size_t j = 0;

	while (src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';

	return (dest);
}

/**
 * split_tok - splite string in array of words
 * @str: char  string
 * @delim: delimiter to separate words
 * Return: array of words
 */

char **split_tok(char *str, const char *delim)
{
	size_t i = 0, wc = 0, offset = 0, j = 0, k = 0;
	char **array = NULL;

	if (str == NULL)
		return (NULL);
	wc = word_count(str);
	array = malloc((wc + 2) * sizeof(*array));
	if (array == NULL)
	{
		free(array);
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; )
	{
		if ((str[i] == *delim || str[i] == '\t')
				&& i == offset && str[i + 1] != '\n')
		{
			i++, offset++;
				continue;
		}
		if (str[i] == *delim || str[i] == '\t' || str[i + 1] == '\0')
		{
			if (offset == i && str[i + 1] == '\n')
				break;
			array[j] = malloc((i - offset + 2) * sizeof(char));
			if (array[j] == NULL)
				return (NULL);
			k = 0;
			while (offset != i && (str[offset] != *delim || str[offset] != '\t'))
				array[j][k++] = str[offset++];
			array[j][k] = '\0';
			offset++, j++;
			if (str[offset] == '\n')
				break;
		}
		i++;
	}
	array[j] = NULL;
	return (array);
}
