#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#define MAX_CMD_LEN 1024
#define PROMPT "$ "
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
 * _strlen - returns the length of a string
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
 * main - Entry point for the simple shell
 * Description: A simple UNIX command line interpreter.
 * Return: Always 0 (Success)
 */
int main(void)
{
	char cmd[MAX_CMD_LEN];
	char *argv[2];
	pid_t pid;
	int len;

	while (1)
	{
		_puts(PROMPT);
		len = read(STDIN_FILENO, cmd, MAX_CMD_LEN);
		if (len == 0)
		{
			_putchar('\n');
			return (0);
		}
		else if (len < 0)
		{
			perror("read");
			continue;
		}
		/*cmd[len - 1] = '\0';  Remove newline character from command */
		if (_strlen(cmd) == 0)
			continue;
		argv[0] = cmd;
		argv[1] = NULL;

		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			continue;
		}
		if (pid == 0)
		{
			if (execve(cmd, argv, NULL) == -1)
			{
				perror(cmd);
				return (-1);
			}
		}
		else
			wait(NULL);
	}
	return (0);
}
