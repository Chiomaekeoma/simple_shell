#include "main.h"
/**
 * main - Entry point
 * @ac: arguments count
 * @av: array of arguments
 * @env: environment
 * Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL, *token, **cmd;

	size_t n = 0;
	pid_t pd;
	(void)ac;
	(void)av;
	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&buffer, &n, stdin) == -1)
		{
			perror("End of file");
			exit(-1);
		}
		token = strtok(buffer, " \n");
		cmd = malloc(sizeof(char *) * 2);
		cmd[0] = malloc(sizeof(char) * strlen(token) + 1);
		strcpy(cmd[0], token);
		cmd[1] = NULL;
		pd = fork();
		if (pd == 0)
		{
			if (execve(cmd[0], cmd, env) == -1)
			{
				perror("Cannot execute cmd");
				exit(-1);
			}
		}
		else
		{
			wait(NULL);
		}
		free(cmd[0]);
		free(cmd);
		free(buffer);
	}
	return (0);
}
