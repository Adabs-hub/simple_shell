#include "main.h"

/**
 * freeArray - free array of strings
 * @array: string array to free
 * Return: nothing
 */

void freeArray(char **array)
{
	int i = 0;

	if (array != NULL)
	{
		while (array[i] != NULL)
		{
			free(array[i++]);
		}
		free(array);
	}

}

/**
 * freeParam - free structure param
 * @param: program data param
 * Return: nothing
 */
void freeParam(data_t *param)
{
	freeArray(param->args);
	freeArray(param->_environ);


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
			_puts("$ ");
		status = getline(&line_str, (size_t *)&buf, stdin);
		if (status == -1)
		{
			param->arg = line_str;
			handle_getlin_err(param);
		}
		if (word_count(line_str) == 0 || line_str == NULL)
		{
			free(line_str);
			line_str = NULL;
			continue;
		}
		else
		{
			param->arg = line_str;
			param->args = split_tok(line_str, " ");
			status = shellExit(param);
			if (status == 1)
			{
				free(line_str);
				break;
			}
			else if (status == 2)
				executeShell(param);
		}
		free(line_str);
		freeArray(param->args);
		line_str = NULL;
		param->args = NULL;
	} while (status + 1);

}

