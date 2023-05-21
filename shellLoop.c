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
 * has_path - checks command path
 * @str: command string
 * Return: string with path
 */
int has_path(data_t *param)
{
	char *tmp = NULL, *str = NULL;
	struct stat st;

	if (_strstr(param->args[0], "/bin/") != NULL)
	{
		return (1);
	}
	else
	{
		tmp = param->args[0];
		str = malloc((_strlen(tmp) + 6) * sizeof(*str));
		if (str == NULL)
		{
			_puts("path assign erro");
			free(str);
			return (0);
		}

		param->args[0] = _strcat(_strcpy(str, "/bin/"), tmp);
		if (param->args[0] == NULL)
			return (0);
		
		if (stat(param->args[0], &st) == 0)
		{
			free(tmp);
			return (1);
		}
		else
		{
			_puts(param->av[0]);
			_puts(": 1: ");
			_puts(tmp);
			_puts(": not found");
			free(param->args[0]);
			param->args[0] = tmp;
			_putchar('\n');
			return (0);
		}

		free(tmp);
	}
	return (1);
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
		_puts("shell$ ");
		status = _getline(stdin, &line_str, buf);
		if (status == -1)
			break;
		if (status == 1)
		{
			free(line_str);
			line_str = NULL;
			continue;
		}
		line_str = rmComment(line_str);
		param->args = split_tok(line_str, " ");
		
		status = shellExit(param);
		if (status == 1)
			break;
		
		else if (status == 2)
			executeShell(param);

		free(line_str);
		freeArray(param->args);
		param->args = NULL;
		line_str = NULL;
		/*_putchar('\n');*/
	} while (status + 1);

}

