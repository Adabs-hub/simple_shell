#include "main.h"

/**
 * get_buildInFunc - get select build in function
 * @param: commands to run  (char)
 * Return: pointer to function pointer
 */

int (*get_buildInFunc(data_t *param))(data_t *)
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
		if ((_strcmp(func_arr[i].arg, param->args[0]) == 0))
		{
			param->errcount++;
			return (func_arr[i].f);
		}
		i++;
	}
	return (0);
}
