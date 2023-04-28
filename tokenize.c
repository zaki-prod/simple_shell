#include "shell.h"

/**
 * parse_cmd - parses command
 *
 * @command: commmand string
 * Return: array of commands
 */
char **parse_cmd(char *command)
{
	char **arr_cmd;
	char *token = NULL;
	size_t i = 0;
	int j = 0;

	if (command == NULL)
		return (NULL);

	for (i = 0; command[i]; i++)
	{
		if (command[i] == ' ')
			j++;
	}
	if ((j + 1) == _strlen(command))
		return (NULL);

	arr_cmd = malloc(sizeof(char *) * (j + 2));
	if (arr_cmd == NULL)
		return (NULL);

	i = 0;
	token = strtok(command, " \n\t\r");
	while (token)
	{
		arr_cmd[i] = token;
		token = strtok(NULL, " \n\t\r");
		i++;
	}
	arr_cmd[i] = NULL;
	return (arr_cmd);
}
