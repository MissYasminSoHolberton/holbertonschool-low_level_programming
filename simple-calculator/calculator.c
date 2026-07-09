#include <stdio.h>

/**
 * main - caculator entry point
 *
 * Return: 0 success
 */
int main(void)
{
	int n;

	printf("Welcome to my Simple Calculator\n\n");
	printf("Options:\n");
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n\n");

	printf("Choice: ");
	scanf("%d", &n);

	if (n > 0 && n < 5)
	{
		printf("Your Choice: %d\n", n);
	}
	else if (n == 0)
	{
		printf("\nBye!\n");
	}
	else
	{
		printf("Incorrect option :(\n");
	}
	return (0);
}
