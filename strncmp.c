#include "main.h"
/**
 * _strncmp - function that compares only the
 * first (at most) n bytes of s1 and s2.
 * @s1: first string
 * @s2: second string
 * @n: number of bytes or characters to compare
 * Return: 0, if the s1 and s2 are equal;
 * a negative value if s1 is less than s2;
 * a positive value if s1 is greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	int diff = 0;

	size_t i = 0;

	if (s1 == NULL || *s1 == '\0' || s2 == NULL || *s2 == '\0' || n == 0)
		return (-1);
	for (i = 0; i < n; i++)
	{
		if (s1[1] != s2[i])
		{
			diff = s1[i] - s2[i];
			return (diff);
		}
	}
	return (0);
}
