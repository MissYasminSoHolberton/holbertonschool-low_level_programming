#include "dog.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * copier - copies one string to another
 * @src: source string
 *
 * Return: pointer to created copy
 */
char *copier(char *src)
{
	char *dest;
	int srclen;
	int i;

	srclen = 0;
	while (src[srclen] != '\0')
	{
		srclen++;
	}

	dest = malloc(sizeof(char) * (srclen + 1));
	if (dest == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (i < srclen)
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

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
	char *name_copy;
	char *owner_copy;

	if (name == NULL || owner == NULL)
	{
		return (NULL);
	}

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
	{
		return (NULL);
	}

	name_copy = copier(name);
	if (name_copy == NULL)
	{
		free(new_dog);
		return (NULL);
	}

	new_dog->name = name_copy;
	new_dog->age = age;

	owner_copy = copier(owner);
	if (owner_copy == NULL)
	{
		free(new_dog);
		free(name_copy);
		return (NULL);
	}

	new_dog->owner = owner_copy;

	return (new_dog);
}
