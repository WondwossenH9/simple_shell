#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_CMD_LEN 1024
void execute_command(char *cmd, char *prog_name);
int read_command(char *cmd, char *prog_name);
void print_prompt(void);
int _strlen(char *s);

#endif
