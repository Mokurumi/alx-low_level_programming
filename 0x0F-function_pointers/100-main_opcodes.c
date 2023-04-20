#include "function_pointers.h"

/**
 * main - check the code
 * @argc: The number of arguments
 * @argv: The arguments vector
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int bytes, i;
	char *main_code = (char *) main;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < bytes; i++)
	{
		printf("%02hhx", main_code[i]);

		if (i != bytes - 1)
			printf(" ");

	}

	printf("\n");

	return (0);
}
