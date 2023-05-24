#include "main.h"

/**
 * copy_info - copies info to create a new env or alias
 * @name: name of env or alias
 * @value: value of env or alias
 * Return: pointer to new env or alias.
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * interactive - returns true if shell is interactive mode
 * @param: application data
 *Return: if interactive mode 1 else 0
 */
int interactive(data_t *param)
{
	return (isatty(STDIN_FILENO) && param->readfd <= 2);
}

