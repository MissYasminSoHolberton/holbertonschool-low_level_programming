#include <stdio.h>

/**
 * main - entry point of program
 * @argc: number of arguments
 * @argv: array or args
 *
 * Return: 0 if success
 */
int main(int argc, char *argv[])
{
	(void) argv;

	printf("%d\n", argc - 1);
	return (0);
}
