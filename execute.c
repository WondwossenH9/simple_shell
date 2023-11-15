#include "shell.h"

/**
 * execute_command - executes commands
 * @cmd: the command to be executed
 * @program_name: name of program for error messages
 */
void execute_command(char *cmd, char *program_name)
{
	char *argv[2];
	pid_t pid;
	int status;

	if (_strlen(cmd) == 0)
		return;
	argv[0] = cmd;
	argv[1] = NULL;
	pid = fork();
	if (pid == -1)
	{
		perror(program_name);
		return;
	}
	if (pid == 0)
	{
		if (execve(cmd, argv, NULL) == -1)
		{
			perror(program_name);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
