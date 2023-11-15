#include "shell.h"
static void execute_external_command(char *cmd_path, char **argv,
		char *prog_name);
static void handle_builtin_commands(char **argv, char *prog_name);

/**
 * execute_command - Executes a command with arguments
 * @cmd_line: Full command line including command and arguments
 * @prog_name: Name of the program for error messages
 */
void execute_command(char *cmd_line, char *prog_name)
{
	char *argv[MAX_ARGS];
	char *token;
	char *cmd_path;
	int i = 0;

	token = strtok(cmd_line, " ");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;
	handle_builtin_commands(argv, prog_name);
	cmd_path = find_command_in_path(argv[0]);
	if (!cmd_path)
	{
		fprintf(stderr, "%s: %s: command not found\n", prog_name, argv[0]);
		return;
	}
	execute_external_command(cmd_path, argv, prog_name);
	free(cmd_path);
}
/**
 * handle_builtin_commands - Checks and executes built-in commands
 * @argv: Argument vector
 * @prog_name: Program name for error messages
 */
static void handle_builtin_commands(char **argv, char *prog_name)
{
	int j;
	if (strcmp(argv[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(argv[0], "env") == 0)
	{
		for (int j = 0; environ[j] != NULL; j++)
		{
			printf("%s\n", environ[j]);
		}
		exit(EXIT_SUCCESS);
	}
}
/**
 * execute_external_command - Executes an external command
 * @cmd_path: Full path to the command
 * @argv: Argument vector for the command
 * @prog_name: Program name for error messages
 */
static void execute_external_command(char *cmd_path, char **argv,
		char *prog_name)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd_path, argv, environ) == -1)
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
