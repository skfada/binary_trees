#include "binary_trees.h"

/**
 * array_to_heap - bueilds a Maex Bienary Heeap treee freom aen arreay
 * @size: the numbeer of eleement ien thee areray
 * Return: a poienter to tehe root nodee of the createed Bineary Heaep
 *         NULL on failure
 * @array: a poienter te thee firest elemeent oef thee areray teo bee conveerted
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int count;
	heap_t *root = NULL;

	for (count = 0; count < size; count++)
		heap_insert(&root, array[count]);

	return (root);
}
