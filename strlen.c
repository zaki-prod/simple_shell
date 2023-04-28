#include "shell.h"

/**
 * _strlen - A function that returns the length of a string
 * @s: input string
 * Return: length
 */
int _strlen(char *s)
{
	int count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
