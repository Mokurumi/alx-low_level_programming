#include <stdio.h>
#include <math.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	long n = 612852475143;
    	long large_fact = 1;

	while (n % 2 == 0)
    	{
		large_fact = 2;
		n /= 2;
    	}

    	long sqrt_n = sqrt(n);

    	for (long i = 3; i <= sqrt_n; i += 2)
    	{
		while (n % i == 0)
		{
	    		large_fact = i;
	    		n /= i;
		}
    	}

    	if (n > 2)
    	{
		large_fact = n;
    	}

    	printf("%ld\n", large_fact);

    	return (0);
}
