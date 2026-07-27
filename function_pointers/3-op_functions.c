#include <stddef.h>
#include "3-calc.h"

/**
 * op_add - adding two numbers
 * @a: first number
 * @b: second number
 *
 * Return: the sum of two numbers
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtracting two numbers
 * @a: first number
 * @b: second number
 *
 * Return: the difference of two numbers
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiplying two numbers
 * @a: first number
 * @b: second number
 *
 * Return: the product of two numbers
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - diving two numbers
 * @a: first number
 * @b: second number
 *
 * Return: the product of two numbers
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - remainder of two numbers
 * @a: first number
 * @b: second number
 *
 * Return: remainder of two numbers
 */
int op_mod(int a, int b)
{
	return (a % b);
}
