#ifndef MAIN_H
#define MAIN_H

/**
 * struct dog - dog's attributes
 *
 * @name: attribute 1
 * @age: attribute 2
 * @owner: attribute 3
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);

#endif
