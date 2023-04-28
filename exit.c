#include "shell.h"

/**
 * exit_cmd - this exits the shell with exit cmd
 *
 * @argu: pointer to array of chars
 * @buffer: input command
 * @Exit: exit value
 * Return: void
 */
void exit_cmd(char **argu, char *buffer, int Exit)
{
	int exit_cond = 0;

	if (!argu[1])
	{
		free(buffer);
		free(argu);
		exit(Exit);
	}
	exit_cond = atoi(argu[1]);

	free(buffer);
	free(argu);
	exit(exit_cond);
}
