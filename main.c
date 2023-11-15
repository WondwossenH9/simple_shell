#include "shell.h"

/**
 * main - Entry point for the simple shell
 * @argc: Argument count (unused)
 * @argv: Argument vector
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	char cmd[MAX_CMD_LEN];
	int status;
	(void)argc;

	while (1)
	{
		print_prompt();
		status = read_command(cmd, argv[0]);
		if (status == 0)
			break;
		if (status == 1)
			execute_command(cmd, argv[0]);
	}
	return (0);
}
