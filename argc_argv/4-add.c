#include <stdio.h>
#include <stdlib.h>

/**
 * input_checker - checks if input is an int
 * @i: input
 *
 * Return: number if input is int, 0 otherwise
 */
int input_checker(char *i)
{
	int num;
	char *endptr;

	num = strtol(i, &endptr, 10);
	if (endptr == i)
	{
		return (0);
	}
	else if (*endptr != '\0')
	{
		return (0);
	}
	else
	{
		return (num);
	}
}

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

		num = input_checker(argv[i]);

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
