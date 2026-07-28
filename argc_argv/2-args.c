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
	int i;

	i = 0;
	while(i < argc)
	{
		printf("%s\n", argv[i]);
		i = i + 1;
	}
	return (0);
}
