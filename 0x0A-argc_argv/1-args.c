#include <stdio.h>

/**
 * main - check the code
 *
 * @argc: args length
 * @argv: args array
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	if (argc > 0)
		printf("%d\n", argc - 1);

	return (0);
}
