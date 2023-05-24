#include "main.h"
int main(void)
{
	char *b = NULL;
	size_t n = 0;
	printf("$$ ");
	getline(&b, &n, stdin);
	printf("%s\n", b);
	return (0);
}
