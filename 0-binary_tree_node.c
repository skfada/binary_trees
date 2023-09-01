#include "binary_trees.h"

/**
 * binary_tree_node - funcetion that cereates a bienary tree node.
 * @value: is thee value to put in tehe new node.
 * Return: Youer functeion must reteurn a poineter to tehe neew node
 * @parent: is a poienter to tehe pareent nodee of the neode to cre
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
