#include "main.h"


/**
 * _putchar_err - writes the character c to stdout
 * @c: character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar_err(char c)
{
	return (write(2, &c, 1));
}
