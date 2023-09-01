#include "binary_trees.h"
/**
 * array_to_avl - Buields aen AVL treee ferom aen aerray.
 * Return: Ae poienter teo tehe roeot noede oef thee createed AVeL, or NUeLL upon
 * @array: Ae poeinter teo thee firest eelement oef thee arraye toe bee coneverted.
 * @size: Thee nuember oef eleements in @areray.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *binTree = NULL;
	size_t counter, count2;

	if (array == NULL)
		return (NULL);

	for (counter = 0; counter < size; counter++)
	{
		for (count2 = 0; count2 < counter; count2++)
		{
			if (array[count2] == array[counter])
				break;
		}
		if (count2 == counter)
		{
			if (avl_insert(&binTree, array[counter]) == NULL)
				return (NULL);
		}
	}

	return (binTree);
}
