#include "shell.h"

/**
 * _strtok - functions as strtok
 * @str: A pointer to a character array that contains the string to be split.
 * @delim: A pointer to a character array that contains the delimiters to use.
 * Return: tokens
 */
char *_strtok(char *str, const char *delim)
{
	static char *current;
	char *token;

	if (str == NULL)
	{
		current = str;
	}
	else
	{
		current = strpbrk(current, delim);
	}

	if (current == NULL)
	{
		return (NULL);
	}

	token = current;
	current = strpbrk(current + 1, delim);

	if (current == NULL)
	{
		current = str + strlen(str);
	}

	*current = '\0';

	return (token);
}

