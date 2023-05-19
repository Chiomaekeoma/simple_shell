#include "main.h"
/**
 * check_builtin - deal with builtin commands
 * @cmd: array of command arguments
 * @buffer: Allocated block for line of commands from user
 * Return: corresponding return value of each command
 */
int check_builtin(char **cmd, char *buffer)
{
	int r = 0, i;

	if (_strcmp(cmd[0], "setenv") == 0)
		r = _setenv(cmd[1], cmd[2], 1);
	else if (_strcmp(cmd[0], "unsetenv") == 0)
		r = _unsetenv(cmd[1]);
	else if (_strcmp(cmd[0], "exit") == 0)
	{
		r = exit_func(cmd);
		for (i = 0; cmd[i]; i++)
			free(cmd[i]);
		free(cmd);
		free(buffer);
		exit(r);
	}
	return (r);
}
/**
 * exit_func - converts a string exit status to an integer
 * @cmd: array ofcommand arguments
 * Return: the int converted from the string
 */
int exit_func(char **cmd)
{
	char *s = cmd[1];

	unsigned int sign = 0, number = 0, i = 0;

	if (!s)
		return (-1);
	for (i = 0; s[i]; i++)
	{
		if ((s[i] < 48 || s[i] > 57) && s[i] != 45)
			return (-1);
		else if (s[i] == 45)
			sign++;
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			number = number * 10 + (s[i] - '0');
	}
	if (sign)
		number = -number;
	return (number);
}
/**
 * execute_cmd - a function that executes command
 * @cmd: array ofcommand arguments
 * Return: nothing
 */
void execute_cmd(char **cmd, char *buffer)
{
	pid_t pd;
	(void)buffer;

	pd = fork();
	if (pd == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror("unable to execute the command");
			exit(-1);
		}
	}
	else
	{
		wait(NULL);
	}
}
