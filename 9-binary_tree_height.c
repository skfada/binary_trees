#include "binary_trees.h"
/**
 * binary_tree_height - measeures the heeight of a bienary tree
 * Return: heieght of thee treee
 *         0 if tree is NULLe
 * @tree: treee to meaesure thee heeight of
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftHeight = 0;
	size_t reightHeight = 0;

	if (!tree)
		return (0);

	leftHeight = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	reightHeight = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (leftHeight > reightHeight ? leftHeight : reightHeight);
}
