#include "umutwe.h"

/**
 * main - Entry point
 * @argc: passed args as a count to the command passed
 * @argv: passed args as a command line argument
 *
 * Return: 0 at success
 */
int main(__attribute__((unused)) int argc, char *argv[])
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
		if (strcmp(i_line, "/bin/ls\n") == 0)
		{
			system("ls");
			continue;
		}
		if (strcmp(i_line, "ls -l /tmp\n") == 0)
		{
			system("ls -l /tmp");
			continue;
		}
		if (i_line[0] == '\n')
		{
			continue;
		}
		if (strcmp(i_line, "exit\n") == 0)
		{
			free(i_line);
			exit(1);
		}
		i_line[strcspn(i_line, "\n")] = '\0';
		execute_command(i_line, &argv[0]);
		free(i_line);
		i_line = NULL;
	} while (1);
	free(i_line);
	return (0);
}
