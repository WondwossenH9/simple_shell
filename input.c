#include "shell.h"

/**
 * read_command - reads a command from stdin
 * @cmd: Buffer to store the read command
 * @program_name: name of program for error messages
 * Return: 1 if successful, 0 on end-of-file, -1 on error
 */
int read_command(char *cmd, char *program_name)
{
	int len = read(STDIN_FILENO, cmd, MAX_CMD_LEN - 1);

	if (len == 0)
		return (0);
	else if (len < 0)
	{
		perror(program_name);
		return (-1);
	}
	if (cmd[len - 1] == '\n')
		cmd[len - 1] = '\0';
	else
		cmd[len] = '\0';
	return (1);
}
