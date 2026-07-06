#include <stdio.h>

/**
 * main - prints all the lowercase alphabet in reverse
 *
 * Return: always 0 (success)
 */
int main(void)
{

int i;

for (i = 122; i >= 97; i--)
{
putchar(i);
}
putchar('\n');
return (0);
}
