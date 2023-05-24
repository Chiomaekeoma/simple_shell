#include "main.h"
/**
 * equal_char - checks if name contains equal character
 * @name: variablename
 * Return: 1 if yes. 0 if no char
 */
int equal_char(const char *name)
{
	int i = 0;

	for (i = 0; name[i]; i++)
	{
		if (name[i] == '=')
			return (1);
	}
	return (0);
}
/**
 * _setenv - function that changes or adds an environment variable
 * @name: name of variable
 * @value: value of the variable
 * @overwrite: if name exists, overwite its value if overwrite is 1.
 * If overwrite is 0, the value is not changed.
 * Return: 0 on success, or -1 on error.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	static char **env, *new_var;

	int i = 0, vars = 0;

	if (name == NULL || name[0] == '\0' || equal_char(name) == 1 ||
			value == NULL)
	{
		perror("Invalid inputs from user");
		return (-1);
	}
	if (getenv(name) != NULL && overwrite == 0)
		return (0);
	_unsetenv(name);
	while (environ[vars])
		vars++;
	new_var = malloc(_strlen(name) + _strlen(value) + 2);
	env = malloc(sizeof(char *) * vars + 2);
	for (i = 0; i < vars; i++)
	{
		env[i] = malloc(_strlen(environ[i]) + 1);
		if (new_var == NULL || env[i] == NULL || new_var == NULL)
		{
			perror("Failed to allocate memory block!");
			return (-1);
		}
		_strcpy(env[i], environ[i]);
	}
	_strcpy(new_var, (char *)name);
	_strcat(new_var, "=");
	_strcat(new_var, (char *)value);
	env[i] = malloc(_strlen(new_var) + 1);
	_strcpy(env[i], new_var);
	env[i + 1] = NULL;
	environ = env;
	for (i = 0; env[i]; i++)
		free(env[i]);
	free(env);
	free(new_var);
	return (0);
}
