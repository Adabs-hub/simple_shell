#include "main.h"

/**
 * printEnv - prints build in environmental variable
 * @param: input commant
 * Return: 1 on success
 */

int printEnv(data_t *param)
{
	size_t j = 0;

	if (param->args == NULL || param->_environ == NULL)
	{
		return (0);
	}

	while (param->_environ[j] != NULL)
	{
		_puts(param->_environ[j]);
		_putchar('\n');
		j++;
	}

	return (1);
}


/**
 * findEnv - get an environment variable
 * @name: name of the environment variable
 * @_environ: environment variable
 * Return: value of the environment variable if is found.
 */
char *findEnv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	ptr_env = NULL;
	mov = 0;

	for (i = 0; _environ[i]; i++)
	{
		/* If name and env are equal */
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * cmp_env_name - compares env variables names
 * with the name passed.
 * @env: name of the environment variable
 * @name: name passed
 * Return: 0 if are not equal. Another value if they are.
 */
int cmp_env_name(const char *env, const char *name)
{
	int i;

	for (i = 0; env[i] != '='; i++)
	{
		if (env[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * set_env - set eviron
 * @name: name
 * @value: value to asssign
 * @param: args and evirons
 * Return: nothin
 */

void set_env(char *name, char *value, data_t *param)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; param->_environ[i]; i++)
	{
		var_env = _strdup(param->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(param->_environ[i]);
			param->_environ[i] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	param->_environ = _reallocdp(param->_environ, i, sizeof(char *) * (i + 2));
	param->_environ[i] = copy_info(name, value);
	param->_environ[i + 1] = NULL;
}
