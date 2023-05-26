#include "main.h"
/**
 * _strlen - function that returns the length of a string.
 * @s: string
 * Return: length of string (Success)
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}
