#include "ss_head.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: original pointer
 * @old_size: original size of the memory
 * @new_size: the size of the new memory block
 *
 * The contents will be copied to the newly allocated space, in the range
 * from the start of ptr up to the minimum of the old and new sizes.
 * If new_size > old_size, the “added” memory should not be initialized.
 * If new_size == old_size do not do anything and return ptr.
 * If ptr is NULL, then the call is equivalent to malloc(new_size).
 * If new_size is equal to zero, and ptr is not NULL, then the call is
 * equivalent to free(ptr). Return NULL.
 *
 * Return: a pointer to the allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	char *ptrc;
	unsigned int iter, i;

	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		return (p);
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	ptrc = ptr;
	iter = old_size > new_size ? new_size : old_size;
	p = malloc(new_size);
	if (p == NULL)
	{
		/* free(ptr); */
		return (NULL);
	}
	for (i = 0; i < iter; i++)
		p[i] = ptrc[i];
	free(ptr);
	return (p);
}
