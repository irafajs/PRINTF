#include "umutwe.h"

/**
 * execute_command - function to handle  passed argument
 * @command: passed argument as command to execute
 * @argv: passed argument as program name
 *
 * Return : nothing
 */
void execute_command(char *command, char *argv[])
{
	char *path_env, *path_copy, *dir, full_path[1024];
	int result, status;
	char *execarg[] = {NULL, NULL};
	pid_t pid;
	bool command_found;

	path_env = getenv("PATH");
	path_copy = (char *)malloc(strlen(path_env) + 1);
	if (path_copy == NULL)
	{
		perror("memory allocation failed\n");
		exit(1);
	}
	strcpy(path_copy, path_env);
	dir = strtok(path_copy, ":");
	command_found = false;
	while (dir != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		if (access(full_path, X_OK) == 0)
		{
			command_found = true;
			break;
		}
		dir = strtok(NULL, ":");
	}
	if (command_found)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("failed to create child\n");
			exit(1);
		}
		if (!pid)
		{
			execarg[0] = full_path;
			result = execve(full_path, execarg, NULL);
			if (result == -1)
			{
				perror("failed to execute the command\n");
				exit(1);
			}
		}
		wait(&status);
	}
	else
	{
		printf("%s:  1: %s: No such file or directory\n", argv[0], argv[1]);
	}
	free(path_copy);
}
