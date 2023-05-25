#include "main.h"

/**
 * shellExit - exit shell
 * @param: passed application data
 * Return: 1
 */

int shellExit(data_t *param)
{
	int err;

	if (_strcmp(param->args[0], "exit") == 0)
	{
		/*check if int*/
		if (param->args[1] != NULL)
		{
			if (isInt(param->args[1]))
			{
				err = _atoi(param->args[1]);
				free(param->arg);
				freeParam(param);
				exit(err);
				return (1);
			}
			else
			{
				param->errcount++;
				_puts_err(param->av[0]);
				_puts_err(": ");
				print_number(param->errcount);
				_puts_err(": ");
				_puts_err(param->args[0]);
				_puts_err(": Illigal number: ");
				_puts_err(param->args[1]);
				_puts_err("\n");
				return (0);

			}
		}
		else
		{
			free(param->arg);
			freeParam(param);
			exit(0);
			return (1);
		}
	}
	return (2);
}

/**
 * rmComment - remove comment from file command
 * @str: getline string
 * Return: char * of removed string
 */
char *rmComment(char *str)
{
	int i, up_to;

	up_to = 0;
	for (i = 0; str[i]; i++)
	{
		if (str[i] == '#')
		{
			if (i == 0)
			{
				free(str);
				return (NULL);
			}

			if (str[i - 1] == ' ' || str[i - 1] == '\t' || str[i - 1] == ';')
				up_to = i;
		}
	}

	if (up_to != 0)
	{
		str = _realloc(str, i, up_to + 1);
		str[up_to] = '\0';
	}

	return (str);
}
