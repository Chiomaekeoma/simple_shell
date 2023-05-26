#include "shell.h"

/**
 * get_saaaaaa - func
 * @name: name
 * @head: head
 * Return: struct
 */
list_pa *get_saaaaaa(char *name, list_pa *head)
{
	while (head)
	{
		if (_varllp(name, head->path))
			return (head);
		head = head->next;
	}

	return (NULL);
}
/**
 * _varllp - function
 * @var_name: name of variable
 * @full_var: full variable
 * Return: integer
 */
int _varllp(char *var_name, char *full_var)
{
	int z;

	for (z = 0; var_name[z]; z++)
	{
		if (full_var[z])
			if (var_name[z] - full_var[z] != 0)
				return (-1);
	}
	if (full_var[z] == '=')
		return (0);

	return (-1);
}

/**
 * nu_to_ch - func
 * @nom: number
 * Return: chararcter
 */
char *nu_to_ch(int nom)
{
	/*count digits*/
	int c = 0, top = nom;
	char *cp_num;

	if (nom == 0)
	{
		c = 1;
	}
	else
	{
		while (top != 0)
		{
			top /= 10;
			c++;
		}
	}

	cp_num = malloc(sizeof(char) * (c + 1));
	if (!cp_num)
	{
		perror("malloc");
		return (NULL);
	}
	cp_num[c] = '\0';
	while (c != 0)
	{
		c--;
		cp_num[c] = '0' + nom % 10;
		nom /= 10;
	}

	return (cp_num);
}

/**
 * cher_cot_pid - func
 * @str: string
 * @c: char
 * Return: unsigned integer
 */
unsigned int cher_cot_pid(char *str, char c)
{
	unsigned int count = 0;

	while (*str != '\0')
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count + 1);
}
