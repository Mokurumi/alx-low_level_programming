#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * shash_table_create - Creates a sorted hash table.
 *
 * @size: The size of the hash table's array.
 *
 * Return: A pointer to the newly created sorted hash table or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table = malloc(sizeof(shash_table_t));

	if (new_table == NULL)
		return (NULL);

	new_table->size = size;
	new_table->array = calloc(size, sizeof(shash_node_t *));
	if (new_table->array == NULL)
	{
		free(new_table);
		return (NULL);
	}

	new_table->shead = NULL;
	new_table->stail = NULL;
	return (new_table);
}

/**
 * create_shash_node - Creates a new sorted hash node.
 *
 * @key: The key for the new node.
 * @value: The value associated with the key.
 *
 * Return: A pointer to the newly created node or NULL on failure.
 */
static shash_node_t *create_shash_node(const char *key, const char *value)
{
	shash_node_t *new_node = malloc(sizeof(shash_node_t));

	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;
	new_node->sprev = NULL;
	new_node->snext = NULL;
	return (new_node);
}

/**
 * insert_sorted_node - Inserts a new node into the sorted linked list.
 *
 * @ht: The sorted hash table to insert into.
 * @new_node: The new node to insert.
 *
 * Return: 1 if successful, 0 otherwise.
 */
static int insert_sorted_node(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *current, *prev = NULL;

	if (new_node == NULL || ht == NULL)
		return (0);

	for (current = ht->shead; current != NULL; current = current->snext)
	{
		if (strcmp(new_node->key, current->key) < 0)
			break;
		prev = current;
	}

	new_node->sprev = prev;
	new_node->snext = current;

	if (prev == NULL)
	{
		ht->shead = new_node;
		if (current != NULL)
			current->sprev = new_node;
		if (ht->stail == NULL)
			ht->stail = new_node;
	}
	else
	{
		prev->snext = new_node;
		if (current != NULL)
			current->sprev = new_node;
		if (current == NULL)
			ht->stail = new_node;
	}

	return (1);
}

/**
 * shash_table_set - Inserts or updates a key-value pair
 * in the sorted hash table.
 *
 * @ht: The sorted hash table to insert/update in.
 * @key: The key to insert/update.
 * @value: The value associated with the key.
 *
 * Return: 1 if successful, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node, *current;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			if (current->value == NULL)
				return (0);
			return (1);
		}
		current = current->next;
	}

	new_node = create_shash_node(key, value);
	if (new_node == NULL)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	if (!insert_sorted_node(ht, new_node))
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}

	return (1);
}

/**
 * shash_table_get - Retrieves the value associated with a key
 * in the sorted hash table.
 *
 * @ht: The sorted hash table to search in.
 * @key: The key to look for.
 *
 * Return: The value associated with the key, or NULL if key couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints the contents of the sorted hash table
 * using the sorted linked list.
 *
 * @ht: The sorted hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;

	if (ht == NULL)
		return;

	printf("{");
	for (current = ht->shead; current != NULL; current = current->snext)
	{
		printf("'%s': '%s'", current->key, current->value);
		if (current->snext != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the contents of the sorted hash table
 * in reverse order using the sorted linked list.
 *
 * @ht: The sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;

	if (ht == NULL)
		return;

	printf("{");
	for (current = ht->stail; current != NULL; current = current->sprev)
	{
		printf("'%s': '%s'", current->key, current->value);
		if (current->sprev != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes the sorted hash table and frees its memory.
 *
 * @ht: The sorted hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *current, *temp;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current != NULL)
		{
			temp = current->next;
			free(current->key);
			free(current->value);
			free(current);
			current = temp;
		}
	}

	free(ht->array);
	free(ht);
}
