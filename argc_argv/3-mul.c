#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point of program
 * @argc: number of arguments
 * @argv: array or args
 *
 * Return: 0 if success
 */
int main(int argc, char *argv[])
{
	int i;
	int product;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	i = 1;
	product = 1;

	while (i < argc)
	{
		product = product * atoi(argv[i]);
		i = i + 1;
	}

	printf("%d\n", product);
	return (0);
}
