#include "function_pointers.h"
#include <stddef.h>

/**
 * int_index - get the index of the matched element
 * @array: input array
 * @size: size or array
 * @cmp: function poiners
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	i = 0;

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
