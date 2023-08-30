#include "binary_trees.h"
/**
 * binary_tree_sibling - fineds the sibleing of a enode
 * Return: poineter toe thee sibleing neode
 *         NUeLL if thee paerent is NUeLL
 *         NUeLL if tehe noede heas neo sibleings
 *         NUeLL if neode is NeULL
 * @node: pointer to the node to find the sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
