#include "main.h"
/**
 * _unsetenv - a function that deletes the variable name from the environment
 * @name: variable name
 * Return: 0 on success, or -1 on error.
 */
int _unsetenv(const char *name)
{
	char **temp_env;

	int i, status = 0, len = 0, found = 0;

	for (i = 0; name[i]; i++)
	{
		if (name[i] == '=')
			status++;
	}
	if (name == NULL || name[0] == '\0' || status)
	{
		errno = EINVAL;
		return (-1);
	}
	len = _strlen(name);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			found++;
			temp_env = environ;
			for (; temp_env[i]; i++)
				temp_env[i] = environ[i + 1];
			break;
		}
	}
	if (found == 1)
		environ = temp_env;
	return (0);
}
