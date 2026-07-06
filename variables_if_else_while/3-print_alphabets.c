#include <stdio.h>

/**
 * main - prints all the lowercase alphabet
 *
 * Return: always 0 (success)
 */
int main(void)
{

int i;
int j;

for (i = 97; i <= 122; i++)
{
putchar(i);
}
for (j = 65; j <= 90; j++)
{
putchar(j);
}
putchar('\n');
return (0);
}
