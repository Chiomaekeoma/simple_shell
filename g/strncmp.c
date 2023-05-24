#include "main.h"
/**
 * _strncmp - it only compares the first (at most) n bytes of s1 and s2.
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to compare
 * Return: 0 for match or difference between characters
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	int diff = 0;

	size_t i;

	if (s1 == NULL || s1[0] == '\0' || s2 == NULL || s2[0] == '\0')
		return (-1);
	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			return (diff);
		}
	}
	return (0);
}
