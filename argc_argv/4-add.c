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
	int sum;
	int num;

	i = 1;
	sum = 0;

	while (i < argc)
	{
		if (*argv[i] == '0')
		{
			sum = sum + num;
			continue;
		}

		num = atoi(argv[i]);

		if (num == 0)
		{
			printf("Error\n");
			return (1);
		}

		sum = sum + num;
		i = i + 1;
	}

	printf("%d\n", sum);
	return (0);
}
