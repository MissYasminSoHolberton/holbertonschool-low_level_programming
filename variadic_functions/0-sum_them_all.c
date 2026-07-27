#include <stdarg.h>

/**
 * sum_them_all - get the sum of all args
 * @n: input
 *
 * Return: sum of all args
 */
int sum_them_all(const unsigned int n, ...)
{
	int result;
	va_list ap;
	unsigned int i;

	result = 0;
	i = 0;

	va_start(ap, n);

	while (i < n)
	{
		result = result + va_arg(ap, int);
		i = i + 1;
	}

	va_end(ap);
	return (result);
}
