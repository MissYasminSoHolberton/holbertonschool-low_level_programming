#include "function_pointers.h"
#include <stddef.h>

/**
 * int_index - get the index of the matched element
 * @array: input array
 * @size: size or array
 * @cmp: function poiners
 *
 * Return: index of the string and -1 if cant find in the array
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	i = 0;

	if (array == NULL)
	{
		return (-1);
	}

	if (cmp == NULL)
	{
		return (-1);
	}

	if (size <= 0)
	{
		return (-1);
	}

	while (i < size)
	{
		if (cmp(array[i]))
			return (i);
		i = i + 1;
	}

	return (-1);
}
