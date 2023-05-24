#include "main.h"
#define BUFFER_SIZE 5120
/**
 * chioli_gtln - function that gets a new line
 * @lineptr: string of character
 * @n: size of the buffer
 * @stream: pointer to a given file
 * Return: the number of characters read
 */
ssize_t chioli_gtln(char **lineptr, size_t *n, FILE *stream)
{
	char buffer[BUFFER_SIZE];

	int characters_num, i, len = 0;

	if (*lineptr == NULL)
	{
		*n = 120;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			perror("no memory available");
			return (-1);
		}
	}
	characters_num = read(fileno(stream), buffer, BUFFER_SIZE);
	if (characters_num == -1)
		return (-1);
	while (buffer[len] != '\n')
		len++;
	for (i = 0; i <= len; i++)
	{
		if ((int)(*n) < len + 2)
			*lineptr = realloc(*lineptr, len + 2);
		(*lineptr)[i] = buffer[i];
	}
	(*lineptr)[i] = '\0';
	return (len);
}
