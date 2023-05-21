#include "main.h"

/**
 * runCdFunc - changes current directory
 * @param: arguments and eviron command
 * Return: 1 on success
 */

int runCdFunc(data_t *param)
{
	char *directory;
	int check_home, check_home2, is_working_dir;

	directory = param->args[1];
	if (directory != NULL)
	{
		check_home = _strcmp("$HOME", directory);
		check_home2 = _strcmp("~", directory);
		is_working_dir = _strcmp("--", directory);
	}

	if (directory == NULL || !check_home || !check_home2 || !is_working_dir)
	{
		cd_to_home(param);
		return (1);
	}

	if (_strcmp("-", directory) == 0)
	{
		cd_previous(param);
		return (1);
	}

	if (_strcmp(".", directory) == 0 || _strcmp("..", directory) == 0)
	{
		cd_dot(param);
		return (1);
	}

	cd_to(param);

	return (1);
}

