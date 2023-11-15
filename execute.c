#include "shell.h"

/**
 * execute_command - Executes a command
 * @cmd: Command to execute
 * @prog_name: Name of the program
 * execute_command - Executes a command with arguments
 * @cmd_line: Full command line including command and arguments
 * @prog_name: Name of the program for error messages
 */
void execute_command(char *cmd, char *prog_name)
void execute_command(char *cmd_line, char *prog_name)
{
	pid_t pid;
	char *argv[2];
	int status;
	char *argv[MAX_CMD_LEN];
	char *token;
	int status, i = 0;

	argv[0] = cmd;
	argv[1] = NULL;
	token = strtok(cmd_line, " ");
	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;
	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd, argv, NULL) == -1)
		if (execve(argv[0], argv, NULL) == -1)
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
