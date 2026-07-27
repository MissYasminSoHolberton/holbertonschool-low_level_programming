#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - printing all numbers with separator
 * @separator: separator
 * @n: numbers to print
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list numbers;
	unsigned int i;

	i = 0;

	if (separator == NULL)
	{
		separator = '\0';
	}

	va_start(numbers, n);

	printf("%d", va_arg(numbers, int));

	while (i < n - 1)
	{
		printf("%c ", *separator);
		printf("%d", va_arg(numbers, int));
		i = i + 1;
	}

	printf("\n");

	va_end(numbers);
}
