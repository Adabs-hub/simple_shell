#include "main.h"


/**
 * setEnv - set environmental variable
 * @param: data parameter
 * return: i
 */

int setEnv(data_t *param)
{
	if (param->args[1] != NULL && param->args[2] != NULL)
	{
		set_env(param->args[1], param->args[2], param);
		return (1);
	}

	_puts_err(param->av[0]);
	_puts_err(": ");
	_puts_err(param->args[0]);
	_puts_err(": Ivalid variabe or value: usage: setenv VARIABLE VALUE\n");
	return (1);
}


/**
 * unsetEnv - remove environmental variable
 * @param: data parameter
 * return: 1
 */
int unsetEnv(data_t *param)
{

	int i;
	char *var_env, *name_env;

	if (param->args[1] == NULL)
	{
		_puts_err(param->av[0]);
		_puts_err(": ");
		_puts_err(param->args[0]);
		_puts_err(": add variale usage: unsetenv VARIABLE\n");
		return (1);
	}


	for (i = 0; param->_environ[i]; i++)
	{
		var_env = _strdup(param->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, param->args[1]) == 0)
		{
			free(param->_environ[i]);
			while (param->_environ[i] != NULL)
			{
				param->_environ[i] = param->_environ[i + 1];
				i++;
			}
			free(var_env);
			return (1);
		}
		free(var_env);
	}
	_puts_err(param->av[0]);
	_puts_err(": :env variable :");
	_puts_err(param->args[1]);
	_puts_err(": not found\n");
	return (1);
}
