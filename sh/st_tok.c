#include "shell.h"

/**
 * _saak - tokenize string
 * @str: string
 * @delimiters: delimeter string
 * Return: token
 */
char *_saak(char *str, const char *delimiters)
{
	return (strtok(str, delimiters));
}

/**
 * _craak - checks for character in string
 * @c: character
 * @str: string
 * Return: 1 if found. 0 otherwise
 */
unsigned int _craak(char c, const char *str)
{
	unsigned int z;

	for (z = 0; str[z] != '\0'; z++)
	{
		if (c == str[z])
			return (1);
	}
	return (0);
}

/**
 * free_e_v - Entry point to the shell
 * @line: arguements count
 * @line_vector: arguements values
 */
void free_e_v(char *line, char **line_vector)
{
	free(line);
	free_vector(line_vector);
}

/**
 * is_dar - Entry point to the shell
 * @line: arguements count
 * @argv: arguements count
 * @counter: arguements count
 * @line_vector: arguements count
 * @status: arguements count
 * @old_line: arguements count
 * Return: is dir or not
 */
int is_dar(char *line, char **argv, int counter, char **line_vector,
		int *status, char *old_line)
{
	struct stat st;

	if (stat(line, &st) == 0)
	{
		if (S_ISDIR(st.st_mode))
		{
			priwt_ewwr(argv[0], counter, line_vector[0], PERMISSION_DENIED);
			*status = PERMISSION_DENIED;
			free_e_v(old_line, line_vector);
			return (0);
		}
	}
	return (-1);
}
