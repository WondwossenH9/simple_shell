#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * _getline - Custom getline function to read a line from stdin
 * @lineptr: Pointer to the buffer containing the line
 * @n: Size of the buffer
 * Return: number of chars read, including the newline, or -1 on failure
 */
ssize_t _getline(char **lineptr, size_t *n)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_pos;
	static int buffer_end;
	int len = 0;
	char c;

	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while (1)
	{
		if (buffer_pos >= buffer_end)
		{
			buffer_end = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (buffer_end <= 0)
				return (-1);
			buffer_pos = 0;
		}
		c = buffer[buffer_pos++];
		if (c == '\n' || c == '\0')
			break;
		if (len >= *n - 1)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
				return (-1);
		}
		(*lineptr)[len++] = c;
	}
	(*lineptr)[len] = '\0';
	return (len);
}
