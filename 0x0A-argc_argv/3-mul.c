#include <stdio.h>

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
		printf("%d\n", argv[1] * argv[2]);
		return (0);
	}

	printf("Error");
	return (1);
}
