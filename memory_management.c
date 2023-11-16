#include "shell.h"

/**
 * safe_malloc - Allocates memory safely
 * @size: Size of memory to allocate
 * Return: Pointer to allocated memory
 */
void *safe_malloc(size_t size)
{
	void *ptr = malloc(size);

	if (!ptr)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
