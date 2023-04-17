#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

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

/**
 * dog_t - struct dog type
 */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);

#endif
