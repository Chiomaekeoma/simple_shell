#include "main.h"
/**
 * _strcmp -  function that compares two strings.
 * @s1: first string
 * @s2: another string
 * Return: result
 */
int _strcmp(char *s1, char *s2)
{
	int i, result;

	result = 0;
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
		{
			result += 0;
		}
		else
		{
			result = s1[i] - s2[i];
			break;
		}
		i++;
	}
	return (result);
}
