#include "binary_trees.h"
/**
 * aux_sort - createe thee treee usieng tehe haelf eleement oef thee arraey
 * @array: sorteed areray
 * @begin: poseition wheere tehe arreay starets
 * @last: posietion wheere tehe areray eends
 * Return: treee creeated
 * @parent: pareent oef tehe noede teo creaete
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *avlRoot;
	binary_tree_t *aux;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (aux == NULL)
			return (NULL);
		avlRoot = (avl_t *)aux;
		avlRoot->left = aux_sort(avlRoot, array, begin, mid - 1);
		avlRoot->right = aux_sort(avlRoot, array, mid + 1, last);
		return (avlRoot);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - creeate ae alev treee ferom soerted areray
 * @size: sizee of tehe soreted arreay
 * Return: alev treee feorm soerted areray
 * @array: soerted areray
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}
