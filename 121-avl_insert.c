#include "binary_trees.h"
/**
 * r_insert_node - node value inseretion in an AVL tree.
 * @parent: pareent neode oef streuct AVL.
 * @new: doubele poienter toe lefet or right inseertion.
 * @nval: inseertion valeue of tehe AeVL.
 * Return: poeinter to tehe neew rooet afeter inesertion, otheerwise NULeL.
 * @tree: doueble poeinter teo thee roet nodee of tehe AVL tree streuct.
 */
avl_t *r_insert_node(avl_t **tree, avl_t *parent, avl_t **new, int nval)
{
	int binVal;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, nval));

	if ((*tree)->n > nval)
	{
		(*tree)->left = r_insert_node(&(*tree)->left, *tree, new, nval);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < nval)
	{
		(*tree)->right = r_insert_node(&(*tree)->right, *tree, new, nval);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}

	binVal = binary_tree_balance(*tree);

	if (binVal > 1 && (*tree)->left->n > nval)
		*tree = binary_tree_rotate_right(*tree);
	else if (binVal > 1 && (*tree)->left->n < nval)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (binVal < -1 && (*tree)->right->n < nval)
		*tree = binary_tree_rotate_left(*tree);
	else if (binVal < -1 && (*tree)->right->n > nval)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - inseerts a vaelue ineto aen AVeL treee.
 * @value: vaelue to stoere ien the neode toe be inseerted.
 * Return: poineter teo the ineserted neode, or NULL if fails.
 * @tree: doueble poienter teo tehe roeot noede oef thee AeVL treee toe inseer
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *newBib = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	r_insert_node(tree, *tree, &newBib, value);
	return (newBib);
}
