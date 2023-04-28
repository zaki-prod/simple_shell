#include "shell.h"

/**
 * read_cmd - read from input
 *
 * Return: input read or NULL if there is no input
 */
char *read_cmd(void)
{
	char *command = NULL;
	size_t n = 0;
	ssize_t num_read;

	if (isatty(0))
		write(1, "cisfun$ ", 8);

	num_read = _getline(&command, &n, stdin);
	if (num_read == -1)
	{
		free(command);
		return (NULL);
	}

	return (command);
}
