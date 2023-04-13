#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * check_digits - check if the given string is composed only of digits
 *
 * @str: the string to check
 *
 * Return: 1 if str contains only digits, 0 otherwise
 */
int check_digits(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
			return (0);

		i++;
	}

	return (1);
}

/**
 * main - multiply two positive numbers
 *
 * @argc: the number of arguments
 * @argv: an array of pointers to the arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int num1, num2, product;

	/* Check the number of arguments */
	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	/* Check if the arguments are valid */
	if (!check_digits(argv[1]) || !check_digits(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	/* Convert arguments to integers */
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	/* Multiply the numbers */
	product = num1 * num2;

	/* Print the result */
	printf("%d\n", product);

	return (0);
}
