#include "umutwe.h"

/**
 * print_env - function to print current env variable
 * @env: passed args as a pointer to the env variable to print
 * @argv: passed args as a vector of inputted command
 *
 * Return: 0 at success
 */
int print_env(char **env, __attribute__((unused)) char *argv[])
{
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}
