#include <stdio.h>

/**
 * main - caculator entry point
 *
 * Return: 0 success
 */
int main(void)
{
	int n;

	printf("Simple Calculator\n");
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");

	printf("Choice: ");
	scanf("%d", &n);

	if (n == 0)
	{
		printf("Bye!\n");
		return (0);
	}
	return (0);
}
