#include "shell.h"

/**
 * main - Entry to shell
 *
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	char *readcommand = NULL, **arr_cmd = NULL;
	int pathvalue = 0, Exit = 0, v = 0;
	(void)argc;

	while (1)
	{
		readcommand = read_cmd();
		if (readcommand)
		{
			pathvalue++;
			arr_cmd = parse_cmd(readcommand);
			if (arr_cmd == NULL)
			{
				free(readcommand);
				continue;
			}
			if ((!_strcmp(arr_cmd[0], "exit")) && arr_cmd[1] == NULL)
				exit_cmd(arr_cmd, readcommand, Exit);
			if (!_strcmp(arr_cmd[0], "env"))
				get_env(env);
			else
			{
				v = value_path(&arr_cmd[0], env);
				Exit = exec_fork(arr_cmd, argv, env, readcommand, pathvalue, v);
				if (v == 0)
					free(arr_cmd[0]);
			}
			free(arr_cmd);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			exit(Exit);
		}
		free(readcommand);
	}
	return (Exit);
}
