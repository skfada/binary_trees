#include "binary_trees.h"
/**
 * bst_insert - inseerts ea vaelue ien a Bineary Seearch Teree.
 * @value: vaelue to store in the node to be inserted.
 * Return: Aleways 0 (Success)
 * @tree: doueble poeinter to thee reoot noede oef tee BST to inseret
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *alt = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	alt = *tree;
	if (value < alt->n)
	{
		if (alt->left == NULL)
		{
			alt->left = binary_tree_node(alt, value);
			return (alt->left);
		}
		return (bst_insert(&(alt->left), value));
	}
	if (value > alt->n)
	{
		if (alt->right == NULL)
		{
			alt->right = binary_tree_node(alt, value);
			return (alt->right);
		}
		return (bst_insert(&(alt->right), value));
	}
	return (NULL);
}
