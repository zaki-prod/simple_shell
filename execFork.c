#include "shell.h"

/**
 * exec_fork - create fork and executes
 * @argu: commands and paths
 * @av: that has the name of the prg
 * @env: environment variable
 * @buffer:input command
 * @id: id process
 * @k: add new tes to check
 * Return: 0 on success
 */
int exec_fork(char **argu, char **av, char **env, char *buffer, int id, int k)
{
	pid_t ch;
	int status;
	char *fmt = "%s: %d: %s: not found\n";

	ch = fork();
	if (ch == 0)
	{
		if (execve(argu[0], argu, env) == (-1))
		{
			fprintf(stderr, fmt, av[0], id, argu[0]);
			if (!k)
				free(argu[0]);
			free(argu);
			free(buffer);
			exit(errno);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (WEXITSTATUS(status));
	}
	return (0);
}
