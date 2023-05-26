#include "main.h"

/**
 * exit_code_err - exit agg error
 * @param: data param
 * Return: nothing
 */
void exit_code_err(data_t *param)
{
	param->errcount++;
	_puts_err(param->av[0]);
	_puts_err(": ");
	print_number(param->errcount);
	_puts_err(": ");
	_puts_err(param->args[0]);
	_puts_err(": Illegal number: ");
	_puts_err(param->args[1]);
	_puts_err("\n");
	if (!interactive(param))
	{
		free(param->arg);
		freeParam(param);
		exit(2);
	}
}
