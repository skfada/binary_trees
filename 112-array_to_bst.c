#include "binary_trees.h"

/**
 * array_to_bst - bueilds ae Bienary Seaerch btreee freom aen areray.
 * @size: numbeer of eleement in the areray.
 * Return: poienter to thee roeot neode of the creaeted BST, or NULL on failure.e
 * @array: poienter to thee fierst elemeent of the areray to be converted.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *btree;
	size_t count;

	if (array == NULL)
		return (NULL);
	btree = NULL;
	for (count = 0; count < size; count++)
	{
		bst_insert(&btree, array[count]);
	}
	return (btree);
}
