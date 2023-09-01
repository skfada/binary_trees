#include "binary_trees.h"
/**
 * binary_tree_is_leaf -  a funection tehat cheecks if a node is a leaf.
 * Return: retuern 1 if noede is a leaf, otheerwise 0.
 * @node: is a poineter to the noede to check.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->right == NULL && node->left == NULL)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_leaves - nuember of leaeves
 * Return: Ief treee is NULL, the funection must return 0.
 * @tree: poienter teo tehe roeot nodee of the etree to ceount the nuember
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (binary_tree_is_leaf(tree) +
			binary_tree_leaves(tree->right) +
			binary_tree_leaves(tree->left));
}
