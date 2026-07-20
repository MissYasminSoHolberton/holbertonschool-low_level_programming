#include <stdio.h>
#include <limits.h>

/**
 * input_handler - scanf and validate single integer inputs
 *
 * Return: 0 success, -1 otherwise
 */
int input_handler(int* number)
{
	int scanf_buffer_value;
	int scanf_return_value;
	int has_trailing_value;
	long input;

	scanf_return_value = scanf("%11ld", &input);
	
	scanf_buffer_value = getchar();
	has_trailing_value = (scanf_buffer_value != '\n' && scanf_buffer_value != EOF);

	// clear input buffer
	while ( scanf_buffer_value != '\n' && scanf_buffer_value != EOF ) {scanf_buffer_value = getchar();}

	// checks if scanf is successful
	if (scanf_return_value != 1)
	{
		printf("Invalid input, not a number! Try again!\n\n");
		return -1;
	}

	// check if number fits in an int
	if (input > INT_MAX || input < INT_MIN)
	{
		printf("Invalid input, out of range number! Try again!\n\n");
		return -1;
	}

	// check if there are non whole number in input
	if (has_trailing_value)
	{
		printf("Invalid input, not a whole number! Try again!\n\n");
		return -1;
	}

	*number = (int)input;
	return 0;
}

/**
 * get_two_numbers - gets two number and do appropriate checks
 *
 * Return: 0 if success, -1 otherwise
 */
int get_two_numbers(int nums[2])
{
	printf(" two whole numbers! Decimals discarded!\nA: ");
	if (input_handler(&nums[0])  == -1)
	{
		return -1;
	}

	printf("B: ");
	if (input_handler(&nums[1]) == -1)
	{
		return -1;
	}
	return 0;
}

/**
 * add - add two integers
 */
void add(void)
{
	int nums[2];
	printf("\nAdd");
	if(get_two_numbers(nums) == -1)
		return;
	if((nums[0] > 0 && nums[1] > INT_MAX - nums[0]) || (nums[0] < 0 && nums[1] < INT_MIN -nums[0]))
	{
		printf("Result out of range! Try again!\n\n");
		return;
	}
	printf("Result: %d\n\n", nums[0] + nums[1]);
}

/**
 * subtract - subtract two integers
 */
void subtract(void)
{
	int nums[2];
	printf("\nSubtract");
	if(get_two_numbers(nums) == -1)
		return;
	if((nums[1] > 0 && nums[0] < INT_MIN + nums[1]) || (nums[1] < 0 && nums[0] > INT_MAX + nums[1]))
	{
		printf("Result out of range! Try again!\n\n");
		return;
	}
	printf("Result: %d\n\n", nums[0] - nums[1]);
}

/**
 * multiply - multiply two integers
 */
void multiply(void)
{
	int nums[2];
	long long product;
	printf("\nMultiply");
	if(get_two_numbers(nums) == -1)
		return;
	product = (long long)nums[0] * nums[1];
	if (product > INT_MAX || product < INT_MIN)
	{
		printf("Result out of range! Try again!\n\n");
		return;
	}
	printf("Result: %d\n\n", (int)product);
}

/**
 * divide - divide two ints, prints result as a float
 */
void divide(void)
{
	int nums[2];
	printf("\nDivide");
	if(get_two_numbers(nums) == -1)
		return;

	if (nums[1] == 0)
	{
		printf("Error: division by zero\n\n");
	}
	else
	{
		printf("Result: %.1f\n\n", (float)nums[0] / nums[1]);
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

	while (1)
	{
		printf("Options:\n");
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");
	
		while (input_handler(&user_input) == -1)
		{
			printf("Choice: ");
		}

		if (user_input == 0)
		{
			break;
		}

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
				printf("Invalid menu option! Try again!\n\n");
				break;
		}
	}

	printf("Bye!\n");
	return (0);
}
