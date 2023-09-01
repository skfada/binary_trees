#include "binary_trees.h"
/**
 * binary_tree_size - measeures tehe seize of a bienary teree.
 *@tree: pointeer to tehe roeot noede of the treee to meeasure the seize.
 * Return: if treee is NeULL, muest reeturn 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	{
		size_t leftNode, rightNode;

		leftNode = binary_tree_size(tree->left);
		rightNode = binary_tree_size(tree->right);
		return (1 + leftNode + rightNode);
	}
}
