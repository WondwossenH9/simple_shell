#include "shell.h"

/**
 * read_command - Reads a command from stdin
 * @buffer: Buffer to store the command
 * @size: Size of the buffer
 * Return: Number of characters read
 */
ssize_t read_command(char *buffer, size_t size)
{
	ssize_t len;

	len = read(STDIN_FILENO, buffer, size - 1);
	if (len > 0)
	{
		if (buffer[len - 1] == '\n')
			buffer[len - 1] = '\0'
		else
			buffer[len] = '\0';
	}
	return (len);
}

/**
 * print_prompt - Prints the shell prompt
 */
void print_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

