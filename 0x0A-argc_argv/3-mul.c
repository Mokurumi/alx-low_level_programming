#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code
 *
 * @argc: args length
 * @argv: args array
 *
 * Return: output
 */
int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		/* Convert arguments to integers */
		int num1 = atoi(argv[1]);
		int num2 = atoi(argv[2]);

		printf("%d\n", num1 * num2);
		return (0);
	}

	printf("Error\n");
	return (1);
}
