#include "main.h"
/**
 * split_command - A function that splits the command input
 * @cmd: command input
 * Return: an array of command tokens
 */
char **split_command(char *cmd)
{
	char *cmd_copy, *token, *delim = " \n", **array_of_tokens;

	int tokens_num = 0, i = 0;

	if (cmd == NULL || cmd[0] == '\0')
		return (NULL);
	cmd_copy = malloc(sizeof(char) * _strlen(cmd) + 1);
	if (cmd_copy == NULL)
		return (NULL);
	_strcpy(cmd_copy, cmd);
	token = _strtok(cmd, delim);
	while (token)
	{
		tokens_num++;
		token = _strtok(NULL, delim);
	}
	tokens_num++;
	array_of_tokens = malloc(sizeof(char *) * tokens_num);
	if (array_of_tokens == NULL)
		return (NULL);
	token = _strtok(cmd_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		array_of_tokens[i] = malloc(sizeof(char) * _strlen(token) + 1);
		if (array_of_tokens[i] == NULL)
			return (NULL);
		_strcpy(array_of_tokens[i], token);
		token = _strtok(NULL, delim);
	}
	array_of_tokens[i] = NULL;
	free(cmd_copy);
	return (array_of_tokens);
}
