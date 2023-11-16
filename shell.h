#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 64

void shell_loop(void);
char *read_command(void);
void execute_command(char *cmd);
void print_error(char *cmd);
void handle_signal(int sig);
void *safe_malloc(size_t size);
#endif
