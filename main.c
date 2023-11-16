#include "shell.h"

/**
 * main - Entry point for the shell
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Status code
 */
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	signal(SIGINT, handle_signal);
	shell_loop();
	return (EXIT_SUCCESS);
}
/**
 * shell_loop - Main loop to read and execute commands
 */
void shell_loop(void)
{
	char *cmd;
	int status = 1;

	do {
		printf("$ ");
		fflush(stdout);
		cmd = read_command();
		if (cmd == NULL)
		{
			printf("\n");
			break;
		}
		execute_command(cmd);
		free(cmd);
	} while (status);
}
/**
 * read_command - Reads a command from standard input
 * Return: A pointer to the read command
 */
char *read_command(void)
{
	char *cmd = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&cmd, &len, stdin);
	if (nread == -1)
		return (NULL);
	if (nread > 0 && cmd[nread - 1] == '\n')
		cmd[nread - 1] = '\0';
	return (cmd);
}
/**
 * execute_command - Executes a command
 * @cmd: Command to execute
 */
void execute_command(char *cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		char *argv[] = {cmd, NULL};

		if (execve(cmd, argv, NULL) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Error");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
