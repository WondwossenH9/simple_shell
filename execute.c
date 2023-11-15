#include "shell.h"

/**
 * execute_command - Executes a command
 * @cmd: Command to execute
 * @prog_name: Name of the program
 */
void execute_command(char *cmd, char *prog_name)
{
	pid_t pid;
	char *argv[2];
	int status;

	argv[0] = cmd;
	argv[1] = NULL;
	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd, argv, NULL) == -1)
		{
			perror(prog_name);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	else
	{
		perror(prog_name);
	}
}
