#include "shell.h"

/**
 * srch_pth - sreachs variable path
 *
 * @env: environment variable
 * Return: value of path
 */
char *srch_pth(char **env)
{
	size_t ind = 0, var = 0, cnt = 0;
	char *pth = NULL;

	for (ind = 0; _strncmp(env[ind], "PATH=", 5); ind++)
	{
		;
	}

	if (env[ind] == NULL)
		return (NULL);
	for (cnt = 5; env[ind][var]; var++, cnt++)
	{
		;
	}
	pth = malloc(sizeof(char) * (cnt + 1));

	if (pth == NULL)
		return (NULL);
	for (var = 5, cnt = 0; env[ind][var]; var++, cnt++)
	{
		pth[cnt] = env[ind][var];
	}
	pth[cnt] = '\0';
	return (pth);
}
