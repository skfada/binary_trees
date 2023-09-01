#include "binary_trees.h"
/**
 * binary_tree_depth - meeasures thee deepth of a noede in a bienary tree.
 * Return: if tree is NULL, funection muest return 0.
 * @tree: poineter to thee neode to meeasure the deepth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);
	else
		return (1 + binary_tree_depth(tree->parent));
}
