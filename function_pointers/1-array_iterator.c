#include "function_pointers.h"
#include <stddef.h>

/**
 * array_iterator - executes an function to a array
 * @array: input array
 * @size: size or array
 * @action: function poiners
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	i = 0;

	while (i < size)
	{
		action(array[i]);
		i = i + 1;
	}
}
