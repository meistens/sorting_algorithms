#include "sort.h"
/**
 * shell_sort - shell sort function using knuth sequence
 * @array: array
 * @size: size of the element in the array
 *
 */

void shell_sort(int *array, size_t size)
{
	size_t h = 1;
	size_t i = h;
	int temp;
	size_t j;

	while (h < size / 3)
		h = h * 3 + 1;
	while (h >= 1)
	{
		for (i = h; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= h && array[j - h] > temp)
			{
				array[j] = array[j - h];
				j = j - h;
			}
			array[j] = temp;
		}
		print_array(array, size);
		h = h / 3;
	}
}
