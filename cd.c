#include "main.h"
/**
 * cd_func - implementation of cd command
 * @dest_Dir: destination directory
 * Return: nothing
 */
void cd_func(char *dest_Dir)
{
	char *home, *old_dir;

	if (dest_Dir == NULL || (*dest_Dir == '~' && dest_Dir[1] == '\0'))
	{
		home = _getenv("HOME");
		if (chdir(home) == -1)
			perror("Directory not found");
		return;
	}
	if (*dest_Dir == '-' && dest_Dir[1] == '\0')
	{
		old_dir = _getenv("OLDPWD");
		if (chdir(old_dir) == -1)
			perror("Directory not found");
		return;
	}
	if (chdir(dest_Dir) == -1)
		perror("Directory not found");
}
