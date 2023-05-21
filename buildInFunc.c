#include "main.h"


/**
 * cdCommand - change directory command - builtin
 * @param: environ and args data.  args[0] = "cd".  args[1] =  directory.
 * Return: 1 on success
 */
int cdCommand(data_t *param)
{
	if (param->args[0] == NULL)
	{
		_puts_err(param->av[0]);
		_puts_err(": expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(param->args[1]) != 0)
			_puts("shell$ ");
	}
	return (1);
}


/**
 * helpCommand - prints help to shell
 * @param: environ and args param
 * Return: returns 1 on success.
 */
int helpCommand(data_t *param)
{
	(void)param;
	_puts("Authors /n Adabogo Emmanuel and Igiku Esther \n");
	_puts("Sorry we didn't have enough time to write a documentation\n");

	_puts("cd \nhelp\nexit\nenv\n^D\n");
	return (1);
}



/**
 * hdlCtrlCommand - to handle "^D" key press
 * @param: eviron and args data
 * Return: returns 1.
 */
int hdlCtrlCommand(data_t *param)
{
	free(param->args);
	return (1);
}
