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
	(void)lineptr;
	(void)n;
      if (*lineptr == NULL)
      {
	      *n = 120;
	      *lineptr = malloc(*n);

	      if (*lineptr == NULL)
		      perror("no memory available");
      }
      characters_num = read(fileno(stream), buffer, BUFFER_SIZE);
      for (i = 0; i < characters_num; i++)
      {
      
	      (*lineptr)[i] = buffer[i];
      }
      return (characters_num);


}
int main(void)
{
	char *bufferptr = NULL;
	size_t n = 0;
	printf("$ ");
	fflush(stdout);
	chioli_gtln(&bufferptr, &n, stdin);
	printf("%s %ld\n", bufferptr, strlen(bufferptr));
	free(bufferptr);
	return (0);
}
