#include "main.h"

/**
 * executeShell - lunch shell command as exercutables
 * @param: command param->args
 * Return: status
 */

int executeShell(data_t *param)
{
	pid_t child_pid;
	int status, (*run)(data_t *);

	run = get_buildInFunc(param->args[0]);
	if (run != 0)
		return (run(param) - 1);
	if (handle_path(param) == 1)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(param->path, param->args, param->_environ) == -1)
			{
				_puts("execve failed");
				return (1);
			}
		}
		else if (child_pid < 0)
		{
			_puts("fork failed");
			return (1);
		}
		else
			waitpid(-1, &status, 0);
	}
	else
	{
		Print_N_err(param);
		return (0);
	}
	return (status);
}

/**
 * Print_N_err - print cmd not found err
 * @param: data param
 * Return: nothing
 */
void Print_N_err(data_t *param)
{
	param->errcount++;	
	_puts(param->av[0]);
	_puts(": ");
	print_number(param->errcount);
	_puts(": ");
	_puts(param->path);
	_puts(": not found");
	_putchar('\n');
}
