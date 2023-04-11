#include<stdio.h>
#include<stdlib.h>

/**
 * count_coins - count the minimum number of coins needed to make change
 *
 * @cents: the amount of cents to make change for
 *
 * Return: the minimum number of coins
 */
int count_coins(int cents)
{
	int coins = 0;

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	while (cents >= 25)
	{
		coins++;
		cents -= 25;
	}

	while (cents >= 10)
	{
		coins++;
		cents -= 10;
	}

	while (cents >= 5)
	{
		coins++;
		cents -= 5;
	}

	while (cents >= 2)
	{
		coins++;
		cents -= 2;
	}

	while (cents >= 1)
	{
		coins++;
		cents -= 1;
	}

	return (coins);
}

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
	int cents;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	printf("%d\n", count_coins(cents));
	return (0);
}
