#include "main.h"

/**
 * exit_frm_wait - check child pit exit code
 * @status: status code for wait
 * @param: data parameter
 * Return: nothing
 */

void exit_frm_wait(int status, data_t *param)
{
	if (WEXITSTATUS(status) == 2)
	{
		free(param->arg);
		freeParam(param);
		exit(2);
	}
}

/**
 * handle_getlin_err - handle -1 returned fro getline
 * @param: data parameter
 * Return: nothing
 */
void handle_getlin_err(data_t *param)
{
	if (interactive(param))
		_putchar_err('\n');
	free(param->arg);
	freeParam(param);
	exit(0);
}

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
				if (err < 0)
				{
					free(param->arg);
					freeParam(param);
					exit(2);
				}
				free(param->arg);
				freeParam(param);
				exit(err);
			}
			else
			{
				exit_code_err(param);
				return (0);
			}
		}
		else
		{
			free(param->arg);
			return (1);
		}
	}
	return (0);
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
