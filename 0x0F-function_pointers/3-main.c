#include "3-calc.h"

/**
 * main - check the code
 * @argc: The number of arguments
 * @argv: The arguments vector
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int a, b, ans;
	int (*op_func)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);
	f = get_op_func(argv[2]);

	if (f == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	if ((argv[2][0] == '/' || argv[2][0] == '%') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	ans = f(a, b);
	printf("%d\n", ans);

	return (0);
}
