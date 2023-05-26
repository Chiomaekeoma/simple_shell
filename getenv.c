#include "main.h"
/**
 * _getenv - implementation of getenv
 * @name: variable name
 * Return: a pointer to the value in the environment,
 * or NULL if there is no match.
 */
char *_getenv(const char *name)
{
	char *env;

	int i = 0, r;

	if (name == NULL || *name == '\0')
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		env = environ[i];
		r = _strncmp((char *)env, (char *)name, _strlen(name));
		if (r == 0)
		{
			env = env + _strlen(name) + 1;
			return (env);
		}
	}
	return (NULL);
}
