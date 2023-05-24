#include "main.h"
/**
 * main - Entry point
 * Return: 0 on success
 */
int main(void)
{
	char *buffer = NULL, **cmd, *prompt = "#cisfun$ ";

	size_t n = 0;

	int path = 0, i, r;

	while (1)
	{
		if (write(1, prompt, _strlen(prompt)) == -1)
		{
			perror("Failed to display prompt!!");
			exit(-1);
		}
		fflush(stdout);
		if (chioli_gtln(&buffer, &n, stdin) == -1)
			exit(-1);
		cmd = split_command(buffer);
		if (cmd == NULL)
			exit(1);
		path = append_path(&cmd[0]);
		if (path == 1)
			execute_cmd(cmd, buffer);
		else if (path != 1)
			r = check_builtin(cmd, buffer);
		for (i = 0; cmd[i]; i++)
			free(cmd[i]);
		free(cmd);
		if (r == 0)
		{
			perror("command not found my dear");
			exit(-1);
		}
	}
	return (0);
}
