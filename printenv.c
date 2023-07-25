#include "umutwe.h"

/**
 * main - Entry point
 * @argc: passed args as counter to the paased command(unused)
 * @argv: passed args as a vector of inputted command
 * @envp: passed arg as a vector of input command
 *
 * Return: 0 at success
 */
int main(__attribute__((unused)) int argc, char *argv[], char *envp[])
{
	char **env = envp;
	size_t storesize = 0;
	ssize_t check_er;
	char *i_line = NULL;

	do {
		printf("$");
		check_er = getline(&i_line, &storesize, stdin);
		if (check_er == -1)
		{
			perror("failed to read inputted line\n");
			break;
		}
		if (i_line[0] == '\n')
		{
			continue;
		}
		if (strcmp(i_line, "exit\n") == 0)
		{
			free(i_line);
			exit(0);
		}
		if (strcmp(i_line, "env\n") == 0)
		{
			while (*env)
			{
				printf("%s\n", *env);
				env++;
			}
		}
		printf("%s: no such file or directory\n", argv[0]);
	} while (1);
	free(i_line);
	return (0);
}
