#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#define MAX_CMD_LEN 1024

/* Function prototypes */
void execute_command(char *cmd, char *prog_name);
ssize_t read_command(char *buffer, size_t size);
void print_prompt(void);

#endif /* SHELL_H */
