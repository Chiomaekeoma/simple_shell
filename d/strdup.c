#include "main.h"
/**
 * _strdup - function that returns a pointer to a newly allocated space in
 * memory, which contains a copy of the string given as a parameter
 * @str: string to be duplicated
 * Return: pointer to duplicate
 */
char *_strdup(char *str)
{
	int org_size;

	static char *dup;

	char *dup_offset;

	if (str == NULL)
		return (NULL);
	org_size = 0;
	while (str[org_size])
	{
		org_size++;
	}
	dup = (char *)malloc(sizeof(char) * (org_size + 1));
	if (dup == NULL)
		return ((char *)NULL);
	dup_offset = dup;
	while (*str)
	{
		*dup_offset = *str;
		dup_offset++;
		str++;
	}
	*dup_offset = '\0';
	return (dup);
}
