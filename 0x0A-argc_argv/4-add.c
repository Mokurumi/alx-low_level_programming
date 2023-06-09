#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

/**
 * main - check the code
 *
 * @argc: args length
 * @argv: args array
 *
 * Return: 0 on success, 1 on error
 *
 */
int main(int argc, char *argv[])
{
	int i = 1, sum = 0, num, j;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	while (i < argc)
	{
		/* Check if the argument contains only digits */
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (1);
			}
		}

		num = atoi(argv[i]);

		/* Check if the number is positive */
		if (num < 0)
		{
			printf("Error\n");
			return (1);
		}

		sum += num;
		i++;
	}

	printf("%d\n", sum);
	return (0);
}
