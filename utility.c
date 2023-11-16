#include "shell.h"

/**
 * print_error - Prints an error message
 * @cmd: Command that caused the error
 */
void print_error(char *cmd)
{
	if (cmd != NULL)
		fprintf(stderr, "%s: command not found\n", cmd);
}
/**
 * handle_signal - Handles the signal
 * @sig: Signal number
 */
void handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 3);
	}
}
