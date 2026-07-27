#include <stddef.h>
#include "3-calc.h"
#include <string.h>

/**
 * get_op_func - get the correct func
 * @s: char input
 *
 * Return: 0 for success
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
		};
	int i;

	i = 0;
	while (ops[i].op != NULL)
	{
		if (strcmp(s, ops[i].op) == 0)
		{
			return (ops[i].f);
		}
		i = i + 1;
	}
	return (NULL);
}

