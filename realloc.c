#include "main.h"
/**
 * _realloc - function that changes the size of
 * the memory block pointed to by ptr to size bytes.
 * @ptr: pointer to memory block
 * @size: size of new block
 * Return: a pointer to the newly allocated memory or
 * NULL if the request fails.
 * Description: If _realloc() fails the original
 * block is left untouched; it is not freed or moved.
 */
void *_realloc(void *ptr, size_t size)
{
	char *new = NULL;

	int i = 0;

	if (ptr != NULL && size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL && size == 0)
		return (NULL);
	if (sizeof(ptr) == size)
		return (ptr);
	new = malloc(size);
	if (new == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	if (ptr)
	{
		for (i = 0; ((char *)ptr)[i]; i++)
			new[i] = ((char *)ptr)[i];
		free(ptr);
	}
	return ((void *)new);
}
