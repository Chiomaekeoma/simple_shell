#include "main.h"
/**
 * append_path - a function that appends command to its path
 * @cmd: address of command
 * Return: 1 if path appended. -1 on error
 */
int append_path(char **cmd)
{
	char *path, *path_copy, *cmd_path, *file_path;

	struct stat stat_buffer;

	path = getenv("PATH");
	path_copy = strdup(path);
	cmd_path = strtok(path_copy, ":");
	while (cmd_path)
	{
		file_path = malloc(strlen(cmd_path) + strlen(*cmd) + 2);
		if (file_path == NULL)
			return (-1);
		strcpy(file_path, cmd_path);
		strcat(file_path, "/");
		strcat(file_path, *cmd);
		if (stat(file_path, &stat_buffer) == 0)
		{
			free(*cmd);
			*cmd = malloc(sizeof(file_path));
			if (*cmd == NULL)
				return (-1);
			strcpy(*cmd, file_path);
			free(file_path);
			free(path_copy);
			return (1);
		}
		else
		{
			free(file_path);
			cmd_path = strtok(NULL, ":");
		}
	}
	free(path_copy);
	if (stat(*cmd, &stat_buffer) == 0)
		return (1);
	return (-1);
}
