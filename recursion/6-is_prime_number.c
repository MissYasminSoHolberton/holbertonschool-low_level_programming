#include "main.h"

/**
 * guess_func - generates a guess
 * @input: input number
 * @guess: guess number
 *
 * Return: guess number
 */
int guess_func(int input, int guess)
{
	if (input % guess == 0)
	{
		return (0);
	}

	if (guess == input - 1)
	{
		return (1);
	}

	return (guess_func(input, guess + 1));
}

/**
 * is_prime_number - checks if a number is prime
 * @n: input number
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n < 2)
	{
		return (0);
	}

	return (guess_func(n, 2));
}
