#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 64

extern char **environ;
void execute_command(char *cmd_line, char *prog_name);
int read_command(char *cmd, char *prog_name);
void print_prompt(void);
int _strlen(char *s);
char *find_command_in_path(char *cmd);

#endif
