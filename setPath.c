#include "main.h"

/**
 * handle_path - handle command path by searching env PATH
 * @param: app data info
 * Return: 1 on success
 */
int handle_path(data_t *param)
{
	char *path = NULL;

	param->path = param->args[0];
	if (param->lnflag == 1)
	{
		param->lncount++;
		param->lnflag = 0;
	}

	path = pathSearch(param);

	if (path)
	{
		param->path = path;
		return (1);
	}

	if ((findEnv("PATH=", param->_environ) || param->args[0][0] == '/' ||
			interactive(param)) && isvalidPath(param->args[0]))
		return (1);
	/**else if (*(param->arg) != '\n')
	**	return (0);
	**/

	return (-1);
}

/**
 * isvalidPath - varify executable command
 * @path: path to inspect
 * Return: 1 if exercutable, 0 otherwise
 */
int isvalidPath(char *path)
{
	struct stat st;

	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
		return (1);

	return (0);
}

/**
 * getenvPath - fetch a path from env PATH
 * @envpath: ENV PATH strings
 * @offset: starting index
 * @limit: stopping index
 * Return: pointer to new string
 */
char *getenvPath(char *envpath, int offset, int limit)
{
	static char strbuf[512];
	int start = 0, i = 0;

	for (i = 0, start = offset; start < limit; start++)
		if (envpath[start] != ':')
			strbuf[i++] = envpath[start];
	strbuf[i] = 0;
	return (strbuf);
}

/**
 * pathSearch - finds command in PATH string
 * @param: data structure
 * Return: command full path or NULL
 */
char *pathSearch(data_t *param)
{
	int i = 0, offset = 0;
	char *path, *pathstring = NULL, *command = NULL;

	pathstring = findEnv("PATH=", param->_environ);
	param->env_pathstr = pathstring;
	command = param->args[0];
	if (!pathstring)
		return (NULL);
	if ((_strlen(command) > 2) && _strstr(command, "./"))
	{
		if (isvalidPath(command))
			return (command);
	}
	while (1)
	{
		if (!pathstring[i] || pathstring[i] == ':')
		{
			path = getenvPath(pathstring, offset, i);
			if (!*path)
				_strcat(path, command);
			else
			{
				_strcat(path, "/");
				_strcat(path, command);
			}
			if (isvalidPath(path))
				return (path);
			if (!pathstring[i])
				break;
			offset = i;
		}
		i++;
	}
	return (NULL);
}
