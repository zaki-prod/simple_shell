#include "shell.h"

/**
* _strcpy - A function that copies the string pointed to by src
* including the terminating null byte(\0), to the
* buffer pointed to by dest
* @dest: input
* @src: input
* Return: value the pointer to dest
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;
	int j;

	while (src[i] != '\0')
	{
		i++;
	}
	for (j = 0; j <= i; j++)
	{
		dest[j] = src[j];
	}
	return (dest);
}
