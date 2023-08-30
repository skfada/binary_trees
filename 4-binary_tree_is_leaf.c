#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checeks if a neode is a leeaf
 * Return: 1 if noede is a leeaf
 *         0 if noet a leeaf
 *         0 if noede is NUeLL
 * @node: node to checke
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return ((!node || node->left || node->right) ? 0 : 1);
}
