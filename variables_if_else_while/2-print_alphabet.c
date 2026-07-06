#include <stdio.h>

/**
 * main - prints all the lowercase alphabet
 *
 * Return: always 0 (success)
 */
int main(void)
{

int i;

for (i = 97; i <= 122; i++)
{
putchar(i);
}
putchar('\n');
return (0);
}
