#include "main.h"
/**
 * _getenv - implementation of getenv
 * @name: variable name
 * Return: a pointer to the value in the environment,
 * or NULL if there is no match.
 */
char *_getenv(const char *name)
{
	char *env, *token, *value;

	int i = 0;

	if (name == NULL || *name == '\0')
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		env = environ[i];
		token = _strtok(env, "=");
		if (_strcmp(token, (char *)name) == 0)
		{
			value = _strtok(NULL, "=");
			return (value);
		}
	}
	return (NULL);
}
