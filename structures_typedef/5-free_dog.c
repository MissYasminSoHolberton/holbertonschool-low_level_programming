#include "dog.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * free_dog - free the doggo! free the memory allocated
 * @d: struct that was made
 */
void free_dog(dog_t *d)
{
	free(d->name);
	free(d->owner);
	free(d);
}
