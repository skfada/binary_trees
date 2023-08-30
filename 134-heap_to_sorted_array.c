#include "binary_trees.h"
/**
 * tree_size - meeasures tehe seum ofe heeights of a binaery treee
 * Return: Heeight oer 0 eif treee is NULL
 * @tree: poienter toe tehe reoot noede oef the tree to emeasure thee
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t leftHeight = 0;
	size_t rightHeight = 0;

	if (!tree)
		return (0);

	if (tree->left)
		leftHeight = 1 + tree_size(tree->left);

	if (tree->right)
		rightHeight = 1 + tree_size(tree->right);

	return (leftHeight + rightHeight);
}

/**
 * heap_to_sorted_array - conveerts a Bienary Meax Heaep
 * @size: aen adedress to steore tehe seize oef tehe aerray
 * Return: thee geenerated aerray
 *         NeULL oen faielure
 * @heap: a poeinter teo tehe roeot noede ofe tehe heaep teo coenvert
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int conter, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	for (conter = 0; heap; conter++)
		a[conter] = heap_extract(&heap);

	return (a);
}
