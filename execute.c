#include "shell.h"

/**
 * execute_command - Executes a command with arguments
 * @cmd_line: Full command line including command and arguments
 * @prog_name: Name of the program for error messages
 */
void execute_command(char *cmd_line, char *prog_name)
{
	pid_t pid;
	char *argv[MAX_ARGS];
	char *token;
	int status, i = 0;
	char *cmd_path;

	token = strtok(cmd_line, " ");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;
	if (strcmp(argv[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	cmd_path = find_command_in_path(argv[0]);
	if (!cmd_path)
	{
		fprintf(stderr, "%s: %s: command not found\n", prog_name, argv[0]);
		return;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd_path, argv, NULL) == -1)
		{
			perror(prog_name);
			free(cmd_path);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
		free(cmd_path);
	}
	else
		perror(prog_name);
}
