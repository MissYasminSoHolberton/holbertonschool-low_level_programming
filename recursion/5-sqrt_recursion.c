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
	if (guess * guess > input)
	{
		return (-1);
	}
	if (guess * guess == input)
	{
		return (guess);
	}

	return (guess_func(input, guess + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of number
 * @n: input number
 *
 * Return: natural square root of number, -1 if it fails
 */
int _sqrt_recursion(int n)
{
	if (n == 1)
	{
		return (1);
	}
	if (n < 0)
	{
		return (-1);
	}

	return (guess_func(n, 0));
}
