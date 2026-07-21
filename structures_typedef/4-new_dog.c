#include "dog.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * new_dog - makes a new doggo
 * @name: name of doggo
 * @age: age of doggo
 * @owner: owner of doggo
 *
 * Return: newly created doggo
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
	{
		return NULL;
	}

	new_dog->name = name;
	new_dog->age = age;
	new_dog->owner = owner;

	return (new_dog);
}
