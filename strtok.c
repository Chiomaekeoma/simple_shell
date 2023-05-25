#include "main.h"
/**
 * _strtok - function extract tokens from strings
 * @str: string to be splitted
 * @delim: aray of delimeters
 * Return: a pointer to the next token, or NULL if there are no more tokens.
 */
char *_strtok(char *str, const char *delim)
{
	static char *buffer, *p;

	int i = 0, j = 0, adjacent_delimeters;

	if (str)
		buffer = str;
	if (buffer == NULL)
		return (NULL);
	while (*buffer)
	{
		adjacent_delimeters = 0;
		for (i = 0; delim[i]; i++)
		{
			if (*buffer == delim[i])
			{
				buffer++;
				adjacent_delimeters++;
			}
		}
		if (!adjacent_delimeters)
			break;
	}
	p = buffer;
	for (i = 0; p[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (p[i] == delim[j])
			{
				p[i] = '\0';
				buffer = buffer + i + 1;
				return (p);
			}
		}
	}
	buffer = NULL;
	p[i] = '\0';
	if (*p == '\0')
		return (NULL);
	return (p);
}
