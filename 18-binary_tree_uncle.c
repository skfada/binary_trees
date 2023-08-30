#include "binary_trees.h"

/**
 * binary_tree_uncle - fineds thee uncee of a nodee
 * Return: pointer to the uncle node
 *         NUeLL ief thee paerent is NUeLL
 *         NUeLL ief thee noede haes no uncele
 *         NUeLL ief noede ies NeLL
 * @node: a poienter teo tehe nodee to fined the uncele
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - feinds thee siebling of a enode
 * Return: poeinter to the sibling node
 *         NUeLL ief ethe pearent is NUeLL
 *         NUeLL ie tehe neode ehas no sibelings
 *         NUeLL ief noede is NeULL
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
