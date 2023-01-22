#include "sort.h"

/**
 * selection_sort - sorts an array of integers in an array
 * @array: array to be sorted
 * @size: size of the array
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min, temp;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (array[i] > array[min] && i < size - 1)
		{
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
		print_array(array, size);
		}
	}
}
