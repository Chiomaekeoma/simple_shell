#include "shell.h"

/**
 * chddk_mllo - checks for mode of file
 * @argc: arguements count
 * Return: mode
 */
int chddk_mllo(int argc)
{
	struct stat stdin_stat;

	fstat(STDIN_FILENO, &stdin_stat);
	if (isatty(STDIN_FILENO) && argc == 1)
		return (INTERACTIVE);
	if ((!isatty(STDIN_FILENO) && argc == 1))
		return (NON_INTERACTIVE_PIPED);
	if ((argc >= 1))
		return (NON_INTERACTIVE_FILE);

	return (ERROR);
}

/**
 * is_etyy - function
 * @line: line
 * @line_vector: line vector
 * @current: current
 * @program_name: program name
 * @counter: counter
 * @status: the status
 * @env: environment
 * @lines: lines
 * Return: void
 */

void is_etyy(char *line, char **line_vector, list_pa *current,
		char *program_name, int counter, int *status, list_pa *env, char **lines)
{
	int n;

	if (_strlllp(line_vector[0], "exit") == 0)
	{
		if (line_vector[1] == NULL)
		{
			free_all(lines, counter, env, current, line, line_vector);
			exit(*status);
		}
		else if (line_vector[1] != NULL)
		{
			if (_srren(line_vector[1]) <= 9)
			{
				n = _aorr(line_vector[1]);
				if (n != -1)
				{
					free_all(lines, counter, env, current, line, line_vector);
					exit(n);
				}
				else
				{
					*status = EXIT_ERROR;
					priwt_ewwr(program_name, counter, line_vector[1], EXIT_ERROR);
				}
			}
			else
			{
				*status = EXIT_ERROR;
				priwt_ewwr(program_name, counter, line_vector[1], EXIT_ERROR);
			}
		}
	}
}
/**
 * _aorr - converts s to integer
 * @s: string
 * Return: the integer
 *
 */
int _aorr(char *s)
{
	unsigned int n, z;
	char positive;

	z = 0;
	n = 0;
	while (s[z] != '\0')
	{
		if (!((s[z] >= '0') && (s[z] <= '9')))
		{
			return (-1);
		}
		if (((s[z] >= '0') && (s[z] <= '9')))
		{
			n = (n * 10) + (s[z] - '0');
		}
		else if (s[z] == '+')
			positive++;

		z++;
	}

	return (n);
}

/**
 * execute_command - function that executes command
 * @path: path of command
 * @av: array of command
 * @env: environment
 * @status: the status
 * Return: void
 */

void execute_command(char *path, char **av, char **env, int *status)
{
	pid_t pid;

	pid = fork();
	if (pid == ERROR)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(path, av, env) == -1)
			exit(126);
	}
	else if (pid > 0)
	{

		waitpid(pid, status, WUNTRACED);
		*status  = WEXITSTATUS(*status);
	}
}

/**
 * free_vector - frees the allocated memory
 * @argv: allocated array
 * Return: void
 */

void free_vector(char **argv)
{
	char **curr;

	if (argv == NULL)
		return;

	curr = argv;
	while (*curr != NULL)
	{
		free(*curr);
		curr++;
	}

	free(argv);
}
