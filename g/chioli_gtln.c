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

	int characters_num, i;

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
	for (i = 0; i < characters_num; i++)
	{
		if ((int)(*n) <= characters_num)
			*lineptr = realloc(*lineptr, characters_num + 1);
		(*lineptr)[i] = buffer[i];
	}
	(*lineptr)[i] = '\0';
	return (characters_num);
}
int main(void)
{
	char *bufferptr = NULL;
	size_t n = 0;
	int r;
	printf("$ ");
	fflush(stdout);
	r = chioli_gtln(&bufferptr, &n, stdin);
	printf("%d %s\n", r, bufferptr);
	free(bufferptr);
	return (0);
}
