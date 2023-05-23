#include "main.h"
/**
 * cd_func - implementation of cd command
 * dest_Dir: destination directory
 * Return: nothing
 */
void cd_func(char *dest_Dir)
{
	char *home, *old_dir, *pwd;

	pwd = getenv("PWD");
	printf("%s\n", pwd);
	if (dest_Dir == NULL || (*dest_Dir == '~' && dest_Dir[1] == '\0'))
	{
		home = getenv("HOME");
		printf("%s\n", home);
		if (chdir(home) == -1)
			perror("Directory not found");
		return;
	}
	if (*dest_Dir == '-' && dest_Dir[1] == '\0')
	{
		old_dir = getenv("OLDPWD");
		printf("%s\n", old_dir);
		if (chdir(old_dir) == -1)
			perror("Directory not found");
		return;
	}
	if (chdir(dest_Dir) == -1)
		perror("Directory not found");
	pwd = getenv("PWD");
	printf("%s\n", pwd);
}
