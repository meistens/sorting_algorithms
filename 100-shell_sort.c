#include "sort.h"
/**
 * shell_sort - shell sort function using knuth sequence
 * @array: array
 * @size: size of the element in the array
 *
 */

void shell_sort(int *array, size_t size)
{
	size_t h = 0;
	size_t i = h;
	size_t ins;
	int temp;
	size_t j;

	if (array == NULL || size < 2)
		return;

	while (h <= size / 3)
		h = h * 3 + 1;
	while (h > 0)
	{
		for (i = h; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j > h - 1 && array[j - h] >= temp)
			{
				ins = array[j - h];
				array[j - h] = array[j];
				array[j] = ins;
				j = j - h;
			}
		}
		h = (h - 1) / 3;
		print_array(array, size);
	}
}
