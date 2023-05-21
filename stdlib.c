#include "main.h"

/**
 * _realloc - reallocate memory
 * @ptr: pointer with data
 * @len: lenght of pointer
 * @new_len: new length of allocated memory
 * Return: nothing
 */

void *_realloc(char *ptr, unsigned int len, unsigned int new_len)
{
	char *buf;
	unsigned int i = 0;
	char *c_ptr;

	if (ptr == NULL)
	{
		buf = malloc(new_len);
		if (buf == NULL)
			return (NULL);

		return (buf);
	}

	if (len == new_len)
		return (ptr);

	if (ptr != NULL && len == 0)
	{
		free(ptr);
		return (NULL);
	}
	else
		c_ptr = ptr;

	buf = malloc(len * sizeof(c_ptr));
	if (buf == NULL)
	{
		free(buf);
		return (NULL);
	}

	while (i < len && i < new_len)
		buf[i++] = *c_ptr++;

	free(ptr);
	return (buf);
}

/**
 * copyPtr - copy pointer to fro mbvuffer
 * @ptr: pointer
 * @ptr_len: pointer len
 * @buf: buffer
 * @buf_len: buffer len
 * Return: nothing
 */

void copyPtr(char **ptr, size_t *ptr_len, char *buf, size_t buf_len)
{
	if (*ptr == NULL || *ptr_len < buf_len)
	{
		if (buf_len > 32)
			*ptr_len = buf_len;
		else
			*ptr_len = 32;
		*ptr = buf;
	}
	else
	{
		_strcpy(*ptr, buf);
		free(buf);
	}
}
