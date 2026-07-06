#include "main.h"

/**
 * print_last_digit - print last digit of number
 * @n: number input
 *
 * Return: always 0 (success)
 */
int print_last_digit(int n)
{

int last;
last = n % 10;

if (last < 0)
{
last *= -1;
}

_putchar(last + '0');

return (last);
}
