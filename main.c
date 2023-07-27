#include "umutwe.h"

/**
 * main - Entry point
 * @argc: passed args as a count to the command passed
 * @argv: passed args as a command line argument
 * @envp: passed args as environment varialbe
 *
 * Return: 0 at success
 */
int main(__attribute__((unused)) int argc, char *argv[], char *envp[])
{
	ssize_t check_er;
	size_t storesize = 0;
	char *i_line = NULL;

	do {
		printf("shellpro~ ");
		check_er = getline(&i_line, &storesize, stdin);
		if (check_er == -1)
		{
			perror("failed to read inputted line\n");
			break;
		}
		i_line[strcspn(i_line, "\n")] = '\0';
		if (strcmp(i_line, "/bin/ls") == 0)
		{
			system("ls");
			continue;
		}
		if (strcmp(i_line, "ls -l /tmp") == 0)
		{
			system("ls -l /tmp");
			continue;
		}
		if (i_line[0] == '\0')
		{
			continue;
		}
		if (strcmp(i_line, "exit") == 0)
		{
			free(i_line);
			exit(1);
		}
		execute_command(i_line, &argv[0]);
		if (strcmp(i_line, "env") == 0)
		{
			print_env(envp, &argv[0]);
		}
		free(i_line);
		i_line = NULL;
	} while (1);
	free(i_line);
	return (0);
}
