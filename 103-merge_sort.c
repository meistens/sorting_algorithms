#include "sort.h"
#include "string.h"

/**
 * merge - merge two part of an array
 * @prmArray: array of int to sort
 * @prmStart: start of the array
 * @prmMiddle: middle of the array
 * @prmEnd: end of the array
 * Return: nothing void
 */
void merge(int *prmArray, int prmStart, int prmMiddle, int prmEnd)
{
	int lp1, lp2, lp3, lp4 = 0;
	int size1 = prmMiddle - prmStart + 1, size2 = prmEnd - prmMiddle;
	int tmp1[4096], tmp2[4096];
	int *tmp3 = malloc(sizeof(int) * (size1 + size2));

	for (lp1 = 0, lp2 = 0; lp1 < size1 || clp2 < size2; lp1++, lp2++)
	{
		tmp1[lp1] = prmArray[prmStart + lp1];
		tmp2[lp2] = prmArray[prmMiddle + 1 + lp2];
	}

	for (lp1 = lp2 = 0, lp3 = prmStart;
	     lp1 < size1 && lp2 < size2; lp3++)
		if (tmp1[lp1] <= tmp2[lp2])
			prmArray[lp3] = tmp3[lp4++] = tmp1[lp1++];
		else
			prmArray[lp3] = tmp3[lp4++] = tmp2[lp2++];

	printf("Merging...\n[left]: ");
	print_array(tmp1, size1);
	printf("[right]: ");
	print_array(tmp2, size2);

	while (lp1 < size1)
		prmArray[lp3++] = tmp3[lp4++] = tmp1[lp1++];

	while (lp2 < size2)
		prmArray[lp3++] = tmp3[lp4++] = tmp2[lp2++];

	printf("[Done]: ");
	print_array(tmp3, size1 + size2);

	free(tmp3);
}

/**
 * sort - sort the array then merge it recursively
 * @prmArray: array of int to sort
 * @prmStart: begin of the array
 * @prmEnd: end of the array
 * Return: nothing void
 */

void sort(int *prmArray, int prmStart, int prmEnd)
{
	int middle;

	if (prmStart < prmEnd)
	{
		middle = (prmStart + prmEnd - 1) / 2;
		sort(prmArray, prmStart, middle);
		sort(prmArray, middle + 1, prmEnd);
		merge(prmArray, prmStart, middle, prmEnd);
	}
}

/**
 * merge_sort - function that sorts an array of integers in ascending
 * order using the Merge sort algorithm
 * @Array: array of int to sort
 * @size: size of the array
 * Return: nothing void
 */

void merge_sort(int *Array, size_t size)
{
	if (Array == NULL || size < 2)
		return;
	sort(Array, 0, size - 1);
}
