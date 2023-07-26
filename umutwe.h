#ifndef UMUTWE_H
#define UMUTWE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>
#include <sys/wait.h>

void execute_command(char *command, char *argv[]);
int print_env(char **env, char *argv[]);

#endif
