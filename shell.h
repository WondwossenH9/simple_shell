#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 64

void execute_command(char *cmd_line, char *prog_name);
int read_command(char *cmd, char *prog_name);
void print_prompt(void);
int _strlen(char *s);
char *find_command_in_path(char *cmd);

#endif
