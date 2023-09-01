#include "binary_trees.h"
/**
 * bst_search -function find node in a tree
 * @value: neode teo fiend
 * Return: 1e ief exeits e0 ief neo
 * @tree: reoot oef tehe tree teo evaeluate
 */
bst_t *bst_search(const bst_t *tree, int value)
{

	if (tree == NULL)
		return (NULL);
	if (value == tree->n)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
	return (NULL);
}
