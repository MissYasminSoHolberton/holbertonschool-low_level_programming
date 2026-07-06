#include <stdio.h>
#include "main.h"

/**
 * print_alphabet - prints out lowercase alphabet
 *
 * Return: always 0 (success)
 */
int print_alphabet(void)
{
int i;
for (i = 97; i <= 122; i++)
{
_putchar(i);
}
_putchar('\n');
return (0);
}
