#include "dog.h"
#include <stddef.h>

/**
 * init_dog - initalize dog struct
 * @d: dog struct
 * @name: name of doggo
 * @age: age of doggo
 * @owner: owner of doggo
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
	{
		return;
	}
	d->name = name;
	d->age = age;
	d->owner = owner;
}
