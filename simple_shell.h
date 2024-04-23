#ifndef __SIMPLE__SHELL__H__
#define __SIMPLE__SHELL__H__

#define MAX_ARGS 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char **split_string(char *line);
char *get_path(char *input_line);
void free_args(char **strings_array);
void execute_command(char **command_args, int command_number);
char *_getenv(const char *name);

#endif
