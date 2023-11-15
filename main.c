#include "shell.h"

/**
 * main - Entry point for the simple shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	char cmd[MAX_CMD_LEN];
	int read_status;

	(void)argc;

	while ((read_status = read_command(cmd, argv[0])) != 0)
	{
		if (read_status == -1)
			continue;
		execute_command(cmd, argv[0]);
	}
	return (0);
}
