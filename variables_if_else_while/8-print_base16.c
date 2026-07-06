#include <stdio.h>

/**
 * main - prints all base 16 numbers in lowercase
 *
 * Return: always 0 (success)
 */
int main(void)
{

int i;
int j;

for (i = 48; i <= 57; i++)
{
putchar(i);
}
for (j = 97; j <= 102; j++)
{
putchar(j);
}
putchar('\n');
return (0);
}
