#include "main.h"

/**
 * getLine - getline fucn
 * @fstream: read file stream
 * @f: file
 * @f_len: file len
 * Return: number char printe
 */

ssize_t _getline(FILE *fstream, char **f, size_t f_len)
{
	static ssize_t i;
	char c = 'c', *buffer = malloc(f_len);
	ssize_t getnum;
	int count;

	if (buffer == NULL)
		return (-1);
	if (i == 0)
		fflush(fstream);
	else
		return (-1);

	buffer[f_len + 1] = '\0';
	i = 0;
	while (c != '\n')
	{
		count = read(STDIN_FILENO, &c, 1);
		if ((count == 0 && i == 0) || count == -1)
		{
			free(buffer);
			return (-1);
		}
		if (i >= 32)
			buffer = _realloc(buffer, i, i + 1);

		if (c != EOF && c != '\n')
		{
			buffer[i] = c;
			i++;
			continue;
		}
		buffer[i++] = '\n';
		buffer[i] =  '\0';
		copyPtr(f, &f_len, buffer, i);
		getnum = i;
	}
	if (count != 0)
		i = 0;
	return (getnum);

}
