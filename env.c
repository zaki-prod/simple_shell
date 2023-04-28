#include "shell.h"

/**
 * get_env - gets all environment
 *
 * @env: environment
 * Return: void
 */
void get_env(char **env)
{
	unsigned int i = 0, j = 0;

	while (env[i])
	{
		j = _strlen(env[i]);

		write(1, env[i], j);
		write(1, "\n", 1);
		i++;
	}
}
