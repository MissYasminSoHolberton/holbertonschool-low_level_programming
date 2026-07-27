#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "variadic_functions.h"

/**
 * print_char - print a char
 * @list: argument
 */
void print_char(va_list list)
{
	printf("%c", va_arg(list, int));
}

/**
 * print_int - print a int
 * @list: argument
 */
void print_int(va_list list)
{
	printf("%d", va_arg(list, int));
}

/**
 * print_float - print a float
 * @list: argument
 */
void print_float(va_list list)
{
	printf("%f", va_arg(list, double));
}

/**
 * print_string - print a string
 * @list: argument
 */
void print_string(va_list list)
{
	char *string;

	string = va_arg(list, char*);

	if (string == NULL)
	{
		string = "(nil)";
	}
	printf("%s", string);
}

/**
 * print_all - print differnt types
 * @format: format of arg
 */
void print_all(const char * const format, ...)
{
	va_list list;
	int i;
	int j;
	char *separator;

	printer_t printers[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{'\0', NULL}
	};

	separator = "";

	va_start(list, format);

	j = 0;
	while (format[j] != '\0')
	{
		i = 0;
		while (printers[i].format != '\0')
		{
			if (format != NULL && format[j] == printers[i].format)
			{
				printf("%s", separator);
				printers[i].print(list);
				separator = ", ";
			}
			i = i + 1;
		}
		j = j + 1;
	}

	printf("\n");
	va_end(list);
}
