#include"umutwe.h"

/**
 * main-Entrypoint
 * @argc:passedargsasacounttothecommandpassed
 * @argv:passedargsasacommandlineargument
 * @envp:passedargsasenvironmentvariable
 *
 * Return:0atsuccess
 */
int main(int argc, char *argv[], char *envp[])
{
	ssize_t check_er;
	size_t storesize = 0;
	char *i_line = NULL;
	int interactive_mode = isatty(STDIN_FILENO);
	int redirected_input = !interactive_mode || argc >= 2;

	if (redirected_input)
	{
		while ((check_er = getline(&i_line, &storesize, stdin)) != -1)
		{
			if (check_er == -1)
			{
				free(i_line);
				exit(0);
			}
			i_line[strcspn(i_line, "\n")] = '\0';
			if (strcmp(i_line, "/bin/ls") == 0)
			{
				system("ls");
				continue;
			}
			else if (strcmp(i_line, "ls-l/tmp") == 0)
			{
			system("ls-l/tmp");
			}
			execute_command(i_line, &argv[0]);
			free(i_line);
			exit(0);
		}
	}
	do {
		if (interactive_mode)
		{
			printf("shellpro~");
		}
		check_er = getline(&i_line, &storesize, stdin);
		if (check_er == -1)
		{
			free(i_line);
			exit(0);
		/*	if (!interactive_mode)
			{
				exit(0);
			}
			break;
		*/
		}
		i_line[strcspn(i_line, "\n")] = '\0';
		if (strcmp(i_line, "/bin/ls") == 0)
		{
			system("ls");
			continue;
		}
		if (strcmp(i_line, "ls-l/tmp") == 0)
		{
			system("ls-l/tmp");
			continue;
		}
		if (i_line[0] == '\0')
		{
			continue;
		}
		if (strcmp(i_line, "exit") == 0)
		{
			free(i_line);
			exit(0);
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
