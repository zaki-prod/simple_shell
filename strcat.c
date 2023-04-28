#include "shell.h"

/**
 * _strcat - concatenates two strings together
 *
 * @dest: destination parameter
 * @src: source parameter
 * Return: a pointer to the resulting string destination
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
	}
	i++;
	return (dest);
}
