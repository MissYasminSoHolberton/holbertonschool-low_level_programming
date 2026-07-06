#include "main.h"

/**
 * main - prints out _putchar
 *
 * Return: always 0 (success)
 */
int main(void)
{
char str[] = "_putchar";
int i = 0;
int count = sizeof(str) / sizeof(str[0]);

while (i < count - 1)
{
_putchar(str[i]);
i++;
}
_putchar('\n');
return (0);
}
