#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: string one
 * @s2: string two
 * Return: compared string
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++)
	{
	}
		return (s1[i] - s2[i]);
}
