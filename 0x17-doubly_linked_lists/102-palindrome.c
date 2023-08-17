#include <stdio.h>

/**
 * is_palindrome - Check if a number is a palindrome
 * @n: The number to check
 *
 * Return: 1 if the number is a palindrome, 0 otherwise
 */
int is_palindrome(int n)
{
	int original = n;
	int reversed = 0;

	while (n > 0)
	{
		reversed = reversed * 10 + n % 10;
		n /= 10;
	}

	return (original == reversed);
}

/**
 * main - Entry point of the program
 *
 * Return: 0 upon success
 */
int main(void)
{
	int i, j, product, largest_palindrome = 0;
	FILE *fp;

	for (i = 100; i < 1000; i++)
		for (j = 100; j < 1000; j++)
		{
			product = i * j;
			if (is_palindrome(product) && product > largest_palindrome)
				largest_palindrome = product;
		}

	printf("The largest palindrome made from the product of two 3-digit numbers is: %d\n", largest_palindrome);

	fp = fopen("102-result", "w");
	if (fp != NULL)
	{
		fprintf(fp, "%d\n", largest_palindrome);
		fclose(fp);
		printf("Result saved in file '102-result'\n");
	}
	else
		printf("Failed to save result to file\n");

	return (0);
}
