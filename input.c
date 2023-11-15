#include "shell.h"

/**
 * read_command - Reads a command from stdin
 * @cmd: Buffer to store the command
 * @prog_name: Name of the program (unused)
 * Return: 1 on success, 0 on EOF, -1 on error
 */
int read_command(char *cmd, char *prog_name)
{
	ssize_t len;
	(void)prog_name;

	len = read(STDIN_FILENO, cmd, MAX_CMD_LEN);
	if (len <= 0)
		return (len);
	if (cmd[len - 1] == '\n')
		cmd[len - 1] = '\0';
	else
		cmd[len] = '\0';
	return (1);
}
/**
 * print_prompt - Prints the shell prompt
 */
void print_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
