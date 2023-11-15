#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define READ_SIZE 1024

/**
 * _getline - Custom getline function to read a line from stdin
 * @lineptr: Pointer to the buffer containing the line
 * @n: Size of the buffer
 * Return: The number of characters read, including the delimiter,
 *         but not including the null byte, or -1 on failure
 */
ssize_t _getline(char **lineptr, size_t *n)
{
	static char buffer[READ_SIZE];
	static int buffer_size;
	static int position;
	int len = 0;
	char c = '\0';

	if (*lineptr == NULL || *n == 0)
	{
		*n = READ_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while (c != '\n')
	{
		if (position >= buffer_size)
		{
			buffer_size = read(STDIN_FILENO, buffer, READ_SIZE);
			if (buffer_size <= 0)
			{
				if (len > 0)
					break;
				return (-1);
			}
			position = 0;
		}
		c = buffer[position++];
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
