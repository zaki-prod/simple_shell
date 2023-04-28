#include "shell.h"

/**
 * value_path - seprates pathes in strings
 *
 * @argu: input command
 * @env: environment variable
 * Return: ptr to str
 */
int value_path(char **argu, char **env)
{
	char *token = NULL, *rel_pth = NULL, *abs_pth = NULL;
	size_t val_pth, cmd;
	struct stat stat_buffer;

	if (stat(*argu, &stat_buffer) == 0)
		return (-1);
	rel_pth = srch_pth(env);
	if (!rel_pth)
		return (1);
	token = strtok(rel_pth, ":");
	cmd = _strlen(*argu);
	while (token)
	{
		val_pth = _strlen(token);
		abs_pth = malloc(sizeof(char) * (val_pth + cmd + 2));
		if (!abs_pth)
		{
			free(rel_pth);
			return (-1);
		}
		abs_pth = _strcpy(abs_pth, token);
		_strcat(abs_pth, "/");
		_strcat(abs_pth, *argu);

		if (stat(abs_pth, &stat_buffer) == 0)
		{
			*argu = abs_pth;
			free(rel_pth);
			return (0);
		}
		free(abs_pth);
		token = strtok(NULL, ":");
	}
	free(rel_pth);
	return (-1);
}
