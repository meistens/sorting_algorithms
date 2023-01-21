#include "sort.h"

/**
 * bubble_sort - bubble sort function
 * @array: array of integers
 * @size: size of the array
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp = 0;
	size_t n = size;
	/* creates a copy of the array */
	int *new_array = malloc(n * sizeof(int));

	new_array = array;

	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (new_array[j] > new_array[j + 1])
			{
				tmp = new_array[j];
				new_array[j] = new_array[j + 1];
				new_array[j + 1] = tmp;
				print_array(new_array, n);
			}
		}
	}
}
