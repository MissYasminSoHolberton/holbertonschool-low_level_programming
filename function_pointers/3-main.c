#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3-calc.h"

/**
 * main - entry point of the
 * @argc: number of cl arguments
 * @argv: cl arguments in an array
 *
 * Return: 0 if success
 */
int main(int argc, char *argv[])
{
	int result;
	int (*op)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	op = get_op_func(argv[2]);

	if (op == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	if ((strcmp(argv[2], "/") == 0 || strcmp(argv[2], "%") == 0)
		&& strcmp(argv[3], "0") == 0)
	{
		printf("Error\n");
		exit(100);
	}

	result = op(atoi(argv[1]), atoi(argv[3]));

	printf("%d\n", result);

	return (0);
}

