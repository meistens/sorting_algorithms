#include "sort.h"

/**
 * quick_sort - sorts an array of integers using lomuto partition
 * @array: array for the sort
 * @size: size of the elements in the array
 *
 */

void quick_sort(int *array, size_t size)
{
	mod(array, size, 0, size - 1);
}

/**
 * partition - rearranges the array into two subarrays
 * @array: main array
 * @low: lowest index of the subarray
 * @high: highest index of the subarray
 * @size: size of the array
 *
 * Return: new index of the pivot
 */

int partition(int *array, int low, int high, size_t size)
{
	int temp;
	int x = low - 1, y;
	int pivot = array[high];

	for (y = low; y <= high; y++)
	{
		if (array[y] <= pivot)
		{
			x++;
			if (x != y)
			{
				temp = array[x];
				array[x] = array[y];
				array[y] = temp;
				print_array(array, size);
			}
		}
	}
	return (x);
}

/**
 * mod - modified quick_sort function
 * @array: array
 * @size: size of elements in the array
 * @low: lowest index of the left/lowest subarray
 * @high: highest index of the right/highest subarray
 *
 */

void mod(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int part = partition(array, low, high, size);

		mod(array, size, low, part - 1);
		mod(array, size, part + 1, high);
	}
}
