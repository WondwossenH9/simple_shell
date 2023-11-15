#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_CMD_LEN 1024

extern char *program_name;
int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
int read_command(char *cmd, char *program_name);
void execute_command(char *cmd, char *program_name);
#endif
