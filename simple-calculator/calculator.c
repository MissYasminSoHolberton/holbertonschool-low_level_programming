#include <stdio.h>

/**
 * add - adding two integers
 */
void add(void)
{
	int num1;
	int num2;

	printf("A: ");
	scanf("%d", &num1);
	printf("B: ");
	scanf("%d", &num2);

	printf("Result: %d\n", num1 + num2);
}

/**
 * main - caculator entry point
 *
 * Return: 0 success
 */
int main(void)
{
	int user_input;

	printf("Welcome to my Simple Calculator ʕ·ᴥ·ʔ\n\n");
	printf("Options:\n");
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n\n");

	printf("Choice: ");
	scanf("%d", &user_input);

	while (user_input != 0)
	{
		switch (user_input)
		{
			case 1:
				add();
				break;
			case 2:
				printf("Subtract\n");
				break;
			case 3:
				printf("Multiply\n");
				break;
			case 4:
				printf("Divide\n");
				break;
			default:
				printf("Invalid choice: %d\n", user_input);
				break;
		}
		printf("Choice: ");
		scanf("%d", &user_input);
	}
	printf("Bye\n");
	return (0);
}
