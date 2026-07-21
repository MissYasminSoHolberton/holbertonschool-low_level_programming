#ifndef DOG_H
#define DOG_H

/**
 * struct dog - information about poopy!!!
 * @name: name of poppy
 * @age: age of the good poppy
 * @owner: feeder of poopy
 *
 * Description: Dog has a name, age and owner
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif
