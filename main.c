#include "main.h"
volatile sig_atomic_t flag = 0;
/**
 * handler - a function that handles SIDINT
 * signal usuallly caused by program termination by Ctrl + C.
 * @signum: SIGINT signal
 * Return: void
 */
void handler(int signum)
{
	(void)signum;
	flag = 1;
}
/**
 * main - Entry point
 * Return: 0 on success
 */
int main(void)
{
	char *buffer = NULL, **cmd = NULL, *prompt = "#cisfun$ ";
	size_t n = 0;
	int path = 0, i = 0, r = 0;

	while (1)
	{
		signal(SIGINT, handler);
		if (isatty(STDIN_FILENO))
		{
			if (write(1, prompt, _strlen(prompt) + 1) == -1)
				exit(-1);
		}
		if (getline(&buffer, &n, stdin) == -1)
		{
			free(buffer);
			exit(0);
		}
		if (flag == 1)
			break;
		if (buffer)
		{
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
			if (r == 0 && path != 1)
				perror("./hsh");
		}
	}
	free(buffer);
	return (0);
}
