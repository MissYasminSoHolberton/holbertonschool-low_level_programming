#include "main.h"

/**
 * times_table - print times table with formatting
 *
 * Return: always void
 */
void times_table(void)
{
int num1;
int num2;
int product;

for (num1 = 0; num1 <= 9; num1++)
{
_putchar('0');

for (num2 = 0; num2 <= 9; num2++)
{
product = num1 * num2;
_putchar(',');
_putchar(' ');
if (product < 10)
{
_putchar(' ');
_putchar(product + '0');
}
else
{
_putchar(product / 10 + '0');
_putchar(product % 10 + '0');
}
}
_putchar('\n');
}
}
