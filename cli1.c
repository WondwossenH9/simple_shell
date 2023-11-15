#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_CMD_LEN 1024
#define PROMPT "$ "

int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
void read_command(char *cmd);
void execute_command(char *cmd);

/**
 * _putchar - writes char to stdout
 * @c: char to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - prints a string to stdout
 * @str: String to be printed
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
/**
 * _strlen - returns length of a string
 * @s: string to evaluate
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}
/**
 * read_command - reads a command from stdin
 * @cmd: Buffer to store the read command
 */
void read_command(char *cmd)
{
	int len = read(STDIN_FILENO, cmd, MAX_CMD_LEN);

	if (len == 0)
	{
		_putchar('\n');
		exit(0);
	}
	else if (len < 0)
	{
		perror("read");
		exit(1);
	}
	cmd[len - 1] = '\0'; /* Remove newline character from command */
}
/**
 * execute_command - executes the given command
 * @cmd: Command to execute
 */
void execute_command(char *cmd)
{
	char *argv[2];
	pid_t pid;

	if (_strlen(cmd) == 0)
		return;
	argv[0] = cmd;
	argv[1] = NULL;
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		if (execve(cmd, argv, NULL) == -1)
		{
			perror(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
}
/**
 * main - Entry point for the simple shell
 * Return: Always 0 (Success)
 */
int main(void)
{
	char cmd[MAX_CMD_LEN];

	while (1)
	{
		_puts(PROMPT);
		read_command(cmd);
		execute_command(cmd);
	}
	return (0);
}
