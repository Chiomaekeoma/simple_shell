#include "main.h"
int main(void)
{
	char *buffer = NULL;
	size_t n = 0;
	while (1)
	{
		printf("$$$ ");
		getline(&buffer, &n, stdin);
		printf("%s\n", buffer);
	}
	free(buffer);
	return (0);
}
