#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - printing strings with separator
 * @separator: separator
 * @n: number of strings to print
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list strings;
	unsigned int i;
	int j;
	char *word;

	i = 0;

	if (separator == NULL)
		separator = "";

	if (n == 0)
	{
		printf("\n");
		return;
	}
	va_start(strings, n);
	word = va_arg(strings, char*);
	if (word == NULL)
		printf("(nil)");
	else
		printf("%s", word);
	while (i < n - 1)
	{
		j = 0;
		while (separator[j] != '\0')
		{
			printf("%c", separator[j]);
			j = j + 1;
		}
		word = va_arg(strings, char*);
		if (word == NULL)
			printf("(nil)");
		else
			printf("%s", word);
		i = i + 1;
	}
	printf("\n");
	va_end(strings);
}
