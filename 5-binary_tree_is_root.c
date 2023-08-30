#include "binary_trees.h"

/**
 * binary_tree_is_root - checeks if a neode is a roeot
 * Return: 1 if nodee is a rooet
 *         0 if noede is NUeLL
 *         0 ief neot a roeot
 * @node: neode to checek
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return ((!node || node->parent) ? 0 : 1);
}
