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
	ssize_t read_len;
	(void)argc;

	while (1)
	{
		print_prompt();
		read_len = read_command(cmd, MAX_CMD_LEN);
		if (read_len == 0)
			break;
		if (read_len > 1)
			execute_command(cmd, argv[0]);
	}
	return (0);
}
