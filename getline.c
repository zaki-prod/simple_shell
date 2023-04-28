#include "shell.h"
/**
 * _getline - read from stream
 * @lineptr: adrress of lineptr
 * @n: size
 * @stream: file stream
 * Return: number of characters
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t r_count = 1, r_total_count = 0;
	char *buf, *mov_buf, *end_buf;

	if (!lineptr || !n || !stream)
		return (-1);
	if (*lineptr == NULL && *n == 0)
	{
		*n = NUMBER;
		buf = malloc(*n);
		if (buf == NULL)
			return (-1);
		*lineptr = buf;
	}
	else
		buf = *lineptr;
	mov_buf = buf;
	end_buf = buf + *n;
	while (r_count != 0)
	{
		r_count = read(STDIN_FILENO, mov_buf, 1);
		if (r_count == -1)
			return (-1);
		r_total_count += r_count;
		if (*mov_buf == '\n')
			break;
		if (mov_buf == end_buf)
		{
			buf = realloc(buf, (*n * 2));
			if (buf == NULL)
				return (-1);
			*lineptr = buf;
			end_buf = buf + (*n * 2);
			*n = *n * 2;
		}
		mov_buf++;
	}
	*(++mov_buf) = '\0';
	*lineptr = buf;
	return (r_total_count);
}
