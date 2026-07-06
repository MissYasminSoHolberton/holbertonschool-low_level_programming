#include <stdio.h>
#include "main.h"

/**
 * print_alphabet - prints out lowercase alphabet 10 times
 *
 * Return: always 0 (success)
 */
int print_alphabet_x10(void)
{
int i;
int j;

for (j = 0; j <= 9; j++)
{
for (i = 97; i <= 122; i++)
{
_putchar(i);
}
_putchar('\n');
}
return (0);
}
