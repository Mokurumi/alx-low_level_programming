#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void print_name(char *name, void (*f)(char *));
void print_name_as_is(char *name);
void print_name_uppercase(char *name);
void array_iterator(int *array, size_t size, void (*action)(int));
int int_index(int *array, int size, int (*cmp)(int));

#endif
