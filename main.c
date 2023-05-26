#include "main.h"

/**
 * getSignal - Handle the crtl + c
 * @signal: Signal handler
 */

void getSignal(int __attribute__((unused)) signal)
{
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * setEnviron - set environ
 * @param: new av array
 * @environ: environ
 * Return: nothing
 */

int setEnviron(data_t *param, char **environ)
{
	unsigned int j = 0;

	param->args = NULL;
	param->_environ = NULL;
	param->av = NULL;
	param->arg = NULL;
	param->path = NULL;
	param->env_pathstr = NULL;
	param->lnflag = 0;
	param->lncount = 0;
	param->readfd = 0;
	param->errcount = 0;

	while (environ[j] != NULL)
		j++;

	param->_environ =  malloc(sizeof(char *) * (j + 1));
	if (param->_environ == NULL)
		return (0);

	for (j = 0; environ[j] != NULL; )
	{
		param->_environ[j] = _strdup(environ[j]);
		j++;
	}

	param->_environ[j] = NULL;
	return (1);
}

/**
 * main - entry point
 * @ac: unsed arg
 * @av: command flag array
 * @environ: environmental variables
 * Return: zero on success
 */

int main(int  __attribute__((unused)) ac, char **av, char **environ)
{
	data_t param;

	if (av == NULL || ac > 1)
		return (0);
	signal(SIGINT, getSignal);

	if (!setEnviron(&param, environ))
		return (0);
	param.av = av;

	shellLoop(&param);
	freeParam(&param);

	return (0);
}
