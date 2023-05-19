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
	char *buffer = NULL, **cmd;

	size_t n = 0;
	int path = 0, i;
	(void)ac;
	(void)av;
	(void)env;
	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&buffer, &n, stdin) == -1)
		{
			perror("End of file");
			exit(-1);
		}
		cmd = split_command(buffer);
		path = append_path(&cmd[0]);
		printf("%d,%s\n", path, cmd[0]);
		if (path == 1)
			execute_cmd(cmd, buffer);
		else if (path != 1)
			check_builtin(cmd, buffer);
		for (i = 0; cmd[i]; i++)
			free(cmd[i]);
		free(cmd);
	}
	return (0);
}
