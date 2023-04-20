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
	char *operator;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);
	operator = argv[2];

	op_func = get_op_func(operator);

	if (op_func  == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	if ((*operator == '/' || *operator == '%') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	ans = op_func(a, b);
	printf("%d\n", ans);

	return (0);
}
