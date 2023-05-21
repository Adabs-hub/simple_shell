#include "main.h"
/**
 * cd_dot - go to parent directory
 * @param: environ and args data
 * Return: no return
 */
void cd_dot(data_t *param)
{
	char pwd[PATH_MAX];
	char *directory, *cp_pwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);
	set_env("OLDPWD", cp_pwd, param);
	directory = param->args[1];
	if (_strcmp(".", directory) == 0)
	{
		set_env("PWD", cp_pwd, param);
		free(cp_pwd);
		return;
	}
	if (_strcmp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	rev_string(cp_strtok_pwd);
	cp_strtok_pwd = _strtok(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = _strtok(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			rev_string(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		set_env("PWD", cp_strtok_pwd, param);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", param);
	}
	free(cp_pwd);
}

/**
 * cd_to - changes to given directory
 * @param: environ and args param
 * Return: no return
 */
void cd_to(data_t *param)
{
	char pwd[PATH_MAX];
	char *directory, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	directory = param->args[1];
	if (chdir(directory) == -1)
	{
		_puts_err("child directory failed");
		_puts_err(param->args[0]);
		return;
	}

	cp_pwd = _strdup(pwd);
	set_env("OLDPWD", cp_pwd, param);

	cp_dir = _strdup(directory);
	set_env("PWD", cp_dir, param);

	free(cp_pwd);
	free(cp_dir);

	/*chdir(directory);*/
}

/**
 * cd_previous - changes to the previous directory
 * @param: args and environs
 * Return: no return
 */
void cd_previous(data_t *param)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);

	p_oldpwd = findEnv("OLDPWD", param->_environ);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = _strdup(p_oldpwd);

	set_env("OLDPWD", cp_pwd, param);

	if (chdir(cp_oldpwd) == -1)
		set_env("PWD", cp_pwd, param);
	else
		set_env("PWD", cp_oldpwd, param);

	p_pwd = findEnv("PWD", param->_environ);

	write(STDOUT_FILENO, p_pwd, _strlen(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	chdir(p_pwd);
}

/**
 * cd_to_home - changes to home directory
 * @param: environ and args parameters
 * Return: nothing
 */
void cd_to_home(data_t *param)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = _strdup(pwd);

	home = findEnv("HOME", param->_environ);

	if (home == NULL)
	{
		set_env("OLDPWD", p_pwd, param);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		_puts_err("child directory failed");
		_puts_err(param->args[0]);

		free(p_pwd);
		return;
	}

	set_env("OLDPWD", p_pwd, param);
	set_env("PWD", home, param);
	free(p_pwd);
}
