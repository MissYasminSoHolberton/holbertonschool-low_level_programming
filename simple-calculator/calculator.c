#include <stdio.h>

/**
 * add - add two integers
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
 * subtract - subtract two integers
 */
void subtract(void)
{
	int num1;
	int num2;

	printf("A: ");
	scanf("%d", &num1);
	printf("B: ");
	scanf("%d", &num2);

	printf("Result: %d\n", num1 - num2);
}

/**
 * multiply - multiply two integers
 */
void multiply(void)
{
	int num1;
	int num2;

	printf("A: ");
	scanf("%d", &num1);
	printf("B: ");
	scanf("%d", &num2);

	printf("Result: %d\n", num1 * num2);
}

/**
 * divide - divide two floats
 */
void divide(void)
{
	float num1;
	float num2;

	printf("A: ");
	scanf("%f", &num1);
	printf("B: ");
	scanf("%f", &num2);

	if (num2 == 0)
	{
		printf("Error: division by zero\n");
	}
	else
	{
		printf("Result: %.1f\n", num1 / num2);
	}
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
				subtract();
				break;
			case 3:
				multiply();
				break;
			case 4:
				divide();
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
