#include "main.h"

/**
 * get_buildInFunc - get select build in function
 * @arg: commands to run  (char)
 * Return: pointer to function pointer
 */

int (*get_buildInFunc(char *arg))(data_t *)
{
	buildIn_f func_arr[] = {
	{"cd", runCdFunc},
	{"help", helpCommand},
	{"^D", hdlCtrlCommand},
	{"env", printEnv},
	{"setenv", setEnv},
	{"unsetenv", unsetEnv},
	{NULL, NULL},
	};
	int i = 0;

	while (i < 6)
	{
		if ((_strcmp(func_arr[i].arg, arg) == 0))
			return (func_arr[i].f);
		i++;
	}
	return (0);
}
