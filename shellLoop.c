#include "main.h"

/**
 * freeArray - free array of strings
 * @array: string array to free
 * Return: nothing
 */

void freeArray(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i++]);
	}
	free(array);
}


/**
 * _atoi - convert char to int
 *
 * @s: char value
 *
 * Return: converted int
 */

int _atoi(char *s)
{
	unsigned int result = 0;
	int i = 0;
	int n = 0;
	int min = 1;

	while (s[i])
	{
		if (s[i] == 45)
			min *= -1;
		while (s[i] >= 48 && s[i] <= 57)
		{
			n = 1;
			result = (result * 10) + (s[i] - '0');
			i++;
		}
		if (n == 1)
			break;
		i++;
	}
	result *= min;
	return (result);
}


/**
 * shellLoop - simple shell loop
 * @param: command arguments array
 * Return: nothing
 */

void shellLoop(data_t *param)
{
	char *line_str = NULL;
	ssize_t buf = 32, status = 0;

	do {
		if (interactive(param))
			_puts("shell$ ");
		status = _getline(stdin, &line_str, buf);
		if (status == -1)
		{
			if (interactive(param))
				_putchar('\n');
			break;
		}
		else if (status == 1 /*|| line_str[0] == '\n' || line_str[0] == '\t'*/)
		{
			free(line_str);
			line_str = NULL;
			continue;
		}
		else
		{
			/*line_str = rmComment(line_str);*/
			param->args = split_tok(line_str, " ");

			status = shellExit(param);
			if (status == 1)
			break;

			else if (status == 2)
				executeShell(param);
		}

		free(line_str);
		freeArray(param->args);
		param->args = NULL;
		line_str = NULL;
		/*_putchar('\n');*/
	} while (status + 1);

}

